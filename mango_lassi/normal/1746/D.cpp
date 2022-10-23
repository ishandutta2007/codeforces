#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> dfs(int i, int p, ll k, const vector<ll>& ss, const vector<vector<int>>& g) {
	int ch = (int)g[i].size() - (p != -1);
	if (ch == 0) {
		return {k * ss[i], (k + 1) * ss[i]};
	} else {
		ll ch_k = k / ch;
		ll base_k = ch_k * ch;

		ll base = 0;
		vector<ll> diffs;

		for (int t : g[i]) {
			if (t == p) continue;

			auto sub = dfs(t, i, ch_k, ss, g);
			base += sub.first;
			diffs.push_back(sub.second - sub.first);
		}
		sort(diffs.rbegin(), diffs.rend());
		
		ll res0 = base + k * ss[i];
		for (int j = 0; j < k - base_k; ++j) res0 += diffs[j];
		ll res1 = res0 + ss[i] + diffs[k - base_k];

		return {res0, res1};
	}
}

void solve() {
	int n;
	ll k;
	cin >> n >> k;

	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;

		g[i].push_back(p);
		g[p].push_back(i);
	}

	vector<ll> ss(n);
	for (ll& s : ss) cin >> s;

	ll res = dfs(0, -1, k, ss, g).first;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}