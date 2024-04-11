#include <iostream>
using namespace std;
int dp[5005][3];
int main()
{
	string s;
	cin >> s;
	s+="a";
	for (int i=1;i<=s.size();i++)
	{
		dp[i][0]=dp[i-1][0]+(s[i-1]=='a');
		dp[i][1]=max(dp[i-1][1],dp[i-1][0])+(s[i-1]=='b');
		dp[i][2]=max(max(dp[i-1][2],dp[i-1][1]),dp[i-1][0])+(s[i-1]=='a');
	}
	printf("%d",dp[s.size()][2]-1);
}