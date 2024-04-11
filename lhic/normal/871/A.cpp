#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		if (n % 4 == 0) {
			cout << n / 4 << "\n";
		}
		else if (n % 2 == 0) {
			if (n == 2)
				cout << -1 << "\n";
			else
				cout << n / 4 << "\n";
		}
		else {
			if (n < 9 || n == 11)
				cout << -1 << "\n";
			else {
				cout << 1 + (n - 9) / 4 << "\n";
			}
		}
	}
	return 0;
}