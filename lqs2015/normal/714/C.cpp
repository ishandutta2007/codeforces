#include<iostream>
#include<string>
#include<map>
#include<cstdio>
using namespace std;
map<string,int> mp;
char c;
string s;
string getnum(string &s)
{
	string res="";
	bool f=0;
	for (int i=0;i<s.size();i++)
	{
		int c=s[i]-'0';
		if (c%2)
		{
			res.push_back('1');
			f=1; 
		}
		else if (f!=0) res.push_back('0'); 
	}
	return res;
}
string getans(string &s)
{
	string res="";
	bool f=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]!='0' || f)
		{
			f=1;
			res.push_back(s[i]); 
		}
	}
	return res;
}
int n;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>c;
		getchar();
		cin>>s;
		if (c=='+') mp[getnum(s)]++;
		else if (c=='-') mp[getnum(s)]--;
		else cout<<mp[getans(s)]<<endl;
	}
	return 0;
}