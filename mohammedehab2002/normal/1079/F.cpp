#include <iostream>
#include <vector>
using namespace std;
#define mod 998244353
vector<int> v[300005];
long long dp[300005][3];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
void dfs(int node,int p)
{
	dp[node][0]=1;
	long long tmp=1;
	for (int u:v[node])
	{
		if (u!=p)
		{
			dfs(u,node);
			tmp=(tmp*(dp[u][0]+2*dp[u][1]))%mod;
			dp[node][0]=(dp[node][0]*(dp[u][0]+dp[u][1]))%mod;
		}
	}
	dp[node][2]=(tmp-dp[node][0]+mod)%mod;
	for (int u:v[node])
	{
		if (u!=p)
		{
			int cur=(dp[u][0]+2*dp[u][1])%mod;
			tmp=(tmp*pow_log(cur,mod-2))%mod;
			dp[node][1]=(dp[node][1]+(dp[u][0]+dp[u][2])*tmp)%mod;
			tmp=(tmp*cur)%mod;
		}
	}
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
	printf("%I64d",(dp[1][0]+dp[1][1])%mod);
}