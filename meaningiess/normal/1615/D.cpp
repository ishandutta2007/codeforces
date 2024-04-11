#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define N 200010
using namespace std;
struct edg
{
	int u,v,w;
}e[N];
vector<int> T[N],G[N],U[N],U2[N];
int d[N],fa[N],col[N],vis[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int par(int x){return __builtin_popcount(x)&1;}
void dfs(int x,int f)
{
	for (int i=0;i<T[x].size();i++) if (T[x][i]!=f)
	{
		if (U[x][i]!=-1)d[T[x][i]]=d[x]^U[x][i];
		else d[T[x][i]]=d[x];dfs(T[x][i],x);
	}
}
int S;
void dfs2(int x)
{
	if (!S) return;
	for (int i=0;i<G[x].size();i++)
	{
		int o;
		if (U2[x][i]) o=3-col[x];else o=col[x];
		if (!col[G[x][i]]) col[G[x][i]]=o,dfs2(G[x][i]);
		else if (o!=col[G[x][i]]) S=0;
	}
}
int main()
{
	int TT;cin>>TT;
	while (TT--)
	{
		int n,m,i,a,b,c;scanf("%d%d",&n,&m);S=1;
		for (i=1;i<=n;i++) T[i].clear(),G[i].clear(),U[i].clear(),U2[i].clear(),fa[i]=i,col[i]=vis[i]=0;
		for (i=1;i<n;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			if (e[i].w!=-1)
			{
				int t1=find(e[i].u),t2=find(e[i].v);
				fa[t1]=t2;
			}
			T[e[i].u].pb(e[i].v);T[e[i].v].pb(e[i].u);
			U[e[i].u].pb(e[i].w);U[e[i].v].pb(e[i].w);
		}
		dfs(1,0);
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			int tp=par(d[a]^d[b]);c^=tp;
			a=find(a);b=find(b);
			G[a].pb(b);G[b].pb(a);
			U2[a].pb(c);U2[b].pb(c);
		}
		for (i=1;i<=n;i++) if (!col[i]) col[i]=1,dfs2(i);
		if (!S) {puts("NO");continue;}
		puts("YES");
		for (i=1;i<n;i++)if (e[i].w==-1)
		{
			int t1=find(e[i].u),t2=find(e[i].v);
			e[i].w=(col[t1]!=col[t2]);
		}
		for (i=1;i<n;i++) printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
	}
}