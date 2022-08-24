#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

int n;
ll x, y;
string s;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> x >> y;
	cin >> s;
	int cnt = 0;
	int fl = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (!fl)
				++cnt;
			fl = 1;
		}
		else {
			fl = 0;
		}
	}
	if (cnt == 0)
		cout << 0 << "\n";
	else
		cout << (cnt - 1) * min(x, y) + y;
	return 0;
}