#include<iostream>
using namespace std;
int n;string s;
main()
{
	cin>>n>>s;
	int a=(n-11)/2,b=(n-11)/2;
	string t="";
	for(int i=0;i<n;i++)
	{
		if(s[i]=='8')
		{
			if(b>0)b--;
			else t+='8';
		}
		else t+=s[i];
	}
	for(int i=0;i<=a;i++)
	{
		if(t[i]=='8')
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}