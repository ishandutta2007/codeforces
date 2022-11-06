#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
ll *t;


int main() {
	ll n;
	cin >> n;
	//t = new ll[n];
	t = new ll[n+1];
	for (ll i = 1; i <= n; i++) {
		cin >> t[i];
	}
	ll m;
	cin >> m;
	ll maxh = t[1];
	for (ll i = 0; i < m; i++) {
		ll wi;
		ll hi;
		cin >> wi;
		cin >> hi;
		maxh = max(maxh,t[wi]);
		cout << maxh << endl;
		maxh += hi;
	}
	return 0;
}