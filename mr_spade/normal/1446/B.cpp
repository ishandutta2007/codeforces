#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,ans;
char s[N],t[N];
int dp[N][N];
signed main()
{
	register int i,j;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(s[i]==t[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
			dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			ans=max(ans,dp[i][j]);
		}
	printf("%d\n",ans);
	return 0;
}