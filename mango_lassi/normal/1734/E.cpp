#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 7;

void solve() {
	int n;
	cin >> n;

	vector<int> bs(n);
	for (int& b : bs) cin >> b;

	for (int y = 0; y < n; ++y) {
		ll base = (ll)y * y % n;
		ll diff = (bs[y] + n - base) % n;
		for (int x = 0; x < n; ++x) {
			ll val = (ll)y * x % n;
			ll act = (val + diff) % n;
			cout << act << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}