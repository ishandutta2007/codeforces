#include <iostream>
using namespace std;
long long dp[32];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&dp[i]);
		if (i)
		dp[i]=min(dp[i],2LL*dp[i-1]);
	}
	for (int i=n;i<32;i++)
	dp[i]=2LL*dp[i-1];
	long long cur=0,ans=(1LL<<62);
	for (int i=31;i>=0;i--)
	{
		if (m&(1<<i))
		cur+=dp[i];
		else
		ans=min(ans,dp[i]+cur);
	}
	ans=min(ans,cur);
	printf("%I64d",ans);
}