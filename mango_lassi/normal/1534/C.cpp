#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vector<int> arr0(n), arr1(n);
	vector<int> pos0(n), pos1(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr0[i];
		--arr0[i];
		pos0[arr0[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i];
		--arr1[i];
		pos1[arr1[i]] = i;
	}

	ll res = 1;
	vector<bool> seen(n, 0);
	for (int i = 0; i < n; ++i) {
		if (seen[i]) continue;
		if (pos1[arr0[i]] == i) continue;

		int j = i;
		do {

			j = pos1[arr0[j]];
			seen[j] = 1;

		} while (j != i);

		res = (2 * res) % MOD;
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