#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n,m,q;
vector<int>G[400040];
int c[400040];
void dfs(int u,int C)
{
	c[u]=C;
	for(int i=0;i<G[u].size();i++)
	{
		if(c[G[u][i]]==0)dfs(G[u][i],C);
	}
}
main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<q;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(n+v);
		G[n+v].push_back(u);
	}
	int cnt=0;
	for(int i=0;i<n+m;i++)
	{
		if(c[i]==0)
		{
			cnt++;
			dfs(i,cnt);
		}
	}
	printf("%d\n",cnt-1);
}