#include<bits/stdc++.h>
using namespace std;
int n,a,b,da,db,test,x,y,d,dist[111111];
vector<int> g[111111];
void dfs(int i,int fa,int dis,int des)
{
	if (i==des) 
	{
		d=dis;
		return;
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i,dis+1,des);
	}
}
int bfs(int s)
{
	for (int i=1;i<=n;i++) dist[i]=-1;
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!~dist[to])
			{
				dist[to]=dist[x]+1;
				q.push(to);
			}
		}
	}
	int mxi=1;
	for (int i=2;i<=n;i++)
	{
		if (dist[i]>dist[mxi]) mxi=i;
	}
	return mxi;
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(a,0,0,b);
		if (d<=da)
		{
			printf("Alice\n");
			continue;
		}
		x=bfs(1);
		y=bfs(x);
		if (min(dist[y],db)>2*da) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}