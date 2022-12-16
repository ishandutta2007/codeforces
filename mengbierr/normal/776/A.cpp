#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
string s[3];
int n;
int main()
{
	cin>>s[1]>>s[2];
	n=read();
	cout<<s[1]<<" "<<s[2]<<endl;
	for(int i=1;i<=n;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(s[1]==t1) s[1]=t2;
		else s[2]=t2;
		cout<<s[1]<<" "<<s[2]<<endl;
	}
}