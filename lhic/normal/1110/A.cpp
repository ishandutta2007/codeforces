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

int a[120000];

int b, k;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> b >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	if (b % 2 == 0) {
		if (a[k - 1] % 2 == 0)
			cout << "even\n";
		else
			cout << "odd\n";
	}
	else {
		int now = 0;
		for (int i = 0; i < k; ++i)
			now = (now + a[i]) % 2;
		if (now == 0)
			cout << "even\n";
		else
			cout << "odd\n";
	}
	return 0;
}