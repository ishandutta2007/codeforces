#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;;

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	ll hi = INF;
	ll lo = -INF;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		hi = min(hi, a + k);
		lo = max(lo, a - k);
	}
	if (lo <= hi) cout << hi << '\n';
	else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}