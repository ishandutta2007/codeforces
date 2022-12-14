#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> x;
string s;
vector<string> a,b;
bool ga,gb;
vector<string> split(string &s)
{
	vector<string> v;
	string str;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]==',' || s[i]==';')
		{
			v.push_back(str);
			str="";
		}
		else str+=s[i];
	}
	v.push_back(str);
	return v; 
}
bool isnum(string s)
{
	if (s.size()==0) return 0;
	if (s=="0") return 1;
	if (s[0]=='0') return 0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]<48 || s[i]>57) return 0;
	}
	return 1;
}
int main()
{
	cin>>s;
	x=split(s);
	for (int i=0;i<x.size();i++)
	{
		if (isnum(x[i])) 
		{
			ga=1;
			a.push_back(x[i]); 
		}
		else
		{
			gb=1;
			b.push_back(x[i]); 
		}
	}
	if (ga)
	{
		cout<<"\"";
		for (int i=0;i<a.size();i++)
		{
			cout<<a[i];
			if (i!=a.size()-1) cout<<",";
		}
		cout<<"\""<<endl;
	}
	else cout<<"-"<<endl;
	if (gb)
	{
		cout<<"\"";
		for (int i=0;i<b.size();i++)
		{
			cout<<b[i];
			if (i!=b.size()-1) cout<<",";
		}
		cout<<"\""<<endl;
	}
	else cout<<"-"<<endl;
}