#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e6;
bitset<N> dp[4];
bitset<N> block[2];

void solve() {
	ll n;
	int m;
	cin >> n >> m;

	vector<pair<ll, int>> pts(m+4);
	for (int i = 0; i < m; ++i) {
		ll x;
		int y;
		cin >> y >> x;
		++x;
		pts[i] = {x, y};
	}
	pts[m] = {1ll, 1};
	pts[m+1] = {1ll, 2};
	pts[m+2] = {n+2, 1};
	pts[m+3] = {n+2, 2};
	sort(pts.begin(), pts.end());

	ll sub = 0;
	for (int i = 1; i < pts.size(); ++i) {
		pts[i].first -= sub;
		ll diff = pts[i].first - pts[i-1].first;
		if (diff >= 4) {
			ll add = (diff - 2) - (diff & 1);
			pts[i].first -= add;
			sub += add;
		}
	}

	n = pts.back().first;
	for (int x = 0; x <= n; ++x) {
		block[0][x] = 0;
		block[1][x] = 0;
		for (int j = 0; j < 4; ++j) dp[j][x] = 0;
	}

	dp[3][0] = 1;
	for (auto pr : pts) {
		block[pr.second - 1][pr.first] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		int k = (((int)block[0][i]) | (2 * (int)block[1][i]));
		for (int s = 0; s < 4; ++s) {
			if (! dp[s][i-1]) continue;
			for (int t = 0; t < 4; ++t) {
				if ((t & k) != k) continue;
				if (t == 3 && s == 3 && k == 0) dp[t][i] = 1;
				else if ((t ^ k ^ s) == 3) dp[t][i] = 1;
				else dp[t][i] = 0;
			}
		}
		// for (int t = 0; t < 4; ++t) cerr << dp[i][t]; cerr << '\n';
	}
	if (dp[3][n]) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}