#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=100000,mod=1e9+7;
int n,m,dp[111111][2],ans;
int main()
{
	dp[1][0]=2;
	for (int i=2;i<=maxn;i++)
	{
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		dp[i][1]=dp[i-1][0];
	}
	scanf("%d%d",&n,&m);
	ans=(1ll*dp[n][0]+dp[n][1]+dp[m][0]+dp[m][1]-2)%mod;
	printf("%d\n",(ans+mod)%mod);
	return Accepted;
}