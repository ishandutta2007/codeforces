#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,r1,r2,r3,d;
int a[N],dp[N][4],f[N][4],g[N][4];
signed main()
{
	register int i;
	scanf("%lld%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=n;i>=1;i--)
	{
		g[i][0]=0;g[i][1]=min(r1,min(r2,r3));
		g[i][2]=min(min(r1,r2)+2*d+g[i][1],r3);
		g[i][3]=min(a[i]*min(r1,r3)+g[i][2],r2+2*d+g[i][1]);
	}
	memcpy(f[n],g[n],sizeof(g[n]));
	for(i=n-1;i>=1;i--)
	{
		f[i][0]=2*d+f[i+1][3];
		f[i][1]=g[i][1]+2*d+f[i+1][3];
		f[i][2]=min(min(r1,r2)+2*d+f[i+1][3]+g[i][1],r3+2*d+f[i+1][3]);
		f[i][3]=min(a[i]*min(r1,r3)+f[i][2],r2+2*d+f[i+1][3]+g[i][1]);
	}
	memcpy(dp[n],g[n],sizeof(g[n]));
	for(i=n-1;i>=1;i--)
	{
		dp[i][0]=d+dp[i+1][3];
		dp[i][1]=min(r1,min(r2,r3))+d+dp[i+1][3];
		dp[i][2]=min(f[i][2],min(r1,r2)+3*d+g[i][1]+dp[i+1][3]);
		dp[i][2]=min(dp[i][2],min(r1,r2)+3*d+g[i][1]+min(r2,min(r1,r3)*a[i+1]+min(r1,r2))+dp[i+1][1]);
		dp[i][2]=min(dp[i][2],r3+d+dp[i+1][3]);
		dp[i][3]=min(f[i][3],a[i]*min(r1,r3)+dp[i][2]);
		dp[i][3]=min(dp[i][3],r2+3*d+g[i][1]+dp[i+1][3]);
		dp[i][3]=min(dp[i][3],r2+3*d+g[i][1]+min(r2,min(r1,r3)*a[i+1]+min(r1,r2))+dp[i+1][1]);
	}
	printf("%lld\n",dp[1][3]);
	return 0;
}