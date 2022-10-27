#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
            if(s[i] == t[j])
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout <<ans;
	return 0;
}