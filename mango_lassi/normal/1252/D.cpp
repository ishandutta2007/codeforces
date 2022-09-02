#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	int p = 0;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		ll b;
		cin >> b;
		as[i] -= b;

		if (as[i] > 0) res += 3;
		if (as[i] != p) ++res;
		p = as[i];
	}
	if (p != 0) ++res;

	if (res > 2) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}