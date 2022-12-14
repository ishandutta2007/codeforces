#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,d,x,dp[3333][3333],c[3333][3333],pre[3333],suf[3333],sub[3333],f[3333],ff[3333],ans[3333],res;
vector<long long> g[3333];
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
void Init()
{
	pre[0]=1;
	for (long long i=1;i<=n && i<=d;i++) pre[i]=pre[i-1]*(d+1-i)%mod;
	suf[0]=1;
	for (long long i=1;i<=n && i<=d;i++) suf[i]=suf[i-1]*binpow(i,mod-2)%mod;
	c[0][0]=1;
	for (long long i=1;i<=3000;i++)
	{
		c[i][0]=1;
		for (long long j=1;j<=3000;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
}
long long C(long long n)
{
	return pre[n]*suf[n]%mod;
}
void dfs(long long i)
{
	sub[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		dfs(to);
		sub[i]+=sub[to];
	}
	for (long long j=1;j<=n;j++)
	{
		dp[i][j]=1;
		for (long long k=0;k<g[i].size();k++)
		{
			long long to=g[i][k];
			dp[i][j]=dp[i][j]*dp[to][j]%mod;
		}
		dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
	}
}
int main()
{
	scanf("%lld%lld",&n,&d);
	Init();
	for (long long i=2;i<=n;i++)
	{
		scanf("%lld",&x);
		g[x].push_back(i); 
	}
	dfs(1);
	for (long long i=1;i<=n;i++) 
	{
		ans[i]=dp[1][i];
		for (long long j=1;j<i;j++)
		{
			ans[i]=(ans[i]-ans[j]*c[i][j])%mod;
		}
	}
	for (long long i=1;i<=n && i<=d;i++) res=(res+ans[i]*C(i))%mod;
	printf("%lld\n",(res+mod)%mod);
	return 0;
}