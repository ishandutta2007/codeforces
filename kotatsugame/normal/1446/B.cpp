#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
string A,B;
int dp[5050][5050];
main()
{
	cin>>N>>M>>A>>B;
	int ans=0;
	for(int i=0;i<=N;i++)for(int j=0;j<=M;j++)
	{
		ans=max(ans,dp[i][j]);
		if(i<N&&j<M&&A[i]==B[j])dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+2);
		if(i<N)dp[i+1][j]=max(dp[i+1][j],dp[i][j]-1);
		if(j<M)dp[i][j+1]=max(dp[i][j+1],dp[i][j]-1);
	}
	cout<<ans<<endl;
}