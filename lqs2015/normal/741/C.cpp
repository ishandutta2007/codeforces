#include<bits/stdc++.h>
using namespace std;
int n,x[111111],y[111111],col[222222];
vector<int> g[222222];
bool used[222222];
void dfs(int i,int t)
{
	col[i]=t;
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!used[to]) dfs(to,3-t);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);  
	}
	for (int i=1;i<=2*n;i+=2)
	{
		g[i].push_back(i+1); 
		g[i+1].push_back(i); 
	}
	for (int i=1;i<=2*n;i++)
	{
		if (!used[i])
		{
			dfs(i,1);
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d %d\n",col[x[i]],col[y[i]]);
	}
	return 0;
}