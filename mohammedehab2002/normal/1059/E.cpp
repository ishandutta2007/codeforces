#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[100005];
int l,arr[100005],dp[20][100005];
long long w,cum[100005];
void pre(int node)
{
	for (int i=1;i<=20;i++)
	{
		if (dp[i-1][node]!=-1)
		dp[i][node]=dp[i-1][dp[i-1][node]];
	}
	cum[node]+=arr[node];
	for (int u:v[node])
	{
		dp[0][u]=node;
		cum[u]=cum[node];
		pre(u);
	}
}
pair<int,int> dfs(int node,int dep)
{
	int ans=0,mn=(1<<30);
	for (int u:v[node])
	{
		auto p=dfs(u,dep+1);
		ans+=p.first;
		mn=min(mn,p.second);
	}
	if (dep<mn)
	{
		ans++;
		int p=1,cur=node;
		for (int i=19;i>=0;i--)
		{
			if (p+(1<<i)<=l && dp[i][cur]!=-1 && cum[node]-cum[dp[i][cur]]+arr[dp[i][cur]]<=w)
			{
				p+=(1<<i);
				cur=dp[i][cur];
			}
		}
		mn=min(mn,dep-p+1);
	}
	return {ans,mn};
}
int main()
{
	int n;
	scanf("%d%d%I64d",&n,&l,&w);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]>w)
		{
			printf("-1");
			return 0;
		}
	}
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	memset(dp,-1,sizeof(dp));
	pre(1);
	printf("%d",dfs(1,0));
}