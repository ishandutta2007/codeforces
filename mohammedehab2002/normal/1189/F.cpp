#include <iostream>
#include <algorithm>
using namespace std;
#define mod 998244353
int dp[1005][1005],arr[1005];
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	for (int i=1e5/(k-1);i>=1;i--)
	{
		int l=1;
		for (int j=1;j<=n;j++)
		{
			while (l<j && arr[j]-arr[l]>=i)
			l++;
			dp[j][2]=(dp[j-1][2]+l-1)%mod;
			for (int m=3;m<=k;m++)
			dp[j][m]=(dp[l-1][m-1]+dp[j-1][m])%mod;
		}
		ans=(ans+dp[n][k])%mod;
	}
	printf("%d",ans);
}