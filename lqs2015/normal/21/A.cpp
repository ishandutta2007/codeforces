#include<iostream>
#include<string>
using namespace std;
string s;
bool good(char c)
{
	return ((c>='A' && c<='Z') || (c>='a' && c<='z') || isdigit(c) || c=='_'); 
}
bool cor1(int begin,int end)
{
	if (begin-end+1>16 || end-begin+1==0) return 0;
	for (int i=begin;i<=end;i++)
	{
		if (!good(s[i])) return 0;
	}
	return 1;
}
bool cor2(int begin,int end)
{
	if (end-begin+1>32 || end-begin+1==0) return 0;
	int g=0;
	for (int i=begin;i<=end;i++)
	{
		if (s[i]=='.') 
		{
			if (g>16 || g==0) return 0;
			g=0;
		}
		else if (!good(s[i])) return 0;
		else g++;
	}
	return g>=1 && g<=16;
}
bool correct(string s)
{
	int a=s.find('@');
	int b=s.find_last_of('/');
	if (a==string::npos) return 0;
	if (b==string::npos) return (cor1(0,a-1) && cor2(a+1,s.size()-1));
	else return (cor1(0,a-1) && cor2(a+1,b-1) && cor1(b+1,s.size()-1));
}
int main()
{
	cin>>s;
	if (correct(s)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}