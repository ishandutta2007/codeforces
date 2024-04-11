#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
long long n,m,u[222222],v[222222],w[222222],pa[222222],dep[222222],ct,x,y,beg[222222],en[222222];
long long an[222222][22],mx[222222][22],cost;
priority_queue<pair<long long,long long> > pq;
vector<pair<long long,long long> > g[222222];
vector<long long> gg[222222];
vector<long long> ans;
long long root(long long x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
bool Union(long long x,long long y)
{
	long long rx=root(x),ry=root(y);
	if (rx==ry) return 0;
	pa[rx]=ry;
	return 1;
}
void dfs(long long i,long long fa,long long len,long long deep)
{
	dep[i]=deep;
	an[i][0]=fa;
	mx[i][0]=len;
	for (long long j=1;j<=20;j++)
	{
		an[i][j]=an[an[i][j-1]][j-1];
		mx[i][j]=max(mx[i][j-1],mx[an[i][j-1]][j-1]);
	}
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dfs(to,i,val,deep+1);
	}
}
long long lca(long long x,long long y)
{
	if (dep[y]<dep[x]) swap(x,y);
	long long wq=1<<20,res=0;
	for (long long i=1;i<=20;i++)
	{
		wq/=2;
		if (dep[y]-dep[x]>=wq) 
		{
			res=max(res,mx[y][20-i]);
			y=an[y][20-i];
		}
	}
	for (long long i=19;i>=0;i--)
	{
		if (an[x][i]!=an[y][i])
		{
			res=max(res,max(mx[x][i],mx[y][i]));
			x=an[x][i];
			y=an[y][i];
		}
	}
	if (x!=y) res=max(res,max(mx[x][0],mx[y][0]));
	return res;
}
void dft(long long i,long long fa)
{
	if (fa && gg[i].size()==1)
	{
		beg[i]=en[i]=++ct;
		return;
	}
	beg[i]=1e9;
	for (long long j=0;j<gg[i].size();j++)
	{
		long long to=gg[i][j];
		if (to==fa) continue;
		dft(to,i);
		beg[i]=min(beg[i],beg[to]);
		en[i]=max(en[i],en[to]);
	}
}
int main()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
	}
	for (long long i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		gg[x].push_back(y);
		gg[y].push_back(x);  
	}
	dft(1,0);m=n;
	n=ct+1;
	for (long long i=1;i<=m;i++)
	{
		u[i]=beg[i];v[i]=en[i]+1;
		pq.push(make_pair(-w[i],i)); 
	}
	for (long long i=1;i<=n;i++) pa[i]=i;
	while(!pq.empty())
	{
		long long x=pq.top().second;
		pq.pop();
		if (Union(u[x],v[x]))
		{
			g[u[x]].push_back(make_pair(v[x],w[x]));
			g[v[x]].push_back(make_pair(u[x],w[x])); 
			cost+=w[x];
		}
	}
	dfs(1,0,0,1);
	for (long long i=1;i<=m;i++)
	{
		if (lca(u[i],v[i])==w[i]) ans.push_back(i);
	}
	printf("%lld %lld\n",cost,ans.size());
	for (long long i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}