#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
#define ll unsigned long long
using namespace std;
ll t[1000];
int main() {
	ll n;
	cin >> n;
	for (ll i = 0; i < 1000; i++) {
		t[i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		ll p = __builtin_popcountll(x);
		t[p] += 1;
	}
	ll ans = 0;
	for (ll i = 0; i < 1000; i++) {
		ans += (t[i]*(t[i]-1))/2;
	}
	cout << ans << endl;
}