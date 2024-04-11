#include <iostream>
using namespace std;
int dp[55],arr[55],cum[55];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=n;i>=0;i--)
	cum[i]=arr[i]+cum[i+1];
	dp[n]=arr[n];
	for (int i=n-1;i>=0;i--)
	{
		for (int x=0;x<2;x++)
		dp[i]=max(dp[i+1],cum[i+1]-dp[i+1]);
	}
	printf("%d %d",cum[0]-dp[0],dp[0]);
}