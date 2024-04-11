#include<iostream>
#include<algorithm>
using namespace std;
int T,N,M;
string A,B;
int dp[2][5001][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>A>>B;
		int now=0;
		for(int j=0;j<=M;j++)for(int k=0;k<3;k++)dp[now][j][k]=1e9;
		dp[now][0][0]=1;
		dp[now][0][1]=0;
		for(int i=0;i<N;i++)
		{
			int nxt=1-now;
			for(int j=0;j<=M;j++)for(int k=0;k<3;k++)dp[nxt][j][k]=1e9;
			for(int j=0;j<=M;j++)
			{
				dp[now][j][1]=min(dp[now][j][1],dp[now][j][0]);
				dp[now][j][2]=min(dp[now][j][2],dp[now][j][1]+N-i);
				if(j<M&&A[i]==B[j])
				{
					dp[nxt][j+1][0]=min(dp[nxt][j+1][0],dp[now][j][0]+1);
					dp[nxt][j+1][1]=min(dp[nxt][j+1][1],dp[now][j][1]);
					dp[nxt][j+1][2]=min(dp[nxt][j+1][2],dp[now][j][2]);
				}
				{
					dp[nxt][j][0]=min(dp[nxt][j][0],dp[now][j][0]+2);
					dp[nxt][j][2]=min(dp[nxt][j][2],dp[now][j][2]);
				}
			}
			now=nxt;
		}
		int ans=1e9;
		for(int k=0;k<3;k++)ans=min(ans,dp[now][M][k]);
		if(ans==(int)1e9)ans=-1;
		cout<<ans<<"\n";
	}
}