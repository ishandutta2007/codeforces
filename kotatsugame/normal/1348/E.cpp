#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
int A[500],B[500];
long long ans;
bool dp[501][500];
main()
{
	scanf("%d%d",&N,&K);
	long long sa=0,sb=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&A[i],&B[i]);
		sa+=A[i];
		sb+=B[i];
	}
	dp[0][0]=true;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=K;j++)if(j<=A[i]&&K-j<=B[i])
		{
			for(int k=0;k<K;k++)if(dp[i][k])
			{
				dp[i+1][(k+j)%K]=true;
			}
		}
		for(int k=0;k<K;k++)if(dp[i][k])dp[i+1][k]=true;
	}
	ans=sa/K+sb/K;
	for(int k=1;k<K;k++)
	{
		if(dp[N][k]&&sb>=K-k)ans=max(ans,(sa-k)/K+(sb-(K-k))/K+1);
	}
	printf("%lld\n",ans);
}