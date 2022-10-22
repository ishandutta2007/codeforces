#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int n,m,cnt,all,fa[N],vs[N],w[N];ll ans=1e18;
map<int,bool> e2[N];queue<int> q;set<int> z;
struct Edge {int u,v,w;}e1[N];vector<int> e3[N];
bool cmp(Edge x,Edge y) {return x.w<y.w;}
void clear() {for(int i=1;i<=n+1;++i) fa[i]=i;}
int findRt(int x) {return x==fa[x]?x:fa[x]=findRt(fa[x]);}
bool merge(int x,int y)
{
	x=findRt(x);y=findRt(y);if(x==y) return 0;
	fa[x]=y;return 1;
}
void bfs(int S)
{
    z.erase(S);q.push(S);vs[S]=S;
    while(!q.empty())
	{
        int u=q.front();q.pop();
        for(set<int>::iterator it=z.begin();it!=z.end();)
		{int v=*it++;if(!e2[u][v]) z.erase(v),q.push(v),vs[v]=S;}
    }
}
void dfs(int u,int lim,int S)
{
	if(u==lim || vs[u]==S) return;vs[u]=S;
	for(int i=0;i<e3[u].size();++i) dfs(e3[u][i],lim,S);
}
ll slv(int u,int v,int w)
{
	ll res=0;clear();
	for(int i=1;i<=m;++i)
	{
		if(u && w<e1[i].w) {if(merge(vs[u],vs[v])) res+=w;u=v=w=0;}
		if(merge(vs[e1[i].u],vs[e1[i].v])) res+=e1[i].w; 
	}if(u) {if(merge(vs[u],vs[v])) res+=w;}return res;
}
int main()
{
	scanf("%d %d",&n,&m);for(int i=1;i<=n;++i) z.insert(i);
	for(int i=1,u,v,w;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);all^=w;
		e1[i]=(Edge) {u,v,w};e2[u][v]=e2[v][u]=1;
	}sort(e1+1,e1+m+1,cmp);
	for(int i=1;i<=n;++i) if(!vs[i]) bfs(i),++cnt;
	if(n-cnt==1ll*n*(n-1)/2-m)
	{
		for(int u=1;u<=n;++u) for(int v=1;v<=n;++v)
			if(!e2[u][v]) e3[u].pb(v);
		for(int u=1;u<=n;++u) for(int v=1;v<u;++v) if(!e2[u][v])
			dfs(u,v,n+1),ans=min(ans,slv(u,v,all)),dfs(u,v,vs[v]);
	}else ans=slv(0,0,0);printf("%lld\n",ans);return 0;
}