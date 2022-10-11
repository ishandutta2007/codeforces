#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v[200005];
int par[200005],dep[200005],dp[200005];
int dfs(int node,int pnode,int d)
{
	dep[node]=d;
	par[node]=pnode;
	dp[node]=d;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		dp[node]=max(dp[node],dfs(v[node][i],node,d+1));
	}
	return dp[node];
}
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0,0);
	int cur=x,s=(dep[x]-1)/2;
	while (s--)
	cur=par[cur];
	printf("%d",dp[cur]*2);
}