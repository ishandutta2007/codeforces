#include<iostream>
#include<cstdio>
#define mod 998244353
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
int c[100005];
int main()
{
	int t,n,ans=0,pr,sl=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)c[i]=read();
		sl=0;
		for(int i=1;i<=n;i++)if(c[i]==1)sl++;
		if(sl!=1)
		{
			printf("NO\n");
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)if(c[i]==1)
		{
			ans=i;
			break;
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(c[(ans+i+n-2)%n+1]+1<c[(ans+i+n-1)%n+1])
			{
				flag=false;
				break;
			}
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
}