#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
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
char s[200005];
bool vis[105];
int dp[400005];
int dx(int n)
{
	int ans=0;
	while(n>0)
	{
		ans=ans*10+n%10;
		n/=10;
	}
	return ans;
}
int main()
{
	dp[0]=1;
	for(int i=1;i<=40000;i++)
	{
		if(dx(i)!=i)continue;
		for(int j=i;j<=40000;j++)
		{
			dp[j]=(dp[j]+dp[j-i])%mod;
		}
	}
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		printf("%d\n",dp[n]);
	}
	return 0;
}