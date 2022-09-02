#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		ll x;
		cin >> x;
		if (x & 1) cout << 1 << ' ' << x-1 << '\n';
		else cout << x/2 << ' ' << x/2 << '\n';
	}
}