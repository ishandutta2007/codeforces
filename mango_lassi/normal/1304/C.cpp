#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		ll m0, m1;
		cin >> n >> m0;
		m1 = m0;

		ll c = 0;
		bool can = 1;
		for (int i = 0; i < n; ++i) {
			ll nc, low, high;
			cin >> nc >> low >> high;

			m0 -= (nc - c);
			m1 += (nc - c);
			c = nc;

			m0 = max(m0, low);
			m1 = min(m1, high);

			if (m0 > m1) can = 0;
		}
		cout << (can ? "YES" : "NO") << '\n';
	}
	
}