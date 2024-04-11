#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

ll get(int h, int n, vector <int>& p) {
	vector <vector <ll>> dp(n, vector <ll>(2));
	dp[0] = { 0, (ll)1e9 };
	for (int i = 1; i < n; i++) {
		int x1 = p[i - 1], x2 = p[i];
		if (x1 - x2 == 1) {
			dp[i][0] = min(dp[i - 1][0] + 1LL, dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0];
			continue;
		}
		if (x1 - x2 == 2) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1LL) + 1LL;
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 1LL);
			continue;
		}
		dp[i][0] = min(dp[i - 1][0] + 1LL, dp[i - 1][1] + 2LL);
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 1LL);
	}
	int x = p[n - 1];
	if (x == 1)
		return min(dp[n - 1][0], dp[n - 1][1]);
	else
		return min(dp[n - 1][0], dp[n - 1][1] + 1LL);
}

ll run() {
	int h, n;
	cin >> h >> n;
	vector <int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	return get(h, n, p);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		cout << run() << '\n';
	return 0;
}