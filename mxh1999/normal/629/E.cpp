#include<bits/stdc++.h>
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

#define maxn 100010
struct Edge
{
	int v,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}

int fa[maxn],dep[maxn],size[maxn],mjy[maxn];
int p[maxn][20];
double f[maxn],dp[maxn];
int n,m;

void dfs(int t)
{
	dep[t]=dep[fa[t]]+1;
	size[t]=1;
	p[t][0]=fa[t];
	int m=fa[t];
	for (int i=0;p[m][i]!=0;i++)
	{
		p[t][i+1]=p[m][i];
		m=p[m][i];
	}
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])
	{
		fa[e[i].v]=t;
		dfs(e[i].v);
		size[t]+=size[e[i].v];
	}
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])	f[t]=f[t]+(f[e[i].v]+1.0)*size[e[i].v]/size[t];
}
void dfs2(int t)
{
	if (fa[t])	dp[t]=(dp[fa[t]]*(n-size[fa[t]])+f[fa[t]]*size[fa[t]]-size[t]*(f[t]+1))/(n-size[t])+1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])	dfs2(e[i].v);
}
int lca(int x,int y)
{
	if (x==y) return x;
	if (dep[x]<dep[y])	swap(x,y);
	int m=dep[x]-dep[y];
	int k=0;
	while (m)
	{
		if (m&1)
			x=p[x][k];
		m>>=1;
		k++;
	}
	if (x==y) return x;
	k=0;
	while (x!=y)
	{
		if (p[x][k]!=p[y][k] || p[x][k]==p[y][k] && k==0)
		{
			x=p[x][k];
			y=p[y][k];
			k++;
		} else k--;
	}
	return x;
}
double doit(int x,int y)
{
	if (dep[x]>dep[y])	swap(x,y);
	int lc=lca(x,y);
	if (lc==x)
	{
		int now=dep[y]-dep[x]-1;
		int haha=y;
		int pre=0;
		while (now)
		{
			if (now&1)	haha=p[haha][pre];
			pre++,now>>=1;
		}
		return f[y]+dp[haha]+dep[y]-dep[x];
	}
	return f[x]+f[y]+dep[y]-dep[lc]+dep[x]-dep[lc]+1;
}
int main()
{
	read(n),read(m);
	for (int i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1);
	dfs2(1);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		double mjy=doit(x,y);
		printf("%.8lf\n",mjy);
	}
	return 0;
}