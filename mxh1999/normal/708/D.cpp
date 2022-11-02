#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int maxn=110;
const int maxm=610;
int n,m,ans;
int S,T;
struct Edge
{
	int v,flow,cost,next;
}	e[maxm<<1];
int g[maxn],tot=1;
void addedge(int x,int y,int flow,int cost)
{
	tot++;e[tot].v=y;e[tot].flow=flow;e[tot].cost=cost;e[tot].next=g[x];g[x]=tot;
	tot++;e[tot].v=x;e[tot].flow=0;e[tot].cost=-cost;e[tot].next=g[y];g[y]=tot;
}

int d[maxn];
int dis[maxn];
bool vis[maxn];
int pre[maxn],pre2[maxn];
int que[65536];
bool spfa()
{
	for (int i=1;i<=n;i++)
	{
		dis[i]=INF;
		vis[i]=false;
		pre[i]=0;
		pre2[i]=0;
	}
	dis[S]=0;
	int h=1,t=1;
	que[1]=S;
	vis[S]=true;
	while (h<=t)
	{
		int u=que[h&65535];
		h++;
		vis[u]=false;
		for (int i=g[u];i;i=e[i].next)
		if (e[i].flow && dis[e[i].v]>dis[u]+e[i].cost)
		{
			dis[e[i].v]=dis[u]+e[i].cost;
			pre[e[i].v]=u;
			pre2[e[i].v]=i;
			if (!vis[e[i].v])
			{
				t++;
				que[t&65535]=e[i].v;
			}
		}
	}
	if (dis[T]==INF)	return false;
	int flow=INF;
	int now=T;
	while (now!=S)
	{
		flow=min(flow,e[pre2[now]].flow);
		now=pre[now];
	}
	now=T;
	ans+=dis[T]*flow;
	while (now!=S)
	{
		e[pre2[now]].flow-=flow;
		e[pre2[now]^1].flow+=flow;
		now=pre[now];
	}
	return true;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y,c,f;
		scanf("%d%d%d%d",&x,&y,&c,&f);
		d[x]+=f;
		d[y]-=f;
		if (f>=c)
		{
			if (f>c)
			{
				addedge(y,x,f-c,0);
				ans+=f-c;
			}
			addedge(y,x,c,1);
			addedge(x,y,INF,2);
		}	else
		{
			addedge(x,y,c-f,1);
			addedge(y,x,f,1);
			addedge(x,y,INF,2);
		}
	}
	addedge(n,1,INF,0);
	S=n+1,T=n+2;
	for (int i=1;i<=n;i++)
	{
		if (d[i]<0)	addedge(S,i,-d[i],0);
		if (d[i]>0)	addedge(i,T,d[i],0);
	}
	n=T;
	while (spfa());
	printf("%d\n",ans);
}