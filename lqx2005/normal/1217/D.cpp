#include<bits/stdc++.h>
using namespace std;
const int N=500000;
struct node
{
	int u,v;
}e[N+5];
int n,m;
vector<int> g[N+5];
int deg[N+5];
bool topsort()
{
	queue<int> q;
	for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
	int tot=0;
	while(!q.empty())
	{
		tot++;
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			deg[v]--;
			if(deg[v]==0) q.push(v);
		}
	}
	return tot!=n;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
		g[e[i].u].push_back(e[i].v);
		deg[e[i].v]++;
	}
	if(topsort()) 
	{
		printf("2\n");
		for(int i=1;i<=m;i++)
		{
			if(e[i].u>e[i].v) printf("1 ");
			else printf("2 ");
		}
		printf("\n");
	}
	else
	{
		printf("1\n");
		for(int i=1;i<=m;i++) printf("1 ");
		printf("\n");
	}
	return 0;
}