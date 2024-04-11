#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		ll s, t;
		cin >> s >> t;
		
		bool fail = 0;
		ll low = 0, high = 0;
		for (ll b = 1; b <= max(s, t); b <<= 1) {
			if (s & b) {
				++high;
				if (low == 0 || (low == 1 && (t & b))) ++low;
			}
			if (t & b) {
				--high;
				low = max(low-1, 0ll);
			}
			if (high < 0) fail = 1;
		}
		if (! fail && low == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}