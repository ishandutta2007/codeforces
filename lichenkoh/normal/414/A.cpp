#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll m,k;
	cin >> m;
	cin >> k;
	ll p = m / 2;
	if (k < p) {
		cout << -1 << endl;
		return 0;
	}
	if (m < 2) {
		if (k > 0) {
			cout << -1 << endl;
			return 0;
		}
		else {
			cout << 1 << endl;
			return 0;
		}
	}
	ll extra = k-p;
	ll first = extra + 1;
	cout << first << endl;
	cout << 2 * first << endl;
	for (ll i = 1; i <= m-2; i++) {
		cout << (2 * first) + i << endl;
	}
	return 0;
}