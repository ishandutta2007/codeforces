#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;

	// Loop mask of who gets more than expected. This gets rid of the absolute value
	vector<ll> xp(n);
	for (ll& x : xp) cin >> x;

	vector<string> solves(n);
	for (int i = 0; i < n; ++i) cin >> solves[i];

	pair<ll, vector<int>> res;
	res.first = -1;
	for (int mask = 0; mask < (1 << n); ++mask) {
		vector<pair<ll, int>> mults(m);
		for (int j = 0; j < m; ++j) {
			mults[j] = {0ll, j};
			for (int i = 0; i < n; ++i) {
				bool s = (solves[i][j] == '1');
				bool b = mask & (1 << i);
				if (s && b) ++mults[j].first;
				else if (s && !b) --mults[j].first;
			}
		}
		sort(mults.begin(), mults.end());

		pair<ll, vector<int>> off = {0ll, vector<int>(m)};
		for (int j = 0; j < m; ++j) off.second[mults[j].second] = j + 1;

		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) off.first -= xp[i];
			else off.first += xp[i];
		}
		for (int i = 0; i < m; ++i) off.first += mults[i].first * (i + 1);
		if (off.first >= res.first) res = off;
	}
	for (int v : res.second) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}