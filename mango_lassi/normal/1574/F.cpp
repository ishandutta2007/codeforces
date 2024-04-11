#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> nxt(k, -1), pre(k, -1);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;

		int x;
		cin >> x;
		--x;

		for (int j = 1; j < c; ++j) {
			int y;
			cin >> y;
			--y;

			if (nxt[x] != -1 && nxt[x] != y) nxt[x] = -2;
			else nxt[x] = y;

			if (pre[y] != -1 && pre[y] != x) pre[y] = -2;
			else pre[y] = x;

			x = y;
		}
	}

	vector<bool> seen(k, 0);
	vector<int> counts(k + 1, 0);
	for (int i = 0; i < k; ++i) {
		if (pre[i] == -1) {
			int len = 0;
			bool works = 1;
			for (int x = i; x >= 0 && works; x = nxt[x], ++len) {
				if (pre[x] == -2 || nxt[x] == -2 || seen[x]) works = 0;
				seen[x] = 1;
			}
			if (works) ++counts[len];
		}
	}

	vector<pair<int, int>> prs;
	for (int i = 1; i <= k; ++i) {
		if (counts[i] >= 1) prs.emplace_back(i, counts[i]);
	}

	vector<ll> dp(m+1, 0);
	dp[0] = 1;
	for (int i = 1; i <= m; ++i) {
		for (auto pr : prs) {
			if (pr.first <= i) dp[i] = (dp[i] + dp[i - pr.first] * pr.second) % MOD;
		}
	}
	cout << dp[m] << '\n';
}