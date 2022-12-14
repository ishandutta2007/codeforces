#include<bits/stdc++.h>
using namespace std;
bool used1[222222],used2[222222],used[222222];
int n,m,x,y,deg[222222],ct,cnt,ans[222222];
vector<int> g[222222],rg[222222];
void topo()
{
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();ct++;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!--deg[to]) q.push(to);
		}
	}
}
void dfs(int i)
{
	if (used1[i]) return;
	used[i]=used1[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		dfs(to);
	}
}
void rdfs(int i)
{
	if (used2[i]) return;
	used[i]=used2[i]=1;
	for (int j=0;j<rg[i].size();j++)
	{
		int to=rg[i][j];
		rdfs(to);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		rg[y].push_back(x);
		deg[y]++;
	}
	topo();
	if (ct!=n)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[i]) 
		{
			cnt++;
			ans[i]=1;
		}
		dfs(i);
		rdfs(i);
	}
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++)
	{
		if (ans[i]) putchar('A');
		else putchar('E');
	}
	putchar('\n');
	return 0;
}