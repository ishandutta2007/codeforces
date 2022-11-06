#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <queue>
#define ll long long
#define MAX_INT 922337203685477580LL
using namespace std;

int main() {
	ll a,b;
	set<ll> seen;
	cin >> a;
	cin >> b;
	ll g = abs(a-b);
	if (g == 0) {
		cout << "infinity" << endl;
		return 0;
	}
	ll m = sqrt(g);
	for (ll x = 1; x <= m; x++) {
		if (g % x == 0) {
			ll y = g/x;
			if (x > b) {
				seen.insert(x);
			}
			if (y > b) {
				seen.insert(y);
			}
			// cout << x << ":" << y << endl;
		}
	}
	cout << seen.size() << endl;
	return 0;
}