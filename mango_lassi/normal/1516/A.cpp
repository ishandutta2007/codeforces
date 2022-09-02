#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll k;
	cin >> n >> k;

	ll cur = k;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		if (i == n-1) cout << v + (k - cur) << '\n';
		else {
			ll add = min(v, cur);
			cur -= add;
			cout << v - add << ' ';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}