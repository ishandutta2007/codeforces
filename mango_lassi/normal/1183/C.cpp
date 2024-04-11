#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	ll k, n, a, b;
	cin >> k >> n >> a >> b;
	ll d = k-1 - n*b;
	if (d < 0) cout << -1 << '\n';
	else {
		cout << min(n, d/(a-b)) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}