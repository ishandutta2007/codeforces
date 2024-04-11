#include <iostream>
using namespace std;
int n,k,arr[2005],dp[2005];
int get(int x)
{
	for (int i=1;i<=n+1;i++)
	dp[i]=1e9;
	for (int i=0;i<=n;i++)
	{
		for (int j=i+1;j<=n+1;j++)
		{
			if (!i || j==n+1 || abs(arr[i]-arr[j])<=1LL*(j-i)*x)
			dp[j]=min(dp[j],dp[i]+j-i-1);
		}
	}
	return dp[n+1];
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	int st=0,en=2e9;
	while (st!=en)
	{
		int mid=(1LL*st+en)/2;
		if (get(mid)<=k)
		en=mid;
		else
		st=mid+1;
	}
	printf("%d",st);
}