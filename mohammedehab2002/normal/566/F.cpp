#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000005];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		dp[a]=max(dp[a],1);
		for (int i=2*a;i<1000005;i+=a)
		dp[i]=max(dp[i],1+dp[a]);
		ans=max(ans,dp[a]);
	}
	printf("%d",ans);
}