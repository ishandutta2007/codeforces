#include <bits/stdc++.h>
using namespace std;
#define N 45
#define ll long long
int n,m;ll dp[N][N];
int main()
{
	scanf("%d %d",&n,&m);for(int i=0;i<=n;++i) dp[0][i]=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=0;k<i;++k)
		dp[i][j]+=dp[k][j-1]*dp[i-k-1][j-1];
	printf("%lld\n",dp[n][n]-dp[n][m-1]);
}