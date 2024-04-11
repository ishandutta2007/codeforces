#include<iostream>
#include<algorithm>
using namespace std;
long long X,dp[5][3<<17];
int N;
main()
{
	cin>>N>>X;
	for(int i=0;i<N;i++)
	{
		long long A;cin>>A;
		dp[1][i+1]=max(dp[0][i+1],dp[1][i]+A);
		dp[2][i+1]=max(dp[1][i+1],dp[2][i]+A*X);
		dp[3][i+1]=max(dp[2][i+1],dp[3][i]+A);
		dp[4][i+1]=max(dp[3][i+1],dp[4][i]);
	}
	cout<<dp[4][N]<<endl;
}