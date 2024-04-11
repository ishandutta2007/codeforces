#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define int long long
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
int dp[1000005],hz[1000005];
int cm[1000005],ncm[1000005];
signed main()
{
	cm[0]=1;
	ncm[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		cm[i]=2LL*cm[i-1]%mod;
		ncm[i]=1LL*ncm[i-1]*(mod+1)/2%mod;
	}
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		if(n==2)
		{
			printf("0\n1\n");
			continue;
		}
		dp[1]=dp[2]=0;
		hz[n+1]=0;
		for(int i=n;i>=3;i--)
		{
			if(2*i-2>n)
			{
				dp[i]=1;
				hz[i]=(1LL*hz[i+1]*(mod+1)/2%mod+dp[i])%mod;
				continue;
			}
			dp[i]=(hz[i+1]+mod-1LL*hz[2*i-1]*ncm[i-2]%mod)%mod*1LL*(mod+1)/2%mod;
			hz[i]=(1LL*hz[i+1]*(mod+1)/2%mod+dp[i])%mod;
			//printf("%lld %lld\n",i,dp[i]);
		}
		dp[n+1]=1;
		printf("0\n");
		for(int i=2;i<=n;i++)
		{
			int ans=ncm[i-i/2];
			if(i==n)ans=2LL*ans%mod;
			printf("%lld\n",1LL*ans*dp[i+1]%mod);
		}
	}
	return 0;
}