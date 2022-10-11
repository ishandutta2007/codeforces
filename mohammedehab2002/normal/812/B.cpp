#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[20][105];
string s[20];
int find(int x,int dir)
{
	if (!dir)
	{
		int ans=0;
		for (int i=0;i<s[x].size();i++)
		{
			if (s[x][i]=='1')
			ans=i;
		}
		return ans;
	}
	else
	{
		int ans=s[x].size()-1;
		for (int i=s[x].size()-1;i>=0;i--)
		{
			if (s[x][i]=='1')
			ans=i;
		}
		return s[x].size()-ans-1;
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i=n-1;i>=0;i--)
	cin >> s[i];
	while (count(s[n-1].begin(),s[n-1].end(),'0')==m+2)
	{
		n--;
		if (n==0)
		break;
	}
	if (n<=1)
	{
		cout << find(0,0);
		return 0;
	}
	dp[0][0]=2*find(0,0);
	dp[0][1]=m+1;
	for (int i=1;i<n-1;i++)
	{
		dp[i][0]=min(dp[i-1][0]+2*find(i,0)+1,dp[i-1][1]+m+2);
		dp[i][1]=min(dp[i-1][1]+2*find(i,1)+1,dp[i-1][0]+m+2);
	}
	cout << min(dp[n-2][0]+find(n-1,0)+1,dp[n-2][1]+find(n-1,1)+1);
}