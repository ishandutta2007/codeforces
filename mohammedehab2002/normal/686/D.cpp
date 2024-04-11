#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int sz[300005],dp[20][300005];
vector<int> v[300005];
void dfs(int node)
{
	sz[node]=1;
	for (int u:v[node])
	{
		dfs(u);
		sz[node]+=sz[u];
	}
	int big=-1;
	for (int u:v[node])
	{
		if (big==-1 || sz[u]>sz[big])
		big=u;
	}
	dp[0][node]=big;
	for (int i=1;i<20;i++)
	{
		if (dp[i-1][node]!=-1)
		dp[i][node]=dp[i-1][dp[i-1][node]];
	}
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	memset(dp,-1,sizeof(dp));
	dfs(1);
	while (q--)
	{
		int u;
		scanf("%d",&u);
		int cur=u;
		for (int i=19;i>=0;i--)
		{
			int tmp=dp[i][cur];
			if (sz[tmp]>sz[u]/2)
			cur=tmp;
		}
		printf("%d\n",cur);
	}
}