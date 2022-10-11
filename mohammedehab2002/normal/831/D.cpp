#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1005][2005];
int a[1005],b[2005];
int main()
{
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=1;i<=k;i++)
	scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	for (int i=1;i<=n;i++)
	{
		for (int x=0;x<=k;x++)
		{
			if (x<i)
			{
				dp[i][x]=(1LL<<60);
				continue;
			}
			dp[i][x]=min(dp[i][x-1],max(dp[i-1][x-1],(long long)abs(a[i]-b[x])+(long long)abs(p-b[x])));
		}
	}
	printf("%I64d",dp[n][k]);
}