#include <bits/stdc++.h>
                  
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <vector <int> > dp(n + 1, vector <int> (3, 1e9));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			dp[i][0] = min(dp[i][0], dp[i - 1][j] + 1);
		}
		if(a[i - 1] == 1|| a[i - 1] == 3)
		{
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		if(a[i - 1] == 2 || a[i - 1] == 3)
		{
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
	return 0;
}