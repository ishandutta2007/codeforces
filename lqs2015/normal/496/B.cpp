#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> mp;
int n,i;
string s,mn;
string add1(string s)
{
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='9') s[i]='0';
		else s[i]++;
	}
	return s;
}
string add2(string s)
{
	char c=s[0];
	for (i=0;i<s.size()-1;i++)
	{
		s[i]=s[i+1];
	}
	s[i]=c;
	return s;
}
bool pre(string a,string b)
{
	if (a.size()!=b.size()) return a.size()>b.size();
	for (int i=0;i<a.size();i++)
	{
		if (a[i]!=b[i]) return a[i]>b[i];
	} 
	return false;
}
void go(string s)
{
	if (mp.find(s)!=mp.end()) return;
	mp[s]++;
	go(add1(s));
	go(add2(s));
}
int main()
{
	for (int i=1;i<=1000;i++)
	{
		mn+='9';
	}
	cin>>n;
	cin>>s;
	go(s);
	for (map<string,int>::iterator x=mp.begin();x!=mp.end();x++)
	{
		string pp=(*x).first;
		if (pre(mn,pp)) mn=pp;
	}
	cout<<mn<<endl;
	return 0;
}