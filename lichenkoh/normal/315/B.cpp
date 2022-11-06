#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	ll n,m;
	cin >> n;
	cin >> m;
	ll *a = new ll[n+1];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll off = 0;
	for (ll j = 0; j < m; j++) {
		ll t;
		cin >> t;
		if (t==1) {
			ll v,x;
			cin >> v;
			cin >> x;
			a[v] = x-off;
		}
		else if (t==2) {
			ll y;
			cin >> y;
			off += y;
		}
		else if (t==3) {
			ll q;
			cin >> q;
			//cout << "DEBUG: " << a[q] << endl;
			cout << (a[q]+off) << endl;
		}
	}
	return 0;
}