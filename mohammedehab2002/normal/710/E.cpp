#include <iostream>
using namespace std;
long long dp[10000005];
int main()
{
	int n,x,y;
	cin >> n >> x >> y;
	dp[1]=x;
	for (int i=2;i<=n;i++)
	dp[i]=min(dp[i-1]+x,dp[(i+1)/2]+y+x*(i%2));
	cout << dp[n];
}