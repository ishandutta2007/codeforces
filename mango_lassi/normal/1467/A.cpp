#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		if (i < 2) {
			cout << "98"[i];
		} else {
			int d = (i + 7) % 10;
			cout << d;
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}