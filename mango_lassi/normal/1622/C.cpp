#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	ll h;
	cin >> n >> h;

	vector<ll> vals(n);
	for (ll& v : vals) cin >> v;
	sort(vals.begin(), vals.end());

	vector<ll> pfs(n + 1, 0);
	for (int i = 0; i < n; ++i) pfs[i + 1] = pfs[i] + vals[i];

	ll res = INF;
	for (int i = n; i > 0; --i) {
		// Minimum number of subtracts to vals[0] before setting (1, i] equal to vals[0] to get sum <= h
		ll mult = 1 + (n-i);
		ll base = pfs[i] + (mult - 1) * vals[0];
		ll subs = max(0ll, (base - h + (mult-1)) / mult);
		res = min(res, mult + subs - 1);
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