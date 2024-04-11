#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,K;
int dp[70];
int tmp[70];
int dp2[40][70];
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<K;i++)dp[i]=-1e8;
	for(int I=0;I<N;I++)
	{
		int T=M/2;
		for(int i=0;i<=T;i++)for(int j=0;j<K;j++)dp2[i][j]=-1e8;
		dp2[0][0]=0;
		for(int J=0;J<M;J++)
		{
			int A;scanf("%d",&A);
			for(int i=T-1;i>=0;i--)for(int j=0;j<K;j++)
			{
				dp2[i+1][(j+A)%K]=max(dp2[i+1][(j+A)%K],dp2[i][j]+A);
			}
		}
		for(int i=0;i<K;i++)tmp[i]=dp[i];
		for(int i=0;i<=T;i++)for(int j=0;j<K;j++)
		{
			for(int k=0;k<K;k++)
			{
				tmp[(j+k)%K]=max(tmp[(j+k)%K],dp[k]+dp2[i][j]);
			}
		}
		for(int i=0;i<K;i++)dp[i]=tmp[i];
	}
	printf("%d\n",dp[0]);
}