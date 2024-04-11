#include <bits/stdc++.h>
using namespace std;
#define MX 100000
#define mod 998244353
int a[1005],dp[1005][1005];
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for (int b=0;(b+1)*(k-1)<=MX;b++)
	{
		int p=1;
		for (int i=1;i<=n;i++)
		{
			while (a[i]-a[p]>b)
			p++;
			for (int j=0;j<=k;j++)
			{
				dp[i][j]=dp[i-1][j];
				if (j)
				dp[i][j]=(dp[i][j]+dp[p-1][j-1])%mod;
			}
		}
		ans=(ans+dp[n][k])%mod;
	}
	printf("%d",ans);
}