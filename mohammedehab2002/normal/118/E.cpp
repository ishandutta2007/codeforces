#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
vector<int> v[100005];
vector<pair<int,int> > ans;
int disc[100005],low[100005],t;
void dfs(int node,int p)
{
	disc[node]=++t;
	low[node]=disc[node];
	for (int u:v[node])
	{
		if (u==p)
		continue;
		if (!disc[u])
		{
			ans.push_back({node,u});
			dfs(u,node);
			low[node]=min(low[node],low[u]);
		}
		else
		low[node]=min(low[node],disc[u]);
		if (disc[u]<disc[node])
		ans.push_back({node,u});
		if (low[u]>disc[node])
		{
			printf("0");
			exit(0);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	for (auto i:ans)
	printf("%d %d\n",i.first,i.second);
}