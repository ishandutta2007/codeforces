#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<ll> as(n), ts(n, 0);
	for (ll& a : as) cin >> a;
	
	ll sum = 0;
	for (ll a : as) sum += a;

	int prev_t = -1;
	ll prev_v = 0;
	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 1) {
			int i;
			ll x;
			cin >> i >> x;
			--i;

			ll old = (ts[i] <= prev_t ? prev_v : as[i]);
			sum += x - old;
	
			as[i] = x;
			ts[i] = qi;
		} else {
			ll x;
			cin >> x;
			sum = x * n;
			
			prev_t = qi;
			prev_v = x;
		}
		cout << sum << '\n';
	}
}