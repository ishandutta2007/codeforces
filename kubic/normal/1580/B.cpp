#include <bits/stdc++.h>
using namespace std;
#define N 105
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m,c,MOD,C[N][N],dp[N][N][N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int dfs(int n,int m,int c)
{
	if(n<c) return 0;if(!n) return 1;if(m==1 && c!=1) return 0;
	if(~dp[n][m][c]) return dp[n][m][c];dp[n][m][c]=0;
	for(int i=1;i<=n;++i) for(int j=max(c-n+i,0);j<=min(c,i-1);++j)
		dp[n][m][c]=(dp[n][m][c]+1ll*dfs(i-1,m-1,j)*dfs(n-i,m-1,c-j)%MOD*C[n-1][i-1])%MOD;
	return dp[n][m][c];
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&c,&MOD);set(dp,-1);dp[0][1][1]=1;
	for(int i=0;i<=n;++i) for(int j=0;j<=i;++j) C[i][j]=j?add(C[i-1][j],C[i-1][j-1]):1;
	for(int i=1;i<=n;++i) dp[i][1][1]=1ll*dp[i-1][1][1]*i%MOD;
	printf("%d\n",dfs(n,m,c));return 0;
}