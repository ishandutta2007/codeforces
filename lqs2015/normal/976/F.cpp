#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,cap,rev,id;
};
vector<edge> g[4444];
int n1,n2,m,x[2222],y[2222],deg[4444],s,t,mn,dist[4444],lst,ans[4444];
vector<int> res[4444];
void addedge(int s,int t,int cap,int id)
{
	g[s].push_back((edge){t,cap,(int)g[t].size(),id});
	g[t].push_back((edge){s,0,(int)g[s].size()-1,-1});
}
int bfs()
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
			if (e.cap<=0) continue;
			if (dist[e.to]==1e9)
			{
				dist[e.to]=dist[x]+1;
				q.push(e.to); 
			}
		}
	} 
}
int dfs(int i,int d)
{
	if (i==t) return d;
	int tmp=d;
	for (int j=0;j<g[i].size();j++)
	{
		edge e=g[i][j];
		if (dist[e.to]!=dist[i]+1 || e.cap<=0) continue;
		int di=dfs(e.to,min(tmp,e.cap));
		if (!di) dist[e.to]=0;	
		else
		{
			g[i][j].cap-=di;
			g[e.to][e.rev].cap+=di;
			tmp-=di;
			if (!tmp) break;
		}
	}
	return d-tmp;
}
int dinic()
{
	int res=0,f;
	while(1)
	{
		bfs();
		if (dist[t]>1e8) break;
		res+=dfs(s,1e9);
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n1,&n2,&m);
	s=n1+n2+1;t=n1+n2+2;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		deg[x[i]]++;deg[n1+y[i]]++;
	}
	mn=1e9;
	for (int i=1;i<=n1+n2;i++) mn=min(mn,deg[i]);
	for (int j=1;j<=m;j++)
	{
		addedge(x[j],n1+y[j],1,j);
	}
	for (int j=1;j<=n1;j++)
	{
		addedge(s,j,deg[j]-mn,-1);
	}
	for (int j=n1+1;j<=n1+n2;j++)
	{
		addedge(j,t,deg[j]-mn,-1);
	}
	lst=m;
	for (int i=mn;i>=0;i--)
	{
		lst-=dinic();
		ans[i]=lst;
		for (int j=1;j<=t;j++)
		{
			for (int k=0;k<g[j].size();k++)
			{
				edge e=g[j][k];
				if (e.cap && ~e.id) res[i].push_back(e.id); 
			}
		}
		for (int j=0;j<g[s].size();j++)
		{
			g[s][j].cap++;
		}
		for (int j=0;j<g[t].size();j++)
		{
			edge e=g[t][j];
			g[e.to][e.rev].cap++;
		}
	}
	for (int i=0;i<=mn;i++)
	{
		printf("%d ",ans[i]);
		for (int j=0;j<res[i].size();j++) printf("%d ",res[i][j]);
		printf("\n");
	}
	return 0;
}