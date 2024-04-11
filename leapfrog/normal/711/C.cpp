#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[105];long long r,dp[105][105][105],w[105][105];
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k),memset(dp,0x3f,sizeof(dp)),r=(int)0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++) scanf("%lld",c+i);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%lld",&w[i][j]);
	if(c[1]) dp[1][1][c[1]]=0;else for(int i=1;i<=m;i++) dp[1][1][i]=w[1][i];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k&&j<=i;j++)
			if(c[i])
			{
				for(int g=1;g<=m;g++)
					if(c[i]==g) dp[i][j][g]=min(dp[i][j][g],dp[i-1][j][g]);
					else dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][g]);
			}
			else
			{
				for(int g=1;g<=m;g++)
					for(int p=1;p<=m;p++)
						if(g==p) dp[i][j][g]=min(dp[i][j][g],dp[i-1][j][p]+w[i][g]);
						else dp[i][j][g]=min(dp[i][j][g],dp[i-1][j-1][p]+w[i][g]);
			}
	if(c[n]) r=dp[n][k][c[n]];else for(int i=1;i<=m;i++) r=min(r,dp[n][k][i]);
	if(r>=(long long)0x3f3f3f3f3f3f3f3f) return puts("-1"),0;else return printf("%lld\n",r),0;
}