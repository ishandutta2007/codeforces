#include<bits/stdc++.h>
using namespace std;
const int MAXN=1111;
typedef long long LL;
LL dp[5][MAXN][MAXN];
LL val[MAXN][MAXN];
main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%I64d",&val[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1])+val[i][j];

	for(int i=n;i>0;i--)
		for(int j=m;j>0;j--)
			dp[2][i][j]=max(dp[2][i+1][j],dp[2][i][j+1])+val[i][j];
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
			dp[3][i][j]=max(dp[3][i-1][j],dp[3][i][j+1])+val[i][j];
	for(int i=n;i>0;i--)
		for(int j=1;j<=m;j++)
			dp[4][i][j]=max(dp[4][i+1][j],dp[4][i][j-1])+val[i][j];
	LL wyn=0;
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			wyn=max(wyn,dp[1][i-1][j]+dp[2][i+1][j]
			+dp[3][i][j+1]+dp[4][i][j-1]);
			wyn=max(wyn,dp[3][i-1][j]+dp[4][i+1][j]
			+dp[1][i][j-1]+dp[2][i][j+1]);
		}
	}
	printf("%I64d\n",wyn);
	return 0;
}