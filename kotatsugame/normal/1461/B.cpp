#include<cstdio>
using namespace std;
int T,N,M;
char S[555][555];
int dp[555][555];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d\n",&N,&M);
		for(int i=0;i<N;i++)scanf("%s\n",S[i]);
		for(int i=0;i<=N;i++)for(int j=0;j<M;j++)dp[i][j]=0;
		int ans=0;
		for(int i=N;i--;)for(int j=0;j<M;j++)if(S[i][j]=='*')
		{
			int t=dp[i+1][j];
			if(j>0)
			{
				if(t>dp[i+1][j-1])t=dp[i+1][j-1];
			}
			else t=0;
			if(j+1<M)
			{
				if(t>dp[i+1][j+1])t=dp[i+1][j+1];
			}
			else t=0;
			ans+=dp[i][j]=t+1;
		}
		printf("%d\n",ans);
	}
}