#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
ll makebitmap(ll x) {
	if (x == 0) {
		return 0;
	}
	if (x%10 == 0) {
		return makebitmap(x/10) << 1;
	}
	else {
		return (makebitmap(x/10) << 1)|0x1;
	}
}
int main() {
	ll k;
	cin >> k;
	ll *a = new ll[k];
	ll *b = new ll[k];
	ll *p = new ll[k];
	for (ll i = 0; i < k; i++)
	{
		ll x;
		cin >> x;
		a[i] = x;
		b[i] = makebitmap(x);
		p[i] = __builtin_popcountll(b[i]);
	}
	ll taken = 0;
	vector<ll> ans;
	ll ansn = 0;
	for (ll d = 0; d < 100; d++) {
		for (ll i = 0; i < k; i++) {
			if (p[i] == d) {
				if ((taken & b[i]) == 0) {
					taken |= b[i];
					ans.push_back(a[i]);
					ansn++;
				}
			}
		}

	}
	cout << ansn << endl;
	for (vector<ll>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}