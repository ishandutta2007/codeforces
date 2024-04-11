#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	ll m,x,y;
	cin >> m;
	ll *c = new ll[m+1];
	c[0] = 0;
	for (ll i = 1; i <= m;i++) {
		cin >> c[i];
	}
	for (ll i = 1; i <= m; i++) {
		c[i] += c[i-1];
	}
	cin >> x; cin >> y;
	for (ll k = 1; k <= m; k++) {
		//cout << k << ":" << c[k] << endl;
		if (x <= c[k-1] && c[k-1] <= y
		&& x <= (c[m]-c[k-1]) && (c[m]-c[k-1]) <= y) {
			cout << k << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;

}