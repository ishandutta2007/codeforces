#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> as(n), xs(m), dst(n, INF);
	for (ll& a : as) cin >> a;
	for (ll& x : xs) cin >> x;
	sort(xs.begin(), xs.end());

	for (int i = 0, j = -1; i < n; ++i) {
		ll x = 100 * i;
		while(j + 1 < m && xs[j + 1] <= x) ++j;
		if (j >= 0) dst[i] = min(dst[i], x - xs[j]);
		if (j + 1 < m) dst[i] = min(dst[i], xs[j + 1] - x);
	}

	vector<pair<ll, ll>> evs(2*n);
	for (int i = 0; i < n; ++i) {
		ll x = 100 * i;
		evs[2*i] = {x - dst[i], as[i]};
		evs[2*i + 1] = {x + dst[i], -as[i]};
	}
	sort(evs.begin(), evs.end());

	ll res = 0, cur = 0;
	for (auto& pr : evs) {
		cur += pr.second;
		res = max(res, cur);
	}
	cout << res << '\n';
}