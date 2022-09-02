#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	if (n % 7 == 0) {
		cout << n << '\n';
	} else {
		int r = n - (n % 10);
		int x = r % 7;
		cout << r + (7-x) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}