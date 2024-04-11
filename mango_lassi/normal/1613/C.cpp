#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll h;
	cin >> n >> h;
	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll low = 1;
	ll high = h;
	while(low != high) {
		ll mid = (low + high) >> 1;

		ll rem = h - mid;
		for (int i = 1; i < n && rem > 0; ++i) rem -= min(as[i] - as[i-1], mid);
		
		if (rem <= 0) high = mid;
		else low = mid + 1;
	}
	cout << low << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}