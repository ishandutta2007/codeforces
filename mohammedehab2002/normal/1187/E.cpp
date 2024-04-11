#include <iostream>
#include <vector>
using namespace std;
vector<int> v[200005];
long long dp[200005],ans;
int n,sz[200005],dep[200005];
int pre(int node,int p)
{
	dep[node]=dep[p]+1;
	dp[1]+=dep[node];
	sz[node]=1;
	for (int u:v[node])
	{
		if (u!=p)
		sz[node]+=pre(u,node);
	}
	return sz[node];
}
void dfs(int node,int p)
{
	if (p)
	dp[node]=dp[p]+n-2*sz[node];
	ans=max(ans,dp[node]);
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	pre(1,0);
	dfs(1,0);
	printf("%I64d",ans);
}