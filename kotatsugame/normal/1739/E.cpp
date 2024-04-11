#include<iostream>
using namespace std;
int N;
string S[2];
int dp[2][2][2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>S[0]>>S[1];
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<N;k++)dp[i][j][k]=-1;
	dp[0][0][0]=0;
	if(S[1][0]=='1')dp[1][1][0]=1;
	int ans=0;
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)if(dp[i][j][k]>=0)
		{
			ans=max(ans,dp[i][j][k]);
			if(k+1<N)
			{
				dp[i][0][k+1]=max(dp[i][0][k+1],dp[i][j][k]+(S[i][k+1]-'0'));
				if(j==0&&S[!i][k+1]=='1')dp[!i][1][k+1]=max(dp[!i][1][k+1],dp[i][j][k]+(S[i][k+1]-'0')+1);
			}
		}
	}
	cout<<ans<<endl;
}