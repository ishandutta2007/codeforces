#include <bits/stdc++.h>

using namespace std;
#define int long long
const int CONST = 1e9 + 7;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> dp(n, 0);
	vector <int> dp1(m, 0);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			dp[i] += 2;
		}
		else if(i == 1)
		{
			dp[i] = 2 + dp[i - 1];
		}
		else
		{
			dp[i] = (dp[i] + dp[i - 1] + dp[i - 2]) % CONST;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(i == 0)
		{
			dp1[i] += 2;
		}
		else if(i == 1)
		{
			dp1[i] = 2 + dp1[i - 1];
		}
		else
		{
			dp1[i] = (dp1[i] + dp1[i - 1] + dp1[i - 2]) % CONST;
		}
	}
	cout << (dp[n - 1] + dp1[m - 1] - 2 + CONST) % CONST;
    return 0;
}