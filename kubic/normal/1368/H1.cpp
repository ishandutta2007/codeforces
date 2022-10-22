#include <bits/stdc++.h>
using namespace std;
#define N 100005
const int INF=1e9;
int n,m,c,ans=INF,dp[N][2];char a1[N],a2[N],b1[N],b2[N];
int slv()
{
	dp[0][0]=dp[0][1]=0;for(int i=1;i<=m;++i) ++dp[0][b1[i]=='B'];
	for(int i=1,mn;i<=n;++i)
	{
		dp[i][0]=dp[i][1]=INF;mn=min(dp[i-1][0],dp[i-1][1]);
		dp[i][0]=min(mn+m,dp[i-1][0])+(a1[i]=='R')+(a2[i]=='R');
		dp[i][1]=min(mn+m,dp[i-1][1])+(a1[i]=='B')+(a2[i]=='B');
	}for(int i=1;i<=m;++i) ++dp[n][b2[i]=='B'];
	return min(dp[n][0],dp[n][1]);
}
int main()
{
	scanf("%d %d %d %s %s %s %s",&n,&m,&c,a1+1,a2+1,b1+1,b2+1);
	ans=slv();swap(n,m);swap(a1,b1);swap(a2,b2);
	ans=min(ans,slv());printf("%d\n",ans);return 0;
}