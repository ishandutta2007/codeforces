#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const long long mod=1e9+7;
long long n,k,x,prime[11111111],cur,dp[11111][66],inv[111111],ans,p,pro,cnt;
bool f[33333333];
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
int main()
{
	cin>>n>>k;
	x=sqrt(n);
	for (long long i=2;i<=x;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (long long j=1;j<=cnt && i*prime[j]<=x;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	for (long long i=1;i<=10000;i++) inv[i]=binpow(i,mod-2);
	ans=1;
	for (long long i=1;i<=cnt;i++)
	{
		if (n%prime[i]) continue;
		cur=0;
		while(n%prime[i]==0)
		{
			n/=prime[i];
			cur++;
		}
		for (long long j=0;j<=k;j++)
		{
			for (long long h=0;h<=cur;h++)
			dp[j][h]=0;
		}
		dp[0][cur]=1;
		for (long long j=1;j<=k;j++)
		{
			for (long long h=0;h<=cur;h++)
			{
				for (long long p=h;p<=cur;p++)
				{
					dp[j][h]=(dp[j][h]+dp[j-1][p]*inv[p+1])%mod;
				}
			}
		}
		pro=0;p=1;
		for (long long j=0;j<=cur;j++)
		{
			pro=(pro+dp[k][j]*p)%mod;
			p=p*prime[i]%mod;
		}
		ans=ans*pro%mod;
	}
	if (n!=1)
	{
		p=1;
		for (long long i=1;i<=k;i++) p=p*inv[2]%mod;
		pro=((1-p)+p*(n%mod))%mod;
		ans=ans*pro%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return Accepted;
}