#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	int le = n, ri = -1;
	for (int i = 0; i + 1 < n; ++i) {
		if (as[i] == as[i+1]) {
			le = min(le, i + 1);
			ri = max(ri, i);
		}
	}
	if (le > ri) {
		cout << 0 << '\n';
	} else {
		cout << max(1, ri - le) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}