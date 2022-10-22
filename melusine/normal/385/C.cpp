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
char s[5005];
int x[1000005];
int pri[5000005],cnt;
bool vis[10000005];
int sl[10000005];
long long qz[10000005];
int main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)x[i]=read(),sl[x[i]]++;
	for(int i=2;i<=10000000;i++)
	{
		if(!vis[i])pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=10000000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=10000000/pri[i];j>=1;j--)sl[j]+=sl[j*pri[i]];
	}
	for(int i=2;i<=10000000;i++)
	{
		if(!vis[i])qz[i]=qz[i-1]+sl[i];
		else qz[i]=qz[i-1];
	}
	int m,x,y;
	m=read();
	for(int j=1;j<=m;j++)
	{
		x=read();
		y=read();
		if(x>10000000)
		{
			printf("0\n");
			continue;
		}
		if(y>10000000)y=10000000;
		printf("%lld\n",qz[y]-qz[x-1]);
	}
	return 0;
}