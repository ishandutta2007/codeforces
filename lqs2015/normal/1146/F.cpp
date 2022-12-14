#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=998244353;
int n,x,dp[222222][3],cp[3],ncp[3];//0 not filled,1 have to go up,2 needn't go up
vector<int> g[222222];
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
void dfs(int i)
{
	if (!g[i].size()) 
	{
		dp[i][2]=1;
		return;
	}
	dp[i][0]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		dfs(to);
		dp[i][0]=1ll*dp[i][0]*(dp[to][0]+dp[to][2])%mod;
	}
	cp[0]=1;cp[1]=0;cp[2]=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		ncp[0]=1ll*cp[0]*(dp[to][0]+dp[to][2])%mod;
		ncp[1]=(1ll*cp[0]*(dp[to][2]+dp[to][1])%mod+1ll*cp[1]*(dp[to][0]+dp[to][2])%mod)%mod;
		ncp[2]=(1ll*cp[1]*(dp[to][2]+dp[to][1])%mod+1ll*cp[2]*(1ll*dp[to][0]+dp[to][2]+dp[to][2]+dp[to][1])%mod)%mod;
		cp[1]=ncp[1];cp[0]=ncp[0];cp[2]=ncp[2];
	}
	dp[i][1]=cp[1];dp[i][2]=cp[2];
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i); 
	}
	dfs(1);
	printf("%d\n",(dp[1][0]+dp[1][2])%mod);
	return Accepted;
}