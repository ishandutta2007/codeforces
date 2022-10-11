#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, r;
	cin >> n >> r;
	vector<pair<int, int>> good, bad;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (b >= 0)
			good.emplace_back(a, b);
		else
			bad.emplace_back(max(a, -b), -b);
	}

	int ans = 0;
	sort(good.begin(), good.end());
	for (auto [a, b] : good)
		if (r >= a) {
			ans++;
			r += b;
		}

	sort(bad.begin(), bad.end(), [&](pair<int, int> &a, pair<int, int> &b) {
		return a.first - a.second > b.first - b.second;
	});
	n = bad.size();
	vector<int> dp(n + 1, -INF);
	dp[0] = r;
 
	for (int i = 0; i < n; i++) {
		auto [a, b] = bad[i];
		vector<int> ndp = dp;
		for (int cnt = 1; cnt <= i + 1; cnt++)
			if (dp[cnt - 1] >= a && ndp[cnt] < dp[cnt - 1] - b)
				ndp[cnt] = dp[cnt - 1] - b;
 
		dp = ndp;
	}

	for (int i = n; i >= 0; i--)
		if (dp[i] >= 0)
			return cout << i + ans << '\n', 0;
}