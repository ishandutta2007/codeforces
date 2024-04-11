#include <iostream>
using namespace std;
int dp[55][3];
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<3;x++)
		dp[i][x]=(1<<25);
		string s;
		cin >> s;
		for (int x=0;x<s.size();x++)
		{
			int pos=min(x,(int)s.size()-x);
			if (s[x]>='a' && s[x]<='z')
			dp[i][0]=min(dp[i][0],pos);
			if (s[x]>='0' && s[x]<='9')
			dp[i][1]=min(dp[i][1],pos);
			if (s[x]=='#' || s[x]=='*' || s[x]=='&')
			dp[i][2]=min(dp[i][2],pos);
		}
	}
	int ans=(1<<25);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			if (i==x)
			continue;
			for (int j=0;j<n;j++)
			{
				if (i==j || x==j)
				continue;
				ans=min(ans,dp[i][0]+dp[x][1]+dp[j][2]);
			}
		}
	}
	cout << ans;
}