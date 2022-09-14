#include<cstdio>
using namespace std;
int N,mod;
int dp[51][2][5000];
const int off=2500;
main()
{
	scanf("%d%d",&N,&mod);
	dp[1][0][off]=1%mod;
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int x=0;x<5000;x++)if(dp[i][j][x])
			{
				for(int k=0;k<=i;k++)for(int l=0;l<=i;l++)
				{
					int nx=x+k-l;
					int nj=k<l?1:k>l?0:j;
					dp[i+1][nj][nx]+=dp[i][j][x];
					if(dp[i+1][nj][nx]>=mod)dp[i+1][nj][nx]-=mod;
				}
			}
		}
	}
	int ans=0;
	for(int x=off+1;x<5000;x++)
	{
		ans+=dp[N][1][x];
		if(ans>=mod)ans-=mod;
	}
	printf("%d\n",ans);
}