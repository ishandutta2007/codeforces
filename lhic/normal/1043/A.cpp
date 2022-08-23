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
int a[120];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	int lb = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i], lb = max(lb, a[i]);
	int rb = 300;
	lb -= 1;
	while (rb - lb > 1) {
		int mid = (lb + rb) >> 1;
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; ++i)
			x += a[i], y += mid - a[i];
		if (x >= y)
			lb = mid;
		else
			rb = mid;
	}
	cout << rb << "\n";
	return 0;
}