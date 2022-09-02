#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	if ((a + b > n-2) || abs(a - b) > 1) {
		cout << -1 << '\n';
	} else {
		int low = 1;
		int high = n;
		bool side = (b > a); // If b > a, we start with 

		if (side) ++a;
		else ++b;

		for (int i = 0; i < n; ++i) {
			if (side) {
				cout << high << ' ';
				--high;
				--a;
			} else {
				cout << low << ' ';
				++low;
				--b;
			}
			if (a + b > 0) side ^= 1;
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}