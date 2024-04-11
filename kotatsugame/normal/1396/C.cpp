#include<cstdio>
#include<algorithm>
using namespace std;
int N;
long long D,R1,R2,R3;
long long A[1<<20];
long long dp[1<<20];
int main()
{
	scanf("%d%lld%lld%lld%lld",&N,&R1,&R2,&R3,&D);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]);
	for(int i=0;i<=N;i++)
	{
		dp[i]=1e18;
	}
	dp[0]=0;
	for(int i=0;i<N;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+D+R1*A[i]+R3);
		dp[i+1]=min(dp[i+1],dp[i]+3*D+min(R1+R2,A[i]*R1+R1*2));
		if(i+2<=N)
		{
			dp[i+2]=min(dp[i+2],dp[i]+4*D+min(R1+R2,A[i]*R1+min(R1*2,R3))+min(R1+R2,A[i+1]*R1+min(R1*2,R3)));
		}
	}
	long long ans=dp[N];
	long long cummin=D+min(2*D+min(R1+R2,A[N-1]*R1+R1*2),R1*A[N-1]+R3);
	ans=min(ans,cummin+dp[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		cummin+=2*D+min(R2+R1,R1*A[i]+min(R1*2,R3));
		ans=min(ans,cummin+dp[i]);
	}
	printf("%lld\n",ans-D);
}