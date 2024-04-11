#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
bool fav[1<<17];
int dp[20][1<<17][4];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++)
	{
		int A;scanf("%d",&A);
		fav[A-1]=true;
	}
	int MIN=-1e9;
	for(int i=0;i<1<<N-1;i++)
	{
		dp[0][i][0]=MIN;
		dp[0][i][1]=MIN;
		dp[0][i][2]=MIN;
		dp[0][i][3]=MIN;
		if(!fav[i*2]&&!fav[i*2+1])
		{
			dp[0][i][0]=0;
		}
		else if(!fav[i*2]&&fav[i*2+1]||fav[i*2]&&!fav[i*2+1])
		{
			dp[0][i][1]=1;
			dp[0][i][2]=1;
		}
		else
		{
			dp[0][i][3]=1;
		}
	}
	for(int k=1;k<N;k++)
	{
		for(int i=0;i<1<<N-k-1;i++)
		{
			dp[k][i][0]=MIN;
			dp[k][i][1]=MIN;
			dp[k][i][2]=MIN;
			dp[k][i][3]=MIN;

			dp[k][i][0]=max(dp[k][i][0],dp[k-1][i*2][0]+dp[k-1][i*2+1][0]);
			dp[k][i][1]=max(dp[k][i][1],dp[k-1][i*2][0]+dp[k-1][i*2+1][1]+1);
			dp[k][i][2]=max(dp[k][i][2],dp[k-1][i*2][0]+dp[k-1][i*2+1][1]+2);
			dp[k][i][2]=max(dp[k][i][2],dp[k-1][i*2][0]+dp[k-1][i*2+1][2]+2);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][0]+dp[k-1][i*2+1][3]+3);

			dp[k][i][1]=max(dp[k][i][1],dp[k-1][i*2][1]+dp[k-1][i*2+1][0]+1);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][1]+dp[k-1][i*2+1][1]+2);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][1]+dp[k-1][i*2+1][2]+3);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][1]+dp[k-1][i*2+1][3]+3);

			dp[k][i][2]=max(dp[k][i][2],dp[k-1][i*2][2]+dp[k-1][i*2+1][0]+2);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][2]+dp[k-1][i*2+1][1]+3);
			dp[k][i][2]=max(dp[k][i][2],dp[k-1][i*2][2]+dp[k-1][i*2+1][2]+2);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][2]+dp[k-1][i*2+1][3]+3);

			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][3]+dp[k-1][i*2+1][0]+3);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][3]+dp[k-1][i*2+1][1]+3);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][3]+dp[k-1][i*2+1][2]+3);
			dp[k][i][3]=max(dp[k][i][3],dp[k-1][i*2][3]+dp[k-1][i*2+1][3]+3);
		}
	}
	dp[N-1][0][1]+=1;
	dp[N-1][0][2]+=1;
	dp[N-1][0][3]+=1;
	int ans=0;
	for(int i=0;i<4;i++)if(ans<dp[N-1][0][i])ans=dp[N-1][0][i];
	printf("%d\n",ans);
}