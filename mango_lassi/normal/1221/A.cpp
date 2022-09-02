#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		if (v <= 2048) sum += v;
	}
	if (sum >= 2048) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}