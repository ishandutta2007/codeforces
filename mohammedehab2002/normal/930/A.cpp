#include <iostream>
using namespace std;
int dp[100005],cnt[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		dp[i]=dp[a]+1;
		cnt[dp[i]]++;
	}
	int ans=1;
	for (int i=1;i<=n;i++)
	ans+=cnt[i]%2;
	printf("%d",ans);
}