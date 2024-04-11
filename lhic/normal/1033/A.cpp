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

int get(int x, int y, int a, int b) {
	if (a > x && b > y)
		return 0;
	else if (a > x && b < y)
		return 1;
	else if (a < x && b > y)
		return 2;
	else if (a < x && b < y)
		return 3;
	assert(false);
}

int ax, ay, bx, by, cx, cy;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;
	int x = get(ax, ay, bx, by);
	int y = get(ax, ay, cx, cy);
	if (x == y)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}