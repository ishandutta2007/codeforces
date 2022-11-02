//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 2010
#define maxm 100010
int n,m;
pair<int,int>	E[maxm];
struct Edge
{
	int v,next;
}	e[maxm<<1];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}
int f[maxn];
int fa[maxn];
int mjy;
bool vis[maxn];
int b[maxn][maxn];
int dep[maxn];
int que[maxn],cnt;
int block[maxn];
int find(int t)
{
	if (f[t]==t)	return t;
	return f[t]=find(f[t]);
}
void Union(int x,int y)
{
	x=find(x),y=find(y);
	if (dep[x]<dep[y])	swap(x,y);
	if (x!=y)	f[x]=y,mjy++;
}
void dfs(int t)
{
	vis[t]=true;
	dep[t]=dep[fa[t]]+1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])
	{
		if (vis[e[i].v])
		{
			int q=t;
			while (q && find(q)!=find(e[i].v))
			{
				int ha=q;q=fa[find(q)];
				Union(ha,e[i].v);
			}
		}	else fa[e[i].v]=t,dfs(e[i].v);
	}
}
void dfs1(int t)
{
	dep[t]=dep[fa[t]]+1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])
	{
		fa[e[i].v]=t;
		dfs1(e[i].v);
	}
}
void dfs2(int t)
{
	dep[t]=-1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t] && !vis[e[i].v])
	{
		dep[t]=0;
		fa[e[i].v]=t;
		dfs2(e[i].v);
	}
}
int main()
{
	read(n);read(m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		E[i].first=x,E[i].second=y;
		addedge(x,y);
		addedge(y,x);
	}
	for (int i=1;i<=n;i++)	f[i]=i;
	for (int i=1;i<=n;i++)
	if (!vis[i])	dfs(i),block[++block[0]]=i;
	tot=0;
	memset(g,0,sizeof(g));
	for (int i=1;i<=m;i++)
	{
		int x=E[i].fi,y=E[i].se;
		x=find(x),y=find(y);
		if (x==y || b[x][y])	continue;
		b[x][y]=b[y][x]=true;
		addedge(x,y);
		addedge(y,x);
	}
	for (int _=1;_<=block[0];_++)
	{
		memset(fa,0,sizeof(fa));
		memset(dep,0,sizeof(dep));
		dfs1(block[_]);
		int xmm=0,pos=0;
		for (int i=1;i<=n;i++)
		if (dep[i]>xmm)	xmm=dep[i],pos=i;
		memset(fa,0,sizeof(fa));
		dfs1(pos);
		xmm=0,pos=0;
		for (int i=1;i<=n;i++)
		if (dep[i]>xmm)	xmm=dep[i],pos=i;
		memset(vis,0,sizeof(vis));
		cnt=0;
		while (pos)
		{
			que[++cnt]=pos;
			vis[pos]=true;
			pos=fa[pos];
		}
		memset(fa,0,sizeof(fa));
		for (int i=1;i<=n;i++)	dep[i]=-2;
		for (int i=1;i<=cnt;i++)	dfs2(que[i]);
		for (int i=1;i<=cnt;i++)	dep[que[i]]=-1;
		for (int i=1;i<=n;i++)
		if (dep[i]!=-1 && dep[i]!=-2)	mjy++;
	}
	printf("%d\n",mjy+block[0]-1);
	return 0;
}