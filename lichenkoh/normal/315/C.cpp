#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	ll n,k;
	cin >> n;
	cin >> k;
	ll *a = new ll[n+1];
	ll *t = new ll[n+1];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	t[1] = 0;
	for (ll i = 2; i <= n; i++) {
		t[i] = t[i-1] + (i-2)*a[i-1];
	}
	ll subber = 0;
	ll rmed = 0;
	ll nnew = n;
	for (ll i = 1; i <= n; i++) {
		ll curr = t[i] - subber;
		ll inew = i-rmed;
		ll nnew = n-rmed;
		curr -= (nnew-inew)*(inew-1)*a[i];
		//cout << "Curr:" << curr << " t[i]:" << t[i] << " Subber:" << subber << " adjust:" << (n-inew)*(inew-1)*a[i] << endl;
		subber += a[i] * rmed;
		if (curr < k) {
			// Remove
			subber += (inew-1)*a[i];
			cout << i << endl;
			rmed++;
		}
	}
	return 0;
}