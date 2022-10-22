#include <bits/stdc++.h>
using namespace std;
#define N 55
#define M 3005
int n,m,MOD,ans,dp[N][M][2];
const int D=1500;
void W(int &x,int y) {x=(x+y)%MOD;}
int main()
{
	scanf("%d %d",&n,&MOD);m=n*(n-1)/2;dp[0][D][1]=1;
	for(int i=1;i<=n;++i) for(int j=-m;j<=m;++j)
	{
		dp[i][D+j][1]=1ll*dp[i-1][D+j][1]*(n-i+1)%MOD;
		for(int k=1;k<=min(n-i,m-j);++k)
			W(dp[i][D+j][0],1ll*(dp[i-1][D+j+k][0]+dp[i-1][D+j+k][1])*(n-i-k+1)%MOD);
		for(int k=0;k<=min(n-i,m+j);++k)
			W(dp[i][D+j][0],1ll*dp[i-1][D+j-k][0]*(n-i-k+1)%MOD);
	}for(int i=1;i<=m;++i) W(ans,dp[n][D+i][0]);printf("%d\n",ans);return 0;
}