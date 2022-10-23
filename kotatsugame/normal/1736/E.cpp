#include<iostream>
#include<vector>
using namespace std;
int N,A[500];
int dp[2][1001][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<=2*N;i++)for(int j=0;j<=N;j++)dp[0][i][j]=-1e9;
	dp[0][N][0]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=2*N;j++)for(int l=0;l<=N;l++)dp[1][j][l]=-1e9;
		for(int j=0;j<=2*N;j++)for(int l=0;l<=i;l++)
		{
			int nj=j-(i-l)+1;
			if(N<=nj&&nj<=2*N)
			{
				dp[1][nj][l+1]=max(dp[1][nj][l+1],dp[0][j][l]+A[i]);
			}
		}
		for(int j=0;j<=2*N;j++)for(int l=0;l<N;l++)
		{
			if(dp[1][j][l]>0)dp[1][j][l+1]=max(dp[1][j][l+1],dp[1][j][l]+A[i]);
		}
		for(int j=0;j<=2*N;j++)for(int l=0;l<=N;l++)dp[0][j][l]=max(dp[0][j][l],dp[1][j][l]);
	}
	int ans=-1e9;
	for(int i=N;i<=2*N;i++)ans=max(ans,dp[0][i][N]);
	cout<<ans<<endl;
}