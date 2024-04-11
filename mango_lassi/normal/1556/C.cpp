#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = 0;
	for (int i = 0; i < n; i += 2) {
		ll cur = 0, mn = 0;
		for (int j = i + 1; j < n; ++j) {
			if (j % 2 == 0) cur += as[j];
			else {
				ll low_x = max(1ll, -mn);
				ll high_x = as[i];

				ll low_y = max(1ll, cur + low_x);
				ll high_y = min(as[j], cur + high_x);
				
				res += max(0ll, high_y - low_y + 1);

				cur -= as[j];
				mn = min(mn, cur);
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}