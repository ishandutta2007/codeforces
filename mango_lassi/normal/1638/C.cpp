#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int max_v = 0, res = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (max_v == i) ++res;
		max_v = max(max_v, a);
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