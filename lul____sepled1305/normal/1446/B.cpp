#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
int dp[N][N];
string s,t;
int i,j,n,m,maxi;

int main() {
	cin>>n>>m;
	cin>>s>>t;
	s = " "+s;
	t = " "+t;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp[i][j] = max(dp[i-1][j]-1,dp[i][j-1]-1);
			dp[i][j] = max(dp[i][j],0);
			if(s[i]==t[j])
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+2);
			maxi = max(maxi,dp[i][j]);
		}
	}
	cout<<maxi;
	return 0;
}