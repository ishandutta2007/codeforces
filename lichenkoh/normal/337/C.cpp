#include <iostream>
#include <assert.h>
#define ll long long
#define MOD 1000000009
using namespace std;
ll modexp(ll x,ll e) {
	assert (e >= 0);
	if (e == 0) {
		return 1;
	}
	if (e % 2 == 0) {
		ll tmp = modexp(x,e/2);
		return (tmp*tmp) % MOD;
	}
	else {
		return (modexp(x,e-1) * x) % MOD;
	}
}


int main() {
	ll n,m,k;
	cin >> n;
	cin >> m;
	cin >> k;
	ll z = (n-m);
	ll r = m - z * (k-1);
	if (r <= 0) {
		cout << m % MOD << endl;
		return 0;
	}
	ll t = (r/k) % MOD;
	ll x = (r % k) % MOD;
	ll twot = modexp(2,t);
	ll ans = (x)%MOD + ((2*(twot - 1))%MOD * k)%MOD;
	//cout << t << endl;
	//cout << (x)%MOD << endl;
	//cout << ((2*(twot - 1))%MOD)%MOD << endl;
	//cout << ans << endl;
	cout << (ans+ z*(k-1))%MOD << endl;
}