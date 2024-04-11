#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int l = -1, r = 2e9 + 1;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		vector <int> dp(n, 1e9);
		dp[0] = 0;
		int u = n - 1;
		for(int i = 1; i < n; i++)
		{
			dp[i] = i;
			for(int j = 0; j < i; j++)
			{
				if(midd * (i - j) >= abs(a[i] - a[j]))
				{
					dp[i] = min(dp[i], dp[j] + (i - j) - 1);
				}
			}
			u = min(u, dp[i] + n - 1 - i);
		}
		if(u <= k)
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	cout << r;
	return 0;
}