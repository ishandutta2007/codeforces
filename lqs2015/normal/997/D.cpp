#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
struct node
{
	long long to,exc[88],rev,hp[88];
	node()
	{
		memset(exc,0,sizeof(exc));
		memset(hp,0,sizeof(hp));
	}
};
vector<node> g[4444];
long long DP[88],DDP[88],sum[88],n,m,K,x,y,ans,cur[88],curr[88],c[88][88],fj[88];
void solve(long long a[],long long b[])
{
	for (long long i=0;i<=K;i++) a[i]=0;
	a[0]=1;
	for (long long i=0;i<=K;i++)
	{
		for (long long j=0;j<=i;j++)
		{
			a[i]=(a[i]+a[i-j]*b[j])%mod;
		}
	}
}
void dfs(long long i,long long k)
{
	for (long long j=0;j<g[i].size();j++)
	{
		if (j==k) continue;
		dfs(g[i][j].to,g[i][j].rev);
	}
	memset(sum,0,sizeof(sum));
	for (long long j=0;j<g[i].size();j++)
	{
		if (j==k) continue;
		for (long long h=0;h<=K-2;h++) sum[h+2]=(sum[h+2]+g[g[i][j].to][g[i][j].rev].hp[h])%mod;
	}
	if (~k) solve(g[i][k].hp,sum);
	for (long long j=0;j<g[i].size();j++)
	{
		if (j==k) continue;
		for (long long h=0;h<=K-2;h++) g[i][j].exc[h+2]=(sum[h+2]-g[g[i][j].to][g[i][j].rev].hp[h])%mod;
	}
}
void dft(long long i,long long k)
{
	if (!~k) 
	{
		for (long long j=0;j<g[i].size();j++)
		{
			for (long long h=0;h<=K;h++) 
			{
				sum[h]=g[i][j].exc[h];
			} 
			solve(g[i][j].hp,sum);
		}
	}
	else
	{
		for (long long j=0;j<g[i].size();j++)
		{
			if (j==k) continue;
			for (long long h=0;h<=K;h++) sum[h]=g[i][j].exc[h];
			for (long long h=0;h<=K-2;h++) sum[h+2]=(sum[h+2]+g[g[i][k].to][g[i][k].rev].hp[h])%mod;
			solve(g[i][j].hp,sum);
		}
	}
	for (long long j=0;j<g[i].size();j++)
	{
		if (j==k) continue;
		dft(g[i][j].to,g[i][j].rev);
	}
}
void solve(long long d[])
{
	dfs(1,-1);
	dft(1,-1);
	for (long long i=1;i<=n;i++)
	{
		memset(sum,0,sizeof(sum));
		for (long long j=0;j<g[i].size();j++)
		{
			long long to=g[i][j].to;
			for (long long h=0;h<=K-2;h++) sum[h+2]=(sum[h+2]+g[to][g[i][j].rev].hp[h])%mod;
		}
		solve(fj,sum);
		for (long long j=0;j<=K;j++) d[j]=(d[j]+fj[j])%mod;
	}
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&K);
	for (long long i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		node nw;nw.to=y;nw.rev=g[y].size();
		g[x].push_back(nw);
		nw.to=x;nw.rev=(long long)g[x].size()-1;
		g[y].push_back(nw);  
	}
	solve(DP);
	for (long long i=1;i<=n;i++) g[i].clear();
	n=m;
	for (long long i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		node nw;nw.to=y;nw.rev=g[y].size();
		g[x].push_back(nw);
		nw.to=x;nw.rev=(long long)g[x].size()-1;
		g[y].push_back(nw);  
	}
	solve(DDP);
	c[0][0]=1;
	for (long long i=1;i<=K;i++)
	{
		c[i][0]=1;
		for (long long j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	for (long long i=0;i<=K;i++)
	{
		ans=(ans+DP[i]*DDP[K-i]%mod*c[K][i])%mod;
	} 
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}