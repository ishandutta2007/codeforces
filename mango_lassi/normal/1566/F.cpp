#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	as.emplace_back(-INF);
	as.emplace_back(INF);
	sort(as.begin(), as.end());
	n += 2;
	
	// Read and remove contained intervals
	vector<pair<ll, ll>> tmp(m);
	for (auto& pr : tmp) {
		cin >> pr.first >> pr.second;
		pr.second *= -1;
	}
	sort(tmp.begin(), tmp.end());

	ll min_end = INF;
	vector<pair<ll, ll>> itvs;
	for (int i = m-1; i >= 0; --i) {
		if (-tmp[i].second < min_end) {
			itvs.emplace_back(tmp[i].first, -tmp[i].second);
			min_end = -tmp[i].second;
		}
	}
	reverse(itvs.begin(), itvs.end());
	m = itvs.size();

	// Solve
	array<ll, 2> dp;
	dp[0] = 0;
	dp[1] = 0;

	int j = 0;
	for (int i = 1; i < n; ++i) {
		ll px = as[i - 1];
		ll cx = as[i];
		int t = j;
		while(t < m && itvs[t].second < cx) ++t;

		/*
		cerr << "Intervals in gap " << i-1 << ' ' << i << ": ";
		for (int x = j; x < t; ++x) cerr << "(" << itvs[x].first << ' ' << itvs[x].second << ") ";
		cerr << '\n';
		*/

		array<ll, 2> nxt;
		nxt[0] = INF;
		nxt[1] = INF;
		for (int x = j; x <= t; ++x) {
			// LEFT takes [j, x), RIGHT takes [x, t)
			ll ld = (x == j ? 0 : itvs[x-1].first - px);
			ll rd = (x == t ? 0 : cx - itvs[x].second);

			ll add = min(dp[0] + ld, dp[1] + 2*ld);
			nxt[0] = min(nxt[0], 2*rd + add);
			nxt[1] = min(nxt[1], rd + add);
			// cerr << i << ' ' << x << ": " << ld << ' ' << rd << " offers " << 2*rd + add << " and " << rd + add << '\n';
		}
		dp = nxt;

		j = t;
		while(j < m && itvs[j].first <= cx) ++j;
	}
	cout << min(dp[0], dp[1]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}