#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<ll> ks(n);
	for (ll& k : ks) cin >> k;
	sort(ks.begin(), ks.end());


	vector<ll> cs(m);
	for (ll& v : cs) cin >> v;
	
	vector<ll> sum_ks(n+1, 0);
	for (int i = 1; i <= n; ++i) sum_ks[i] = sum_ks[i-1] + cs[ks[i-1] - 1];

	vector<ll> sum_cs(m+1, 0);
	for (int i = 1; i <= m; ++i) sum_cs[i] = sum_cs[i-1] + cs[i-1];

	ll max_t = min(m, n);
	for (int j = n-1; j >= 0; --j) max_t = min(max_t, n-1-j + ks[j]);

	ll res = INF;
	for (int t = 0; t <= max_t; ++t) {
		// Use t presents
		ll off = sum_cs[t] + sum_ks[n-t];
		res = min(res, off);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}