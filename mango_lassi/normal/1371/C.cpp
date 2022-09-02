#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	ll v, c, n, m;
	cin >> v >> c >> n >> m;

	// v > c:
	//	(--v, --n), (--c, --m)
	// v <= c:
	//	(--c, --n), (--v, --m)

	// Can only decrement minimum to decrease m

	if (min(v, c) < m || (v + c < n + m)) cout << "No\n";
	else cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}