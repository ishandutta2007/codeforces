#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
char S[222];
char T[5];
int dp[201][201][201];
main()
{
	scanf("%d%d%s%s",&N,&K,S,T);
	for(int i=0;i<=N;i++)for(int j=0;j<=i;j++)for(int k=0;k<=K;k++)dp[i][j][k]=-1e9;
	dp[0][0][K]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)for(int k=0;k<=K;k++)if(dp[i][j][k]>=0)
		{
			dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
			if(S[i]==T[0])
			{
				dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+j*(T[0]==T[1]));
			}
			else if(k>0)
			{
				dp[i+1][j+1][k-1]=max(dp[i+1][j+1][k-1],dp[i][j][k]+j*(T[0]==T[1]));
			}
			if(S[i]==T[1])
			{
				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+j);
			}
			else if(k>0)
			{
				dp[i+1][j][k-1]=max(dp[i+1][j][k-1],dp[i][j][k]+j);
			}
		}
	}
	int ans=0;
	for(int j=0;j<=N;j++)for(int k=0;k<=K;k++)ans=max(ans,dp[N][j][k]);
	printf("%d\n",ans);
}