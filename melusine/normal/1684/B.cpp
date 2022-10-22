#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	} 
	return n*f;
}
char s[500005];
signed main()
{
	int t,a,b,c;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		c=read();
		printf("%lld %lld %lld\n",a+b+c,b+c,c);
	}
	return 0;
}