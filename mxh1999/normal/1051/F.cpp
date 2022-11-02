#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=200010;
int fa[maxn],dep[maxn];
ll sum[maxn];
int p[maxn][20];
int n,m,Q;
struct Edge
{
	int v,next;
	ll z;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y,ll z)
{
	tot++;
	e[tot].v=y;
	e[tot].z=z;
	e[tot].next=g[x];
	g[x]=tot;
}
bool vis[maxn];
bool is[maxn];
int que[maxn],cnt;
ll dis[110][maxn];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > dui;
int lca(int x,int y)
{
	if (dep[x]<dep[y])	swap(x,y);
	int m=dep[x]-dep[y];
	for (int i=0;i<20;i++)
		if (m&(1<<i))	x=p[x][i];
	if (x==y)	return x;
	for (int i=19;i>=0;i--)
		if (p[x][i]!=p[y][i])	x=p[x][i],y=p[y][i];
	return p[x][0];
}
void dfs(int t)
{
	p[t][0]=fa[t];
	vis[t]=true;
	dep[t]=dep[fa[t]]+1;
	for (int i=1;p[p[t][i-1]][i-1];i++)
		p[t][i]=p[p[t][i-1]][i-1];
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])
	{
		if (vis[e[i].v])	is[t]=is[e[i].v]=true;	else
		{
			fa[e[i].v]=t;
			sum[e[i].v]=sum[t]+e[i].z;
			dfs(e[i].v);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
	if (is[i])	que[++cnt]=i;
	while (cnt>100);
	for (int i=1;i<=cnt;i++)
	{
		for (int j=1;j<=n;j++)	dis[i][j]=-1;
		dis[i][que[i]]=0;
		while (!dui.empty())	dui.pop();
		dui.push(make_pair(0,que[i]));
		while (!dui.empty())
		{
			pair<ll,int> u=dui.top();
			dui.pop();
			if (dis[i][u.second]!=u.first)	continue;
			for (int j=g[u.second];j;j=e[j].next)
			if (dis[i][e[j].v]==-1 || dis[i][e[j].v]>u.first+e[j].z)
			{
				dis[i][e[j].v]=u.first+e[j].z;
				dui.push(make_pair(dis[i][e[j].v],e[j].v));
			}
		}
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int z=lca(x,y);
		ll ans=sum[x]+sum[y]-2*sum[z];
		for (int j=1;j<=cnt;j++)
			if (dis[j][x]+dis[j][y]<ans)	ans=dis[j][x]+dis[j][y];
		printf("%lld\n",ans);
	}
	return 0;
}