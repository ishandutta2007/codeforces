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

int n;
string a, b;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	cin >> a >> b;
	int ans = 0;
	int i = 0;
	while (i < n) {
		if (a[i] == b[i]) {
			i += 1;
			continue;
		}
		if (i + 1 < n && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
			ans += 1;
			i += 2;
			continue;
		}
		ans += 1;
		i += 1;
	}
	cout << ans << "\n";
	return 0;
}