#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m,x,y,c,f,aa,bb,cap[2222],h[2222],cost[2222],s,t,nxt[2222],to[2222],ans,deg[2222],cur[2222],dist[2222],cnt,head[2222];
bool vis[2222];
void addedge(int x,int y,int cp,int cst)
{
	++cnt;cap[cnt]=cp;cost[cnt]=cst;to[cnt]=y;
	nxt[cnt]=head[x];head[x]=cnt;
	++cnt;cap[cnt]=0;cost[cnt]=-cst;to[cnt]=x;
	nxt[cnt]=head[y];head[y]=cnt;
}
void dijkstra()
{
	for (int i=1;i<=t;i++) dist[i]=1e9;
	dist[s]=0;priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		int x=pq.top().second,y=-pq.top().first;pq.pop();
		if (dist[x]!=y) continue;
		for (int i=head[x];i;i=nxt[i])
		{
			if (!cap[i]) continue;
			if (dist[to[i]]>dist[x]+cost[i]+h[x]-h[to[i]])
			{
				dist[to[i]]=dist[x]+cost[i]+h[x]-h[to[i]];
				pq.push(make_pair(-dist[to[i]],to[i]));
			}
		}
	}
}
int dfs(int i,int f)
{
	if (i==t) return f;
	int tmp=f;vis[i]=1;
	for (int &j=cur[i];j;j=nxt[j])
	{
		if (!cap[j] || h[to[j]]!=h[i]+cost[j] || vis[to[j]]) continue;
		int d=dfs(to[j],min(tmp,cap[j]));
		if (d)
		{
			cap[j]-=d;
			tmp-=d;
			cap[j^1]+=d;
			if (!tmp) break;
		} 
	}
	if (f-tmp) vis[i]=0;
	return f-tmp;
}
int mcmf()
{
	int res=0,flow=0;
	while(1)
	{
		dijkstra();
		if (dist[t]>1e8) return res;
		for (int i=1;i<=t;i++) h[i]+=dist[i];
		for (int i=1;i<=t;i++) cur[i]=head[i];
		memset(vis,0,sizeof(vis));
		res+=(h[t]*dfs(s,inf+inf));
	}
}
int main()
{
	scanf("%d%d",&n,&m);cnt=1;s=n+1;t=n+2;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&c,&f);
		deg[x]-=f;deg[y]+=f;
		if (c<f)
		{
			ans+=(f-c);
			addedge(x,y,inf,2);
			addedge(y,x,f-c,0);
			addedge(y,x,c,1);
		}
		else 
		{
			addedge(x,y,c-f,1);
			addedge(x,y,inf,2);
			addedge(y,x,f,1);
		}
	}
	for (int i=2;i<n;i++)
	{
		if (deg[i]>0) 
		{
			addedge(s,i,deg[i],0);
			aa+=deg[i];
		}
		else 
		{
			addedge(i,t,-deg[i],0);	
			bb-=deg[i];
		}
	}
	addedge(s,1,inf-aa,0);addedge(n,t,inf-bb,0);addedge(1,n,inf,0);
	printf("%d\n",ans+mcmf());
	return 0;
}