#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define MOD 998244353
int n,m,c,ans,dp[N][N];
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);dp[0][0]=1;
	for(int i=1;i<=c;++i) for(int j=0;j<=i;++j)
	{
		dp[i][j]=1ll*dp[i-1][j]*j%MOD;
		if(j) dp[i][j]=(dp[i][j]+1ll*dp[i-1][j-1]*(n-j+1))%MOD;
	}
	for(int i=0;i<=c;++i)
		ans=(ans+1ll*dp[c][i]*qPow(m,MOD-i-1))%MOD;
	printf("%d\n",ans);return 0;
}