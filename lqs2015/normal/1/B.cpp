#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int i;
void two_one(string s)
{
	string s1,s2;
	for (i=0;s[i]!='C';i++);
	s1=s.substr(1,i-1);
	s2=s.substr(i+1); 
	int r=0;
	for (int i=0;i<s2.size();i++)
	{
		r=r*10+(s2[i]-'0');
	}
	string ss="";
	r--;
	for (;r>=0;r=(r/26-1))
	{
		ss=(char)(r%26+'A')+ss;
	}
	cout<<ss<<s1<<endl;
}
void one_two(string s)
{
	string s1,s2;
	for (i=0;s[i]<'0' || s[i]>'9';i++);
	s1=s.substr(0,i);
	s2=s.substr(i);
	int r1=0,r2=0;
	for  (int i=0;i<s1.size();i++)
	{
		r1=r1*26+(s1[i]-'A'+1);
	}
	for (int i=0;i<s2.size();i++)
	{
		r2=r2*10+(s2[i]-'0');
	}
	cout<<"R"<<r2<<"C"<<r1<<endl;
}
void solve(string s)
{
	int x=s.size();
	if (s[0]=='R')
	{
		if (s[1]>='0' && s[1]<='9')
		{
			int i=1;
			while(s[++i]!='C' && i<x);
			if(s[i]=='C') two_one(s);
			else one_two(s); 
		}
		else one_two(s);
	}
	else
	{
		one_two(s);
	}
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		solve(s);
	}
	return 0;
}