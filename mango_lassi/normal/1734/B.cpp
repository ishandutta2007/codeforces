#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 7;

void solve() {
	int n;
	cin >> n;

	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= y; ++x) {
			cout << (x == 1 || x == y) << ' ';
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