#include<bits/stdc++.h>
using namespace std;
struct edge
{
	long long to,cap,rev;
};
vector<edge> g[222222];
void addedge(long long s,long long t,long long cp)
{
	g[s].push_back((edge){t,cp,g[t].size()});
	g[t].push_back((edge){s,0,g[s].size()-1}); 
}
long long dist[222222],s,t,a[2222],x,y,z,ans,n,m;
void bfs()
{
	for (long long i=1;i<=t;i++) dist[i]=1e14;
	queue<long long> q;
	q.push(s);
	dist[s]=0;
	while(!q.empty())
	{
		long long x=q.front();q.pop();
		for (long long i=0;i<g[x].size();i++)
		{
			edge e=g[x][i];
			if (dist[e.to]>dist[x]+1 && e.cap>0)
			{
				dist[e.to]=dist[x]+1;
				q.push(e.to); 
			}
		}
	 } 
}
long long dfs(long long i,long long f)
{
	if (i==t) return f;
	long long tmp=f;
	for (long long j=0;j<g[i].size();j++)
	{
		edge e=g[i][j];
		if (e.cap>0 && dist[e.to]==dist[i]+1)
		{
			long long d=dfs(e.to,min(tmp,e.cap));
			if (d)
			{
				tmp-=d;
				g[i][j].cap-=d;
				g[e.to][e.rev].cap+=d;
				if (!tmp) break;
			}
			else dist[e.to]=0;
		}
	}
	return f-tmp;
}
long long dinic()
{
	long long res=0;
	while(1)
	{
		bfs();
		if (dist[t]>=1e14) return res;
		res+=dfs(s,1e14);
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	s=n+m+1;t=n+m+2;
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<=n;i++)
	{
		addedge(i+m,t,a[i]);
	}
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		ans+=z;
		addedge(s,i,z);
		addedge(i,x+m,1e12);
		addedge(i,y+m,1e12);
	}
	printf("%I64d\n",ans-dinic());
	return 0;
}