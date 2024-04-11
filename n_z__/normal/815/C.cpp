#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][5001][5001];
main()
{
	int n,b;
	cin>>n>>b;
	vector<int>a[n+1];
	for(int x=1;x<=n;x++)
	{
		cin>>dp[0][x][1]>>dp[1][x][1];
		if(x>=2){
			int u;
			cin>>u;
			a[u].push_back(x);
		}
	}
	vector<int>s(n+1);
	for(int x=n;x>=1;x--)
	{
		for(int y=2;y<=n;y++)
		dp[0][x][y]=dp[1][x][y]=1e18;
		s[x]=1;
		dp[1][x][1]=dp[0][x][1]-dp[1][x][1];
		for(auto q:a[x])
		{
			for(int y=s[x];y>=0;y--)
			for(int z=s[q];z>=0;z--)
			{
				dp[0][x][y+z]=min(dp[0][x][y+z],dp[0][x][y]+dp[0][q][z]);
				if(y)dp[1][x][y+z]=min(dp[1][x][y+z],dp[1][x][y]+dp[1][q][z]);
			}
			s[x]+=s[q];
		}
		for(int y=1;y<=s[x];y++)
		dp[1][x][y]=min(dp[1][x][y],dp[0][x][y]);
	}
	cout<<(upper_bound(dp[1][1]+1,dp[1][1]+1+n,b)-dp[1][1]-1)<<endl;
}