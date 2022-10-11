#include <iostream>
using namespace std;
string s[2];
int dp[105];
int main()
{
	cin >> s[0] >> s[1];
	for (int i=1;i<=s[0].size();i++)
	{
		int cnt=0;
		dp[i]=dp[i-1];
		for (int x=1;x<=min(3,i);x++)
		{
			cnt+=(s[0][i-x]=='0');
			cnt+=(s[1][i-x]=='0');
			if ((x==2 && cnt>=3) || (x==3 && cnt==6))
			dp[i]=max(dp[i],dp[i-x]+x-1);
		}
	}
	cout << dp[s[0].size()];
}