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
char s[100005];
int main()
{
	int t,n,ans=0,pr;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n%2==1)
		{
			printf("0\n");
			continue;
		}
		ans=1;
		for(int i=1;i<=n/2;i++)ans=1LL*ans*i%mod;
		ans=1LL*ans*ans%mod;
		printf("%d\n",ans);
	}
}