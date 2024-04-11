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


ll MOD;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

int gcnt;

int cc;
void sum(int x, int y, int xy) {
	++gcnt;
	cout << "+ " << x << " " << y << " " << xy << "\n";
}

void puf(int x, int y) {
	++gcnt;
	cout << "^ " << x << " " << y << "\n";
}

int d;

int mult(int x, ll c) {
	if (c == 0)
		c = MOD;
	if (c == 1)
		return x;
	int y = mult(x, c / 2);
	sum(y, y, cc);
	y = cc++;
	if (c % 2 == 1)
		sum(x, y, y);
	return y;
}

ll cnk[20][20];

ll a[20][20];
int one;
ll c[20];
int e[20];

int sq(int x) {
	e[0] = x;
	for (int i = 1; i <= d; ++i)
		e[i] = cc++;
	for (int i = 1; i <= d; ++i)
		sum(e[i - 1], one, e[i]);
	for (int i = 0; i <= d; ++i) {
		puf(e[i], e[i]);
		e[i] = mult(e[i], c[i]);
	}
	for (int i = 1; i <= d; ++i)
		sum(e[0], e[i], e[0]);
	return e[0];
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> d >> MOD;
	for (int i = 0; i <= 10; ++i)
		for (int j = 0; j <= 10; ++j) {
			if (i == j || j == 0)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
		}
	int x = 1;
	int y = 2;
	int xy = 3;
	sum(x, y, xy);
	one = 4;
	cc = 5;
	for (int i = 0; i <= d; ++i)
		for (int j = 0; j <= d; ++j) {
			a[i][j] = cnk[d][i] * pw(j, i) % MOD;
		}
	a[d - 2][d + 1] = 1;
	int now = 0;
	for (int i = 0; i <= d; ++i) {
		int fl = 0;
		for (int j = now; j <= d; ++j) {
			if (a[j][i]) {
				for (int k = 0; k <= d + 1; ++k)
					swap(a[now][k], a[j][k]);
				fl = 1;
				break;
			}
		}
		if (!fl)
			assert(false);
		ll x = pw(a[now][i], MOD - 2);
		for (int j = 0; j <= d + 1; ++j)
			a[now][j] = (a[now][j] * x) % MOD;
		for (int j = 0; j <= d; ++j) {
			if (j == now)
				continue;
			ll x = a[j][i];
			for (int k = 0; k <= d + 1; ++k)
				a[j][k] = (a[j][k] - x * a[now][k] % MOD + MOD) % MOD;
		}
		++now;
	}
	for (int i = 0; i <= d; ++i)
		c[i] = a[i][d + 1];
	x = sq(x);
	y = sq(y);
	xy = sq(xy);
	x = mult(x, MOD - 1);
	y = mult(y, MOD - 1);
	sum(x, xy, xy);
	sum(y, xy, xy);
	xy = mult(xy, (MOD + 1) / 2);
	cout << "f " << xy << "\n";
	cerr << gcnt << "\n";
	return 0;
}