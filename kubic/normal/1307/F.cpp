#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define pb push_back
int n,m,c1,c2,q[N],dst[N],col[N],fa1[N],dep[N],fa[N][19];vector<int> e[N];
int findRt(int u) {return u==fa1[u]?u:fa1[u]=findRt(fa1[u]);}
void merge(int u,int v) {u=findRt(fa1[u]);v=findRt(fa1[v]);if(u!=v) fa1[u]=v;} 
void bfs()
{
	for(int i=1;i<=n;++i) dst[i]=-1;
	for(int i=q[0];i<=q[1];++i) dst[q[i]]=0,col[q[i]]=q[i];
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(auto v:e[u]) if(dst[v]==-1)	 dst[v]=dst[u]+1,col[v]=col[u],q[++q[1]]=v;
	}
}
void dfs(int u,int f)
{
	fa[u][0]=f;for(int i=1;i<=18;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
	dep[u]=dep[f]+1;for(auto v:e[u]) if(v!=f) dfs(v,u);
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=18;i>=0;--i) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];if(u==v) return u;
	for(int i=18;i>=0;--i) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];return fa[u][0];
}
int qry(int u,int v,int x)
{
	int t=LCA(u,v); if(x>dep[u]-dep[t]) x=dep[u]+dep[v]-dep[t]*2-x,swap(u,v);
	for(int i=18;i>=0;--i) if(x>>i&1) u=fa[u][i];return u;
}
int main()
{
	scanf("%d %d %d",&n,&m,&c1);q[0]=2;q[1]=1;
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		e[u].pb(n+i);e[n+i].pb(u);e[v].pb(n+i);e[n+i].pb(v);
	}n=n*2-1;for(int i=1,u;i<=c1;++i) scanf("%d",&u),q[++q[1]]=u;
	bfs();dfs(1,0);for(int i=1;i<=n;++i) fa1[i]=dst[i]<=m?col[i]:i;
	for(int i=1;i<=n;++i) for(auto j:e[i])
		if(dst[i]+dst[j]<m*2) merge(i,j);scanf("%d",&c2);
	for(int i=1,u,v,u1,v1;i<=c2;++i)
	{
		scanf("%d %d",&u,&v);
		if(dep[u]+dep[v]-dep[LCA(u,v)]*2<=m*2) puts("YES");
		else
		{
			u1=qry(u,v,m);v1=qry(v,u,m);
			if(findRt(u1)==findRt(v1)) puts("YES");else puts("NO"); 
		}
	}return 0;
}