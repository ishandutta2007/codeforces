#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define MOD 1000000007
const int inv2=500000004;
int T,n,m,c,dp[N][N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void slv()
{
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=dp[i-1][0];dp[i][i]=add(dp[i-1][i-1],c);
		for(int j=1;j<i;++j)
			dp[i][j]=1ll*(dp[i-1][j-1]+dp[i-1][j])*inv2%MOD;
	}printf("%d\n",dp[n][m]);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}