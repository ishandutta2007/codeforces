#include<bits/stdc++.h>
using namespace std;

const int maxn=300010;
struct Store
{
	int x,y,cost;
}	st[maxn];
struct Edge
{
	int v,next,id;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y,int id)
{
	tot++;
	e[tot].v=y;
	e[tot].id=id;
	e[tot].next=g[x];
	g[x]=tot;
}
int n,stamp,dfn[maxn],low[maxn];
int m;

void tarjan(int index,int fa)
{
    int tmp;
    dfn[index]=low[index]=++stamp;
	for (int i=g[index];i;i=e[i].next)
	{
		tmp=e[i].v;
		if (!dfn[tmp])
		{
			tarjan(tmp,index);
			low[index]=min(low[index],low[tmp]);
			if(low[tmp]>dfn[index])	st[e[i].id].cost=1;
		}
		else if(dfn[tmp]<dfn[index] && tmp!=fa)
		{
			low[index]=min(low[index],dfn[tmp]);
		}
	}
}
int dep[maxn];
void dfs(int t)
{
	for (int i=g[t];i;i=e[i].next)
	if (dep[e[i].v]==0)
	{
		dep[e[i].v]=dep[t]+st[e[i].id].cost;
		dfs(e[i].v);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y,i);
		addedge(y,x,i);
		st[i].x=x;
		st[i].y=y;
	}
	tarjan(1,0);
	dep[1]=1;
	dfs(1);
	int pos=1;
	for (int i=1;i<=n;i++)
		if (dep[i]>dep[pos])	pos=i;
	memset(dep,0,sizeof(dep));
	dep[pos]=1;
	dfs(pos);
	pos=1;
	for (int i=1;i<=n;i++)
		if (dep[i]>dep[pos])	pos=i;
	printf("%d\n",dep[pos]-1);
}