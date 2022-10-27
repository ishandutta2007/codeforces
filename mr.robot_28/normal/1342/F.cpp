#include<bits/stdc++.h>
using namespace std;

signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int dp[n + 1][1 << n][n + 1];
		pair <int, int> pred[n + 1][1 << n][n + 1];
		int sum[1 << n];
		for(int mask = 0; mask < (1 << n); mask++)
		{
			sum[mask] = 0;
			for(int j = 0; j < n; j++)
			{
				if((1 << j) & mask)
				{
					sum[mask] += a[j];
				}
			}
		}
		for(int i = 0; i < n + 1; i++)
		{
			for(int j = 0; j < (1 << n); j++)
			{
				for(int k = 0; k < n + 1; k++)
				{
					dp[i][j][k] = 1e9;
				}
			}
		}
		dp[0][0][0] = 0;
		for(int mask = 0; mask < (1 << n) - 1; mask++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(dp[i][mask][j] == 1e9)
					{
						continue;
					}
					int xormask = ((1 << n) - 1) ^ mask;
					for(int mask1 = xormask; mask1 > 0; mask1 = (mask1 - 1) & xormask)
					{
						if((mask1 >> j) == 0 || sum[mask1] <= dp[i][mask][j])
						{
							continue;
						}
						int to = j + __builtin_ctz(mask1 >> j) + 1;
						if(sum[mask1] < dp[i + 1][mask | mask1][to])
						{
							dp[i + 1][mask | mask1][to] = sum[mask1];
							pred[i + 1][mask | mask1][to] = {mask1, j}; 
						}
					}
				}
			}
		}
		int anslen, anspos;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(dp[i][(1 << n) - 1][j] < 1e9)
				{
					anslen = i;
					anspos = j;
				}
			}
		}
		int stmask = (1 << n) - 1;
		vector <pair <int, int> > ans;
		while(anslen > 0)
		{
			int tomask = pred[anslen][stmask][anspos].first ^ stmask;
			int topos = pred[anslen][stmask][anspos].second;
			for(int j = n - 1; j >= 0; j--)
			{
				if(((1 << j) & pred[anslen][stmask][anspos].first) && j + 1 != anspos)
				{
					ans.push_back({j + 1, anspos});
				}
			}
			anslen--;
			stmask = tomask;
			anspos = topos;
		}
		cout << ans.size() << "\n";
		vector <int> inc(n + 1);
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].first - inc[ans[i].first] << " " << ans[i].second - inc[ans[i].second] << "\n";
			for(int j = ans[i].first; j <= n; j++)
			{
				inc[j]++;
			}
		}
	}
	return 0;
}