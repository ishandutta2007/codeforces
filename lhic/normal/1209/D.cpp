#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 1e5 + 100;

int n, k;

int sz[N];
int p[N];

int get(int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = get(p[x]);
}

void un(int x, int y) {
	x = get(x), y = get(y);
	if (x == y)
		return;
	if (sz[x] > sz[y]) {
		swap(x, y);
	}
	sz[y] += sz[x];
	p[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		sz[i] = 1, p[i] = i;
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		un(x, y);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] == i) {
			ans += sz[i] - 1;
		}
	}
	cout << k - ans << "\n";
	return 0;
}