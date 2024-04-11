#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int A[16][10000];
int D[16][16];
int dp[1<<16][16][16];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)scanf("%d",&A[i][j]);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)
	{
		int now=1e9;
		for(int k=0;k<M;k++)now=min(now,abs(A[i][k]-A[j][k]));
		D[i][j]=now;
	}
	for(int i=0;i<1<<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)dp[i][j][k]=-1;
	for(int i=0;i<N;i++)dp[1<<i][i][i]=1e9;
	for(int i=1;i<1<<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)
	{
		if(dp[i][j][k]==-1)continue;
		for(int l=0;l<N;l++)if(!(i>>l&1))
		{
			dp[i|1<<l][j][l]=max(dp[i|1<<l][j][l],min(dp[i][j][k],D[k][l]));
		}
	}
	int ans=0;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)
	{
		int now=dp[(1<<N)-1][i][j];
		for(int k=0;k<M-1;k++)now=min(now,abs(A[j][k]-A[i][k+1]));
		ans=max(ans,now);
	}
	printf("%d\n",ans);
}