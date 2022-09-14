#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int cnt[5<<20];
int sum[5<<20];
long long dp[5<<20];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);cnt[A]++;
	}
	const int LIM=(5<<20)-1;
	long long ans=0;
	for(int i=LIM;i>=1;i--)
	{
		for(int j=i;j<=LIM;j+=i)sum[i]+=cnt[j];
		long long now=(long long)i*sum[i];
		for(int j=i+i;j<=LIM;j+=i)
		{
			now=max(now,dp[j]+(long long)i*(sum[i]-sum[j]));
		}
		dp[i]=now;
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
}