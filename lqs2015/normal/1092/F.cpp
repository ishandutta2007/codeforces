#include<bits/stdc++.h>
using namespace std;
long long n,beg[222222],en[222222],sum[222222],a[222222],x,y,ct,gd[222222],dep[222222],res,ans;
vector<long long> g[222222];
void dfs(long long i,long long fa)
{
	beg[i]=++ct;
	res+=dep[i]*a[i];
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		dep[to]=dep[i]+1;
		dfs(to,i);
	}
	en[i]=ct;
}
void dft(long long i,long long fa)
{
	ans=max(ans,res);
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		long long g=sum[en[to]]-sum[beg[to]-1];
		res-=g;
		res+=(sum[n]-g);
		dft(to,i);
		res+=g;
		res-=(sum[n]-g);
	}
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0);
	for (long long i=1;i<=n;i++) gd[beg[i]]=a[i];
	for (long long i=1;i<=n;i++) sum[i]=sum[i-1]+gd[i];
	ans=res;
	dft(1,0);
	printf("%I64d\n",ans);
	return 0;
}