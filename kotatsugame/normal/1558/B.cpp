#include<iostream>
using namespace std;
int rd(){int x;cin>>x;return x;}
int dp[4000002];
main()
{
	const int N=rd();
	const int M=rd();
	dp[N]=1;
	for(int i=N-1;i>=1;i--)
	{
		dp[i]=dp[i+1]*2%M;
		for(int k=2;i*k<=N;k++)
		{
			int r=i*k+k;
			if(r>N)r=N+1;
			dp[i]=((long long)dp[i]+dp[i*k]-dp[r]+M)%M;
		}
	}
	cout<<(dp[1]-dp[2]+M)%M<<endl;
}