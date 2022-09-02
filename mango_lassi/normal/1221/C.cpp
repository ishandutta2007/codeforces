#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	ll c, m, x;
	cin >> c >> m >> x;
	ll res = min(min(c, m), (c + m + x) / 3);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}