#include<iostream>
#include<cstdio>
#include<cstring>
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
int a[2005];
int main()
{
	int t,n,z,maxn=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		z=read();
		for(int i=1;i<=n;i++)a[i]=read();
		maxn=0;
		for(int i=1;i<=n;i++)maxn=max(maxn,(a[i]|z));
		printf("%d\n",maxn);
	}
	return 0;
}