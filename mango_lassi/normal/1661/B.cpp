#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a;
	cin >> a;

	int res = 16;
	for (int j = 0; j < 16; ++j) {
		int full = (1 << j);
		int bits = a & (full - 1);
		int adds = (bits == 0 ? 0 : full - bits);
		int shifts = 15 - j;
		res = min(res, adds + shifts);
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