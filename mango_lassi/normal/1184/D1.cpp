#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, m, t;
	cin >> n >> k >> m >> t;
	for (int ti = 0; ti < t; ++ti) {
		int p, x;
		cin >> p >> x;
		if (p == 1) {
			if (x <= k) ++k;
			++n;
		} else if (p == 0) {
			if (x < k) {
				k -= x;
				n -= x;
			} else {
				n = x;
			}
		}
		cout << n << ' ' << k << '\n';
	}
}