#include <iostream>
using namespace std;
int dp[105][3];
int main()
{
	string s;
	cin >> s;
	for (int i=1;i<=s.size();i++)
	{
		for (int x=0;x<3;x++)
		dp[i][x]=dp[i-1][x];
		if (s[i-1]=='Q')
		{
			dp[i][0]++;
			dp[i][2]+=dp[i-1][1];
		}
		if (s[i-1]=='A')
		dp[i][1]+=dp[i-1][0];
	}
	cout << dp[s.size()][2];
}