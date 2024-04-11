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

const int MAXN = 120000;

int n, k;
int a[MAXN];

int run(int l, int r, int lb, int rb, int k) {
	int now = 1;
	--k;
	if (k <= 1) {
		for (int i = 0; i < r - l; ++i)
			a[l + i] = lb + i;
		return now;
	}
	if (l + 1 == r) {
		a[l] = lb;
		return now;
	}
	int m = (l + r) >> 1;
	int x = run(l, m, rb - (m - l), rb, k - 1);
	now += x;
	k -= x;
	now += run(m, r, lb, lb + (r - m), k);
	return now;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	int x = run(0, n, 0, n, k);
	if (x != k) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 0; i < n; ++i)
			cout << a[i] + 1 << " ";
		cout << "\n";
	}
	return 0;
}