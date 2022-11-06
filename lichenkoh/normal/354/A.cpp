#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	ll n,l,r,ql,qr;
	cin >> n; cin >> l; cin >> r; cin >> ql; cin >> qr;
	ll *a = new ll[n+1];
	a[0] = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++) {
		a[i] += a[i-1];
	}
	ll minans = -1;
	for (ll numr = 0; numr <= n; numr++) {
		ll numl = n - numr;
		ll addcost = 0;
		if (numr >= numl) {
			addcost = (numr - numl - 1)*qr;
		}
		else {
			addcost = (numl - numr - 1)*ql;
		}
		addcost = max(0LL, addcost);
		ll ans = 0;
		ans = a[numl] * l + (a[n] - a[numl]) * r;
		//cout << ans << ":" << addcost << endl;
		ans += addcost;
		if (minans == -1) {
			minans = ans;
		}
		else {
			minans = min(minans,ans);
		}
		//cout << "minans:" << ans << endl;
	}
	cout << minans << endl;
	return 0;
}