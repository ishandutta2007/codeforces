#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct edge
{
	int to,val,pos;
};
edge make(int to,int val,int pos)
{
	edge a;
	a.to=to;a.val=val;a.pos=pos;
	return a;
}
vector<edge> g[222];
int n,m,x,y,z,a[111],b[111],c[111],ans,mat[111][111],s,t;
int dist[222];
void bfs()
{
	for (int i=1;i<=t;i++) dist[i]=1e9;
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			edge e=g[x][i];
			if (e.val<=0) continue;
			if (dist[e.to]>dist[x]+1)
			{
				dist[e.to]=dist[x]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int i,int f)
{
	if (i==t) return f;
	for (int j=0;j<g[i].size();j++)
	{
		edge e=g[i][j];
		if (e.val>0 && dist[e.to]==dist[i]+1)
		{
			int d=dfs(e.to,min(f,e.val));
			if (d>0)
			{
				g[i][j].val-=d;
				g[e.to][e.pos].val+=d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow()
{
	int flow=0,f=0;
	while(1)
	{
		bfs();
		if (dist[t]==1e9) return flow;
		f=dfs(s,1e9);
		while(f>0)
		{
			flow+=f;
			f=dfs(s,1e9);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		c[i]=a[i]-b[i];
	}
	int sum=0;
	for (int i=1;i<=n;i++) sum+=c[i];
	if (sum!=0)
	{
		printf("NO\n");
		return 0;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(make(n+y,0,g[n+y].size()));
		g[n+y].push_back(make(x,1e9,g[x].size()-1));
		g[y].push_back(make(n+x,0,g[n+x].size()));  
		g[n+x].push_back(make(y,1e9,g[y].size()-1));
	}
	for (int i=1;i<=n;i++)
	{
		g[n+i].push_back(make(i,0,g[i].size()));
		g[i].push_back(make(n+i,a[i],g[n+i].size()-1)); 
	}
	s=2*n+1;t=2*n+2;
	for (int i=1;i<=n;i++)
	{
		if (c[i]>0)
		{
			ans+=c[i];
			g[s].push_back(make(i,c[i],g[i].size()));
			g[i].push_back(make(s,0,g[s].size()-1));  
		}
		else if (c[i]<0)
		{
			g[i].push_back(make(t,-c[i],g[t].size()));
			g[t].push_back(make(i,0,g[i].size()-1));  
		}
	}
	if (maxflow()==ans)
	{
		printf("YES\n");
		for (int i=n+1;i<=2*n;i++)
		{
			for (int j=0;j<g[i].size();j++)
			{
				int to=g[i][j].to;
				if (to==i-n || to>n) continue;
				mat[i-n][to]=1e9-g[i][j].val;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) a[i]-=mat[i][j];
			mat[i][i]=a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			printf("%d ",mat[i][j]);
			printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}