#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vector<ll> xs(n);
	for (ll& x : xs) {
		cin >> x;
		x *= 2;
	}

	vector<ll> ts(n);
	for (ll& t : ts) {
		cin >> t;
		t *= 2;
	}

	ll low = 0;
	ll high = INF;
	ll ans = 0;
	while(low <= high) {
		ll mid = (low + high) >> 1;

		ll min_x = -INF;
		ll max_x = INF;
		for (int i = 0; i < n; ++i) {
			if (mid < ts[i]) {
				min_x = INF;
				max_x = -INF;
			} else {
				min_x = max(min_x, xs[i] - (mid - ts[i]));
				max_x = min(max_x, xs[i] + (mid - ts[i]));
			}
		}

		if (min_x <= max_x) {
			high = mid;
			ans = max_x;

			if (low == high) break;
		} else {
			low = mid + 1;
		}
	}

	if (ans & 1) {
		cout << (ans / 2) << ".5" << '\n';
	} else {
		cout << (ans / 2) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}