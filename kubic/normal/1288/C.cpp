#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 15
#define MOD 1000000007
int n,m,dp[M<<1][N],s[M<<1][N];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) s[0][i]=1;
	for(int i=1;i<=m<<1;++i) for(int j=1;j<=n;++j)
	{
		dp[i][j]=(dp[i][j]+s[i-1][j])%MOD;
		s[i][j]=(s[i][j-1]+dp[i][j])%MOD; 
	}printf("%d\n",s[m<<1][n]);return 0;
}