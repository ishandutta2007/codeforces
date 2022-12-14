#include<iostream>
using namespace std;
int dp[111][5],n,s;
pair<bool,bool> a[111];
const int Inf=2000000;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		if (s>=2) a[i].first=1;
		if (s%2) a[i].second=1;
	}
	for (int i=0;i<110;i++)
	{
		for (int j=0;j<5;j++)
		dp[i][j]=Inf;
	}
	if (a[1].first) dp[1][1]=0;
	if (a[1].second) dp[1][2]=0;
	dp[1][0]=1;
	for (int i=2;i<=n;i++)
	{
		if (a[i].first) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		if (a[i].second) dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
	}
	cout<<min(min(dp[n][0],dp[n][1]),dp[n][2])<<endl;
	return 0;
}