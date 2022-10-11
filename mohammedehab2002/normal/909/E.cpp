#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[100005];
int arr[100005],dp[100005];
int dfs(int node)
{
	if (dp[node]!=-1)
	return dp[node];
	dp[node]=arr[node];
	for (int u:v[node])
	dp[node]=max(dp[node],dfs(u)+(arr[node] && !arr[u]));
	return dp[node];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for (int i=0;i<n;i++)
	ans=max(ans,dfs(i));
	printf("%d",ans);
}