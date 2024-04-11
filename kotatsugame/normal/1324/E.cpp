#include<cstdio>
#include<algorithm>
using namespace std;
int N,H,L,R;
int dp[2001][2001];
main()
{
	scanf("%d%d%d%d",&N,&H,&L,&R);
	int cumsum=0;
	for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dp[i][j]=-1e9;
	dp[0][0]=0;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		cumsum+=A;
		for(int j=0;j<=i;j++)
		{
			int t=(cumsum-j)%H;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(L<=t&&t<=R));
			t=(cumsum-j-1)%H;
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+(L<=t&&t<=R));
		}
	}
	int ans=0;
	for(int i=0;i<=N;i++)ans=max(ans,dp[N][i]);
	printf("%d\n",ans);
}