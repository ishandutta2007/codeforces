#include<bits/stdc++.h>
using namespace std;
const int inf=5e8;
int head[111],nxt[11111],to[11111],cap[11111],cost[11111],cnt,x,y,z;
int dist[111],h[111],n,m,s,t,flow,f,prevv[111],preve[111],q,pos;
pair<int,int> que[111111];
long long ans[5555],curans;
double res[111111];
void addedge(int x,int y,int cp,int cst)
{
	++cnt;cost[cnt]=cst;
	cap[cnt]=cp;to[cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
}
void dijkstra()
{
	for (int i=1;i<=t;i++) dist[i]=1e9;
	dist[s]=0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		int x=pq.top().second,y=-pq.top().first;pq.pop();
		for (int i=head[x];i;i=nxt[i])
		{
			if (!cap[i]) continue;
			if (dist[to[i]]>dist[x]+cost[i]+h[x]-h[to[i]])
			{
				dist[to[i]]=dist[x]+cost[i]+h[x]-h[to[i]];
				prevv[to[i]]=x;preve[to[i]]=i;
				pq.push(make_pair(-dist[to[i]],to[i]));
			}
		}
	}
}
void mcf()
{
	while(1)
	{
		dijkstra();
		if (dist[t]>inf) break;
		for (int i=1;i<=n;i++) h[i]+=dist[i];
		f=inf;
		for (int i=t;i!=s;i=prevv[i]) f=min(f,cap[preve[i]]);
		for (int i=flow+1;i<=flow+f;i++) ans[i]=ans[i-1]+h[t];
		flow+=f;
		for (int i=t;i!=s;i=prevv[i])
		{
			cap[preve[i]]-=f;
			cap[preve[i]^1]+=f;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);cnt=1;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,1,z);
		addedge(y,x,0,-z);
	}
	s=1;t=n;
	mcf();
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&que[i].first);
		que[i].second=i;
	}
	sort(que+1,que+q+1);pos=1;
	for (int i=1;i<=q;i++)
	{
		while(pos<flow && 1ll*(ans[pos]+que[i].first)*(pos+1)>=1ll*(ans[pos+1]+que[i].first)*pos) pos++;
		res[que[i].second]=(double)(ans[pos]+que[i].first)/(double)pos;
	}
	for (int i=1;i<=q;i++) printf("%.9lf\n",res[i]);
	return 0;
}