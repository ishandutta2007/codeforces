#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second



int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, d;
	cin >> n >> d;
	
	vector<vector<ld>> dp(10, vector<ld>(n + 1, -1e60));
	vector<vector<int>> h(10, vector<int>(n + 1, -1));

	dp[1][0] = 0;
	vector<int> a;
	for (int i = 0, x; i < n; ++i)
	{
		cin >> x;
		a.push_back(x);
		ld y = logl(x);

		for (int j = 0; j < 10; ++j)
		{
			if (dp[j][i] > dp[j][i + 1])
			{
				dp[j][i + 1] = dp[j][i];
				h[j][i + 1] = -1;
			}
			if (dp[j][i] + y > dp[(j * x) % 10][i + 1])
			{
				dp[(j * x) % 10][i + 1] = dp[j][i] + y;
				h[(j * x) % 10][i + 1] = j;
			}
		}
	}

	if (dp[d][n] <= 0)
	{
		cout << "-1\n";
		return 0;
	}

	vector<int> ans;
	for (int i = n, j = d; i > 0; --i)
	{
		if (h[j][i] != -1)
		{
			ans.push_back(a[i - 1]);
			j = h[j][i];
		}
	}

	cout << ans.size() << "\n";
	for (auto &i : ans)
		cout << i << " \n"[&i==&ans.back()];

	return 0;
}