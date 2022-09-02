#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	ll res = 0;
	for (int d = 0; d <= 1; ++d) {
		ll delta = 0, cur_max = 0;
		for (int i = d; i+1 < n; i += 2) {
			delta += (d ? -1 : 1) * (vals[i] - vals[i+1]);
			cur_max = max(cur_max, delta);
			res = max(res, cur_max - delta);
		}
	}
	for (int i = 0; i < n; i += 2) res += vals[i];
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}