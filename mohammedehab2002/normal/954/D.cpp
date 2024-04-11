#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int dist[1005][1005];
vector<int> v[1005];
bool vis[1005];
int main()
{
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1;i<=n;i++)
	{
		queue<pair<int,int> > q;
		q.push({i,0});
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		while (!q.empty())
		{
			int node=q.front().first,d=q.front().second;
			q.pop();
			dist[i][node]=d;
			for (int u:v[node])
			{
				if (!vis[u])
				{
					vis[u]=1;
					q.push({u,d+1});
				}
			}
		}
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		for (int x=i+1;x<=n;x++)
		{
			if (dist[i][x]==1)
			continue;
			cnt+=(dist[s][i]+dist[x][t]+1>=dist[s][t] && dist[s][x]+dist[i][t]+1>=dist[s][t]);
		}
	}
	printf("%d",cnt);
}