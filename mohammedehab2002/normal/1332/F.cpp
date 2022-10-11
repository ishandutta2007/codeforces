#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
vector<int> v[300005];
long long dp[300005][3];
void dfs(int node,int p)
{
	dp[node][0]=1;
	dp[node][1]=1;
	dp[node][2]=1;
	for (int u:v[node])
	{
		if (u!=p)
		{
			dfs(u,node);
			dp[node][0]=(dp[node][0]*(2*dp[u][0]+2*dp[u][1]+3*dp[u][2]))%mod;
			dp[node][1]=(dp[node][1]*(2*(dp[u][0]+dp[u][2])+dp[u][1]))%mod;
			dp[node][2]=(dp[node][2]*(dp[u][0]+dp[u][1]+dp[u][2]))%mod;
		}
	}
	dp[node][0]=(dp[node][0]-dp[node][2]+mod)%mod;
	dp[node][1]=(dp[node][1]-dp[node][2]+mod)%mod;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	printf("%I64d",(dp[1][0]+dp[1][1]+dp[1][2]-1+mod)%mod);
}