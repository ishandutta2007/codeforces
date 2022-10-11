#include <iostream>
#include <string.h>
#include <map>
using namespace std;
long long dp[100005][4],arr[4];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<4;i++)
	scanf("%I64d",&arr[i]);
	for (int i=0;i<=n;i++)
	{
		for (int x=1;x<4;x++)
		dp[i][x]=-(1LL<<62);
	}
	for (int i=1;i<=n;i++)
	{
		long long a;
		scanf("%I64d",&a);
		for (int x=1;x<4;x++)
		dp[i][x]=max(dp[i-1][x],dp[i][x-1]+a*arr[x]);
	}
	printf("%I64d",dp[n][3]);
}