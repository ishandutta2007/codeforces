#include <iostream>
#include <string.h>
using namespace std;
int dp[(1<<23)],a[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		dp[a[i]]=a[i];
	}
	for (int i=0;i<(1<<23);i++)
	{
		for (int x=i;x;x=(x&(x-1)))
		{
			if (dp[(i^(x&(-x)))]!=-1)
			dp[i]=dp[(i^(x&(-x)))];
		}
	}
	for (int i=0;i<n;i++)
	printf("%d ",dp[((~a[i])&((1<<23)-1))]);
}