#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,M;
unsigned long long A[100][100];
unsigned long long dp[100][100];
int d[2]={0,1};
const unsigned long long INF=15e18;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			scanf("%llu",&A[i][j]);
			A[i][j]+=N+M-(i+j);
		}
		unsigned long long ans=INF;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			unsigned long long D=A[i][j];
			if(D>A[0][0])continue;
			for(int x=0;x<N;x++)for(int y=0;y<M;y++)dp[x][y]=INF;
			dp[0][0]=A[0][0]-D;
			for(int x=0;x<N;x++)for(int y=0;y<M;y++)
			{
				if(dp[x][y]==INF)continue;
				for(int r=0;r<2;r++)
				{
					int tx=x+d[r],ty=y+d[r^1];
					if(tx<0||ty<0||tx>=N||ty>=M||A[tx][ty]<D)continue;
					dp[tx][ty]=min(dp[tx][ty],dp[x][y]+A[tx][ty]-D);
				}
			}
			ans=min(ans,dp[N-1][M-1]);
		}
		printf("%llu\n",ans);
	}
}