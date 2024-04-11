#include<iostream>
#include<string>
using namespace std;
bool f;
string s,ss,sss;
int n;
int main()
{
	cin>>s;
	n=s.size();
	for (int i=n-1;i>=0;i--)
	{
		if (s[i]!='0') f=1;
		if (f) ss=s[i]+ss;
	}
	n=ss.size();
	for (int i=n-1;i>=0;i--)
	{
		sss=sss+ss[i];
	}
	if (sss==ss)
	{
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
	return 0;
}