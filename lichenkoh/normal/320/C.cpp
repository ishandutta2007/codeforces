#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
#define MOD 1000000007
ll modexp(ll x) {
	if (x == 0) {
		return 1;
	}
	if (x % 2 == 0) {
		ll tmp = modexp(x/2);
		return (tmp*tmp) % MOD;
	}
	else {
		return (2*modexp(x-1)) % MOD;
	}
}
int main() {
	string s;
	cin >> s;
	ll n = s.length();
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '1') {
			ll d = n-1-i;
			ans = (ans + modexp(i+2*d)) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}