#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
int dp[201][5001];
main()
{
	cin>>N>>K;
	for(int i=0;i<=K;i++)for(int j=0;j<=5000;j++)dp[i][j]=-1e9;
	dp[0][0]=0;
	for(int i=0;i<N;i++)
	{
		long long A;cin>>A;
		int c2=0,c5=0;
		while(A%2==0)c2++,A/=2;
		while(A%5==0)c5++,A/=5;
		for(int j=K-1;j>=0;j--)for(int k=5000-c5;k>=0;k--)
		{
			dp[j+1][k+c5]=max(dp[j+1][k+c5],dp[j][k]+c2);
		}
	}
	int ans=0;
	for(int j=0;j<=5000;j++)ans=max(ans,min(j,dp[K][j]));
	cout<<ans<<endl;
}