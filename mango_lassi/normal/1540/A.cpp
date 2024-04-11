#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		vector<ll> vals(n);
		for (ll& v : vals) cin >> v;

		ll res = -vals[0];
		sort(vals.begin(), vals.end());
		res += vals[n-1];

		for (int i = 1; i < n; ++i) vals[i] = vals[i-1] + vals[i];
		for (int i = n-1; i > 0; --i) res += vals[i-1] - i * (vals[i] - vals[i-1]);
		cout << res << '\n';
	}
}