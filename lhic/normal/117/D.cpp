#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

ll MOD;
ll n;

ll run(ll n, int sh, ll msk, ll k, ll br) {
	if (n <= k) {
		ll en = br & ((1ll << sh) - 1);
		br >>= sh;
		if (en <= msk)
			--br;
		if (br < 0)
			return 0;
		br = min(br, n - 1);
		br %= MOD;
		ll ans = (br + 1) * ((msk + 1) % MOD);
		ans %= MOD;
		ans += ((br * (br + 1) / 2) % MOD) * ((1ll << sh) % MOD);
		ans %= MOD;
		return ans;
	}

	ll r = n / 2;
	ll l = n - r;
	if (l >= k)
		return run(l, sh + 1, msk, k, br);
	else
		return (run(l, sh + 1, msk, l, br) + run(r, sh + 1, msk + (1ll << sh), k - l, br)) % MOD;
}

ll get(ll a, ll b) {
	if (a <= 0 || b <= 0)
		return 0;
	return run(n, 0, 0, a, b);
}

int main() {
	int m;
	scanf("%lld%d%lld", &n, &m, &MOD);
	for (int i = 0; i < m; ++i) {
		ll l, r, u, v;
		scanf("%lld%lld%lld%lld", &l, &r, &u, &v);
		ll ans = get(r, v) - get(l - 1, v) - get(r, u - 1) + get(l - 1, u - 1);
		ans += 2 * MOD;
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}