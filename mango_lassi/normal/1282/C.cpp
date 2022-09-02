#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll mint(int as, int bs, ll a, ll b) {
	return as * a + bs * b;
}

void solve() {
	int n;
	ll m, a, b;
	cin >> n >> m >> a >> b;

	vector<pair<ll, int>> evs(n);
	for (int i = 0; i < n; ++i) cin >> evs[i].second;
	for (int i = 0; i < n; ++i) cin >> evs[i].first;
	sort(evs.begin(), evs.end());

	ll must_as = 0;
	ll must_bs = 0;
	ll oth_as = 0;
	ll oth_bs = 0;
	for (auto pr : evs) {
		if (pr.second) ++oth_bs;
		else ++oth_as;
	}
	evs.push_back({m+1, -1});

	ll res = 0;
	for (int j = 0; j <= n; ++j) {
		ll s = evs[j].first - 1;
		ll t = s - (a * must_as + b * must_bs);
		ll off = j;
		
		if (t >= 0) {
			ll x = min(oth_as, t / a);
			ll y = min(oth_bs, (t - x*a) / b);
			off += x + y;
			res = max(res, off);
		}

		if (evs[j].second == 0) {
			++must_as;
			--oth_as;
		} else {
			++must_bs;
			--oth_bs;
		}
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