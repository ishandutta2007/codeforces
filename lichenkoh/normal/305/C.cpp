#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define ll unsigned long long
unordered_map <ll,ll> h;
void inc(ll i) {
	if (h.find(i) == h.end()) {
		h[i] = 1;
	}
	else {
		h[i]++;
		if (h[i] == 2) {
			h[i] = 0;
			inc(i+1);
		}
	}
}
int main() {
	ll n;
	cin >> n;
	//ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		inc(x);
	}
	ll maxp = 0;
	ll have = 0;
	for (unordered_map <ll,ll>::iterator it = h.begin(); it != h.end(); ++it) {
		ll key = it->first;
		ll val = it->second;
		//cout << key << ":" << val << ":" << maxp << endl;
		if (val == 1) {
			have++;
			maxp = max(maxp,key);
		}
	}
	ll ans = maxp+1-have;
	cout << ans << endl;
	return 0;
}