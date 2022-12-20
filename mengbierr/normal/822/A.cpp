#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	int a=read(),b=read(),x,s=1;
	x=min(a,b);
	int ans=1;
	for(int i=1;i<=x;i++)
	s*=i;
	cout<<s;
}