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
int a[1200];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < 2 * n; ++i)
		cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		for (int j = i + 1; j < 2 * n; ++j) {
			if (a[j] == a[i]) {
				ans += abs(j - (i + 1));
				rotate(a + i + 1, a + j, a + j + 1);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}