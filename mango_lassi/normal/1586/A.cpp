#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int sum = 0;
	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		sum += as[i];
	}

	bool is_prime = 1;
	for (int j = 2; j < sum; ++j) {
		if (sum % j == 0) is_prime = 0;
	}

	if (is_prime) {
		cout << n - 1 << '\n';

		bool found = 0;
		for (int j = 0; j < n; ++j) {
			if ((as[j] & 1) && (! found)) {
				found = 1;
			} else {
				cout << j + 1 << ' ';
			}
		}
		cout << '\n';
	} else {
		cout << n << '\n';
		for (int i = 1; i <= n; ++i) cout << i << ' '; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}