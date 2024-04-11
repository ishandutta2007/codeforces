#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// Best value for NONZERO AMOUNT OF LEAVES taken from the subtree
pair<ll, int> solve(int i, int p, int pen, const vector<vector<int>>& g) {
	pair<ll, int> res = {-INF, 0};
	for (int t : g[i]) {
		if (t == p) continue;
		auto sub = solve(t, i, pen, g);
		if (res.first < 0) res = max(res, sub);
		else if (sub.first >= 0) {
			res.first += sub.first;
			res.second += sub.second;
		}
	}
	if (res.first == -INF) {
		// Leaf
		return {1 - pen, 1};
	} else {
		++res.first;
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int lc = 0;
	for (int i = 1; i < n; ++i) {
		if (g[i].size() == 1) ++lc;
	}
	if (lc <= k) {
		// Color all leaves, otherwise blue does
		ll res = -INF;
		for (int j = lc; j <= k; ++j) res = max(res, (ll)(n-j) * j);
		cout << res << '\n';
	} else {
		// Aliens trick
		int low = 0;
		int high = n;

		while(low != high) {
			int mid = (low + high + 1) >> 1;
			auto res = solve(0, -1, mid, g);
			if (res.second < k) high = mid - 1;
			else low = mid;
		}

		auto sub = solve(0, -1, low, g);
		ll red = k;
		ll white = sub.first + k * low - k;
		ll mx_blue = n - red - white;
		
		ll res = INF;
		for (ll b = 0; b <= mx_blue; ++b) {
			res = min(res, (white + mx_blue - b) * (red - b));
		}
		cout << res << '\n';
	}
}