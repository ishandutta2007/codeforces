#include<iostream>
using namespace std;
int N,X,Y;
int dp[2][1<<22];
main()
{
	cin>>N>>X>>Y;
	int L=X<Y?Y:X;
	int msk=(1<<L)-1;
	int now=0;
	for(int i=0;i<X+Y;i++)
	{
		int nxt=1-now;
		int val=N/(X+Y)+(i<N%(X+Y));
		for(int j=0;j<1<<L;j++)
		{
			dp[nxt][j<<1&msk]=max(dp[nxt][j<<1&msk],dp[now][j]);
			if(!(j>>X-1&1||j>>Y-1&1))
			{
				dp[nxt][j<<1&msk|1]=max(dp[nxt][j<<1&msk|1],dp[now][j]+val);
			}
		}
		now=nxt;
	}
	int ans=0;
	for(int j=0;j<1<<L;j++)ans=max(ans,dp[now][j]);
	cout<<ans<<endl;
}