#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=300000;
const int inf=10000000000000000;
struct edge
{
	int to,c;
};
int n,m;
vector<edge> g[maxn+5];
int vi[maxn+5],d[maxn+5],sz[maxn+5],par[maxn+5],ans=-inf;
void add(int u,int v,int w)
{
	g[u].push_back((edge){v,w});
	return;
}
void List(int u,int fa)
{
	vi[u]=0;
	if(u==n) vi[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		if(v==fa) continue;
		List(v,u);
		if(vi[v]) vi[u]=1;
	}
	return;
}
void Dfs(int u,int fa)
{
	sz[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		if(v==fa) continue;
		if(vi[v]) continue;
		Dfs(v,u);
		sz[u]+=sz[v];
	}
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		if(v==fa) continue;
		if(vi[v])  Dfs(v,u);
	}
	return;
}
void dfs(int u,int fa,int cost,int maxlen)
{
	par[u]=fa;
	if(!vi[u]) return;
	d[u]=d[fa]+cost;
	int maxw=-inf*2;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		int w=g[u][i].c;
		if(vi[v]) continue;
		maxw=max(maxw,w);
	}
	if(maxw>-inf)
	{
		if(maxlen>-inf) ans=max(ans,maxlen-d[u]+maxw);
		else if(fa!=0) ans=max(ans,maxw-d[u]+d[fa]);
	}
	else
	{
		if(maxlen>-inf) ans=max(ans,maxlen-d[u]);
		else if(par[u]!=0&&par[par[u]]!=0) ans=max(ans,d[par[par[u]]]-d[u]);
	}
	maxlen=max(maxlen,d[u]+maxw);
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		int w=g[u][i].c;
		if(v==fa) continue;
		if(!vi[v]) continue;
		dfs(v,u,w,maxlen);
	}
	return;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	int u,v,w;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	int flag=0;
	List(1,0);
	Dfs(1,0);
	for(int i=1;i<=n;i++) if(vi[i]&&sz[i]>=3) flag=1;
	d[0]=0;
	dfs(1,0,0,-inf*2);
	for(int tot=1;tot<=m;tot++)
	{
		scanf("%lld",&w);
		if(flag) printf("%lld\n",d[n]);
		else 
		{
			w+=ans;
			if(w<0) printf("%lld\n",d[n]+w);
			else printf("%lld\n",d[n]);
		}
	}
	return 0;
}