#include <iostream>
#include <vector>
using namespace std;
int arr[100005],dp[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	getchar();
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		int c=getchar();
		if (c=='0')
		dp[i]=dp[i-1];
		else
		dp[i]=max(sum,dp[i-1]+arr[i]);
		sum+=arr[i];
	}
	printf("%d",dp[n]);
}