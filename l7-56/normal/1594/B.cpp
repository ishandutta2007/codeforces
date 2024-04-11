#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const ll mod = 1e9 + 7;
ll t,n,k;

ll f(ll x) {
	return 1ll << x;
}

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
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld", &n, &k);
		ll l = 0, r = 32, mid, ans = -1;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(f(mid) <= k) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		k -= f(ans);
		ll res = pw(n, ans);
		for(int i = 0; i < ans; ++i)
			if(k & (1ll << i)) res = (res + pw(n, i)) % mod;
		printf("%lld\n", res);
	}
	return 0;
}