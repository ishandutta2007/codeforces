#include <bits/stdc++.h>
using namespace std;
#define N 105
#define ll long long
int T,n,ans,a[N],b[N],s[N],dp[N][N*N];
void slv()
{
	scanf("%d",&n);ans=1e9;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i]+b[i];
	for(int i=0;i<=n;++i) for(int j=0;j<=n*100;++j) dp[i][j]=1e9;dp[0][0]=0;
	for(int i=1;i<=n;++i) for(int j=0;j<=i*100;++j)
	{
		if(j>=a[i] && s[i]-j>=b[i]) dp[i][j]=min(dp[i][j],dp[i-1][j-a[i]]+(j-a[i])*a[i]+(s[i]-j-b[i])*b[i]);
		if(j>=b[i] && s[i]-j>=a[i]) dp[i][j]=min(dp[i][j],dp[i-1][j-b[i]]+(j-b[i])*b[i]+(s[i]-j-a[i])*a[i]);
	}for(int i=0;i<=n*100;++i) ans=min(ans,dp[n][i]);ans*=2;
	for(int i=1;i<=n;++i) ans+=(a[i]*a[i]+b[i]*b[i])*(n-1);printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}