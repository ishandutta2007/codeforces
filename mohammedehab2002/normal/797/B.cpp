#include <iostream>
#include <math.h>
using namespace std;
int dp[100005][2];
int main()
{
	int n;
	scanf("%d",&n);
	int mn=-(1<<30),ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (!i)
		{
			if (a%2==0)
			{
				dp[i][0]=max(a,0);
				dp[i][1]=-(1<<30);
			}
			else
			dp[i][1]=a;
			continue;
		}
		for (int x=0;x<2;x++)
		dp[i][x]=max(dp[i-1][(x^(abs(a)%2))]+a,dp[i-1][x]);
	}
	printf("%d",dp[n-1][1]);
}