#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

ll n;

ll ans = 0;

ll get(ll x) {
	ll ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

void run(int x, ll cur) {
	if (x == 13) {
		if (cur <= n)
			ans = max(ans, get(cur) + get(n - cur));
		return;
	}
	run(x + 1, cur * 10);
	run(x + 1, cur * 10 + 9);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	run(0, 0);
	cout << ans << "\n";
	return 0;
}