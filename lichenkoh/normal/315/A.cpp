#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	ll n;
	cin >> n;
	bool *okay = new bool[n+1];
	ll *a = new ll[n+1];
	ll *b = new ll[n+1];
	for (ll i = 0; i <= n; i++) {
		okay[i] = false;
	}
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i != j && a[j] == b[i]) {
				okay[j] = true;
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (okay[i] == false) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}