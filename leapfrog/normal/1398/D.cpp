#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[205],b[205],c[205];long long dp[205][205][205],res;
int main()
{
	scanf("%d%d%d",&n,&m,&k),memset(dp,0,sizeof(dp)),res=0;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
	for(int i=1;i<=k;i++) scanf("%d",c+i);
	sort(a+1,a+n+1,greater<int>()),sort(b+1,b+m+1,greater<int>()),sort(c+1,c+k+1,greater<int>());
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int l=0;l<=k;l++)
			{
				dp[i][j+1][l+1]=max(dp[i][j+1][l+1],dp[i][j][l]+1ll*b[j+1]*c[l+1]);
				dp[i+1][j+1][l]=max(dp[i+1][j+1][l],dp[i][j][l]+1ll*a[i+1]*b[j+1]);
				dp[i+1][j][l+1]=max(dp[i+1][j][l+1],dp[i][j][l]+1ll*a[i+1]*c[l+1]);
				res=max(res,dp[i][j][l]);
			}
	return printf("%lld\n",res),0;
}