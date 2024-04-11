#include<bits/stdc++.h>
using namespace std;
int n,a[333333];
long long dp[333333],pre;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		pre+=a[i];
		dp[i]=min(dp[i-1]+a[i]/2,pre/3);
	}
	printf("%lld\n",dp[n]);
	return 0;
}