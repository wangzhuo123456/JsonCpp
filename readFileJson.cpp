#include <string>
#include "jsoncpp1.9.0/json.h"
#include <iostream>
#include <fstream>
using namespace std;

 
//从文件中读取JSON
void readFileJson()
{
	Json::Reader reader;
	Json::Value root;
 
	//从文件中读取，保证当前文件有test.json文件
	ifstream in("test.json", ios::binary);
	//in.open("test.json", ios::binary);
 
	if( !in.is_open() )  
	{ 
	cout << "Error opening file\n"; 
	return; 
	}
 
	/*
	//test.json内容如下：
	{
		"name":"Tsybius",
		"age":23,
		"sex_is_male":true,
		"partner":
		{
			"partner_name":"Galatea",
			"partner_age":21,
			"partner_sex_is_male":false
		},
		"achievement":["ach1","ach2","ach3"]
	}
	*/
 
	if(reader.parse(in,root))
	{
	//读取根节点信息
	string name = root["name"].asString();
	int age = root["age"].asInt();
	bool sex_is_male = root["sex_is_male"].asBool();
 
	cout << "My name is " << name << endl;
	cout << "I'm " << age << " years old" << endl;
	cout << "I'm a " << (sex_is_male ? "man" : "woman") << endl;
 
	//读取子节点信息
	string partner_name = root["partner"]["partner_name"].asString();
	int partner_age = root["partner"]["partner_age"].asInt();
	bool partner_sex_is_male = root["partner"]["partner_sex_is_male"].asBool();
 
	cout << "My partner's name is " << partner_name << endl;
	cout << (partner_sex_is_male ? "he" : "she") << " is "
		<< partner_age << " years old" << endl;
 
	//读取数组信息
	cout << "Here's my achievements:" << endl;
	for(unsigned int i = 0; i < root["achievement"].size(); i++)
	{
		string ach = root["achievement"][i].asString();
		cout << ach << '\t';
	}
	cout << endl;
 
	cout << "Reading Complete!" << endl;
	}
	else
	{
	cout << "parse error\n" << endl;	
	}
 
	in.close();
}