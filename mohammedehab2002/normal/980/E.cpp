#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[1000005];
int dp[22][1000005],dep[1000005];
bool b[1000005];
void dfs(int node,int p)
{
	dp[0][node]=p;
	if (p!=-1)
	dep[node]=dep[p]+1;
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	k=n-k-1;
	b[n]=1;
	memset(dp,-1,sizeof(dp));
	dfs(n,-1);
	for (int i=1;i<22;i++)
	{
		for (int x=1;x<=n;x++)
		{
			if (dp[i-1][x]!=-1)
			dp[i][x]=dp[i-1][dp[i-1][x]];
		}
	}
	for (int i=n-1;i>0;i--)
	{
		int u=i;
		for (int x=21;x>=0;x--)
		{
			if (dp[x][u]!=-1 && !b[dp[x][u]])
			u=dp[x][u];
		}
		if (dep[i]-dep[u]+1<=k)
		{
			u=i;
			while (!b[u])
			{
				b[u]=1;
				k--;
				u=dp[0][u];
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!b[i])
		printf("%d ",i);
	}
}