#include<iostream>
#include<cstdio>
#include<map>
#define mod 998244353
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
int a[200005];
int qzh[200005];
char xz[200005]; 
signed main()
{
	int t,n,q,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		sth=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		sth=0;
		for(int i=n;i>=1;i--)
		{
			//printf("orz%d\n",sth);
			if(a[i]>sth&&sth<q)
			{
				sth++;
				xz[i]='1';
			}
			else if(a[i]<=sth)xz[i]='1';
			else xz[i]='0';
		}
		for(int i=1;i<=n;i++)printf("%c",xz[i]);
		printf("\n");
	}
	return 0;
}