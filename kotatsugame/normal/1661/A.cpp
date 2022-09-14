#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[25],B[25];
long long dp[26][2];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		dp[0][0]=dp[0][1]=0;
		for(int i=0;i<N-1;i++)
		{
			for(int j=0;j<2;j++)dp[i+1][j]=1e18;
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					dp[i+1][k]=min(dp[i+1][k],dp[i][j]+abs(A[i]-A[i+1])+abs(B[i]-B[i+1]));
					swap(A[i+1],B[i+1]);
				}
				swap(A[i],B[i]);
			}
		}
		cout<<min(dp[N-1][0],dp[N-1][1])<<"\n";
	}
}