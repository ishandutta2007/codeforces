#include<bits/stdc++.h>
using namespace std;
int n,m,k;long long s[5005],dp[5005][5005];
signed main()
{
	scanf("%d%d%d",&n,&m,&k),s[0]=0;
	for(int i=1,p;i<=n;i++) scanf("%d",&p),s[i]=s[i-1]+p;
	for(int kk=1;kk<=k;kk++)
	{
		long long mx=0;
		for(int i=m;i<=n;i++)
		{
			dp[i][kk]=max(dp[i-1][kk],dp[i][kk]),mx=max(mx,dp[i-m][kk-1]);
			dp[i][kk]=max(dp[i][kk],mx+s[i]-s[i-m]);
		}
	}
	return printf("%lld\n",dp[n][k]),0;
}