#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll a, b, n, i, l, r, t, m;
	cin >> a >> b >> n;
	for (i = 0; i < n; i++) {
		cin >> l >> t >> m;
		if (a + b * (l - 1) > t)
			cout << -1 << '\n';
		else {
			r = 2 + (t - a) / b;
			ll l2 = l, mid;
			while (l2 + 1 < r) {
				mid = (l2 + r) / 2;
				if ((2 * a + (mid + l - 2) * b) * (mid - l + 1) <= 2 * t * m)
					l2 = mid;
				else
					r = mid;
			}
			cout << l2 << '\n';
		}
	}

	return 0;
}