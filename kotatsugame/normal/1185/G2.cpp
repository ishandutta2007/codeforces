#include<cstdio>
#include<vector>
using namespace std;
long long mod=1e9+7;
int N,T;
vector<int>A[3];
long long dp[3][51][2501];
long long DP[3][51][51][51];
long long sum[51][51][51];
long long F[51];
main()
{
	scanf("%d%d",&N,&T);
	F[0]=1;
	for(int i=1;i<=N;i++)F[i]=F[i-1]*i%mod;
	sum[0][0][0]=1;
	DP[0][1][0][0]=1;
	DP[1][0][1][0]=1;
	DP[2][0][0][1]=1;
	for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)for(int k=0;k<=N;k++)
	{
		for(int l=0;l<3;l++)
		{
			if(DP[l][i][j][k]==0)continue;
			if(i<N&&l!=0)
			{
				DP[0][i+1][j][k]+=DP[l][i][j][k];
				DP[0][i+1][j][k]%=mod;
			}
			if(j<N&&l!=1)
			{
				DP[1][i][j+1][k]+=DP[l][i][j][k];
				DP[1][i][j+1][k]%=mod;
			}
			if(k<N&&l!=2)
			{
				DP[2][i][j][k+1]+=DP[l][i][j][k];
				DP[2][i][j][k+1]%=mod;
			}
			sum[i][j][k]=(sum[i][j][k]+DP[l][i][j][k])%mod;
		}
	}
	for(int i=0;i<N;i++)
	{
		int t,g;scanf("%d%d",&t,&g);
		A[g-1].push_back(t);
	}
	for(int i=0;i<3;i++)
	{
		dp[i][0][0]=1;
		for(int t:A[i])
		{
			for(int j=A[i].size()-1;j>=0;j--)
			{
				for(int k=0;k<=T-t;k++)
				{
					dp[i][j+1][k+t]+=dp[i][j][k];
					dp[i][j+1][k+t]%=mod;
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=A[0].size();i++)for(int t0=0;t0<=T;t0++)
	{
		if(dp[0][i][t0]==0)continue;
		for(int j=0;j<=A[1].size();j++)for(int t1=0;t1+t0<=T;t1++)
		{
			if(dp[1][j][t1]==0)continue;
			for(int k=0;k<=A[2].size();k++)
			{
				if(dp[2][k][T-t0-t1]==0)continue;
				ans=(ans+dp[0][i][t0]*dp[1][j][t1]%mod*dp[2][k][T-t0-t1]%mod*sum[i][j][k]%mod*F[i]%mod*F[j]%mod*F[k]%mod)%mod;
			}
		}
	}
	printf("%lld\n",ans);
}