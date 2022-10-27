#include <bits/stdc++.h>
 
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int d, m;
		cin >> d >> m;
		int t = log2(d) + 1;
		vector <int> dp(t);
		int ans = 0;
		for(int j = 0; j < t; j++)
		{
			if((1 << j) > d)
			{
				continue;
			}
			int cnt = d - (1 << j) + 1;
			int cnt2 = (1 << (j + 1)) - (1 << j);
			for(int k = 0; k < j; k++)
			{
				dp[j] = dp[j] + min(cnt, cnt2) * dp[k] % m;
				if(dp[j] >= m)
				{
					dp[j] -= m;
				}
			}
				dp[j] += min(cnt, cnt2) % m;
				if(dp[j] >= m)
				{
					dp[j] -= m;
				}
			ans += dp[j];
			if(ans >= m)
			{
				ans -= m;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}