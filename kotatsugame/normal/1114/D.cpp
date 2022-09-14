#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>color;
int n,c[5555];
int dp[5005][5005];
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>c[i];
	color.push_back(c[0]);
	for(int i=1;i<n;i++)if(c[i-1]!=c[i])color.push_back(c[i]);
	n=color.size();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
	{
		if(i!=j)dp[i][j]=1e9;
	}
	for(int i=n;i--;)
	{
		for(int j=i;j<n;j++)
		{
			if(i>0&&j+1<n&&color[i-1]==color[j+1])
			{
				dp[i-1][j+1]=min(dp[i-1][j+1],dp[i][j]+1);
			}
			if(i>0)
			{
				dp[i-1][j]=min(dp[i-1][j],dp[i][j]+1);
			}
			if(j+1<n)
			{
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
}