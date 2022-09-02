#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

bool solve() {
	ll a, b, n, s;
	cin >> a >> b >> n >> s;
	if (a * n + b < s) return false;
	if (s % n > b) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		bool res = solve();
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}