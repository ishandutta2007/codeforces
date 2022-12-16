#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

const ll mod = 1e9 + 7;
ll k, ans = 6;
ll pw(ll a, ll p) {
	ll ans = 1;
	while(p) {
		if(p & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		p >>= 1;
	}
	return ans;
}

int main() {
	scanf("%lld", &k);
	printf("%lld", (6 * pw(4, (1ll << k) - 2)) % mod);
	return 0;
}