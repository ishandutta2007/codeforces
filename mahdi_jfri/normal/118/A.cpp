#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

string lowercase(string a)
{
	for(int i=0;i<a.size();i++)
	{if(a[i]>64 && a[i]<97)
	a[i]=a[i]-'A'+'a';}
	return a;
}

int main()
{
	string a;
	cin>>a;
	char b[10]={'a','e','o','u','i','y'};
	a=lowercase(a);
	for(int i=0;i<7;i++)
	{
		for(int c=a.find(b[i]);c!=string::npos;c=a.find(b[i]))
		{	
			a.erase(c,1);
		}
	}
	for(int i=0;i<a.size();i++)
	cout<<"."<<a[i];
}