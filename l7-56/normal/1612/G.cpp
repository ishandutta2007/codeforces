#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll maxm = 5e5 + 10, maxn = 2e6 + 10, p = 1e6, mod = 1e9 + 7;
ll m,c[maxm],d[maxn],cnt[2],fact[maxm],mxc,nw;

int main() {
	scanf("%lld", &m);
	for(int i = 1; i <= m; ++i) scanf("%lld", &c[i]), mxc = max(mxc, c[i]);
	sort(c + 1, c + m + 1, greater <ll> ());
	
	nw = mxc;
	for(int i = 1; i <= m; ++i) {
		while(nw > c[i] - 1) d[nw + p] = d[-nw + p] = cnt[nw & 1], nw--;
		cnt[nw & 1]++;
	}
	while(nw >= 0) d[nw + p] = d[-nw + p] = cnt[nw & 1], nw--;
	
	fact[0] = 1;
	for(ll i = 1; i <= m; ++i) fact[i] = (fact[i - 1] * i) % mod;
	
	ll ans1 = 0, ans2 = 1;
	for(ll i = -mxc + p, x = 1; i <= mxc + p; x += d[i++]) {
//		if(d[i]) printf("%lld %lld\n", i - p, d[i]);
		ans1 = (ans1 + (2 * x + d[i] - 1)  * d[i] / 2 % mod * (i - p) % mod) % mod;
		ans2 = (ans2 * fact[d[i]]) % mod;
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}