#include<iostream>
using namespace std;
bool dp[16][360];
int n,a;
main()
{
	cin>>n;
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		for(int j=0;j<360;j++)
		{
			dp[i+1][(j+a)%360]|=dp[i][j];
			dp[i+1][(j-a+360)%360]|=dp[i][j];
		}
	}
	cout<<(dp[n][0]?"YES":"NO")<<endl;
}