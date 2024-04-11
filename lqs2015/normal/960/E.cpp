#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const long long mod=1e9+7;
long long n,x,y,d[222222],sub[222222],a[222222],sum,cnt,ans,pct;
vector<long long> g[222222];
void dfs(long long i,long long fa,long long f,long long pre)
{
	sub[i]=1;
	a[i]=(pre+f*d[i])%mod;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		dfs(to,i,-f,a[i]);
		sub[i]+=sub[to];
	}
}
void doit(long long i,long long fa,long long cur)
{
	ans=(ans+cur)%mod;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		pct=-cur;
		pct+=sub[to]*d[i];
		pct+=(n-sub[to])*d[to];
		pct%=mod;
		doit(to,i,pct);
	}
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&d[i]);
	}
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0,1,0);
	for (long long i=1;i<=n;i++) sum=(sum+a[i])%mod;
	doit(1,0,sum);
	if (ans<0) ans+=mod;
	printf("%I64d\n",ans);
	return 0;
}