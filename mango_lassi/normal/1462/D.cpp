#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int sum = 0;
	vector<int> as(n);
	for (int& a : as) {
		cin >> a;
		sum += a;
	}
	for (int d = n; d >= 1; --d) {
		if ((sum % d) != 0) continue;
		int t = sum / d;

		int cur = 0;
		bool fail = 0;
		for (int i = 0; i < n; ++i) {
			if (as[i] + cur > t) fail = 1;
			else if (as[i] + cur < t) cur += as[i];
			else cur = 0;
		}
		if (cur != 0) fail = 1;
		if (! fail) {
			cout << n-d << '\n';
			break;
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