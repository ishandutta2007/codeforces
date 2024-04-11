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

ll ans[10];

const int MAXN = 120000;
ll go[MAXN];


ll gcd(ll a, ll b) {
	while (b) {
		ll q = a % b;
		a = b;
		b = q;
	}
	return a;
}

ll gcall;
ll gcab, gcac, gcbc;

ll gcnt(int a, int b, int c, int x) {
	if (x == 1) {
		ll ans = go[a];
		ans -= go[gcac];
		ans -= go[gcab];
		ans += go[gcall];
		return ans;
	}
	else if (x == 2) {
		swap(a, b);
		ll ans = go[a];
		ans -= go[gcbc];
		ans -= go[gcab];
		ans += go[gcall];
		return ans;
	}
	else if (x == 4) {
		swap(a, c);
		ll ans = go[a];
		ans -= go[gcac];
		ans -= go[gcbc];
		ans += go[gcall];
		return ans;
	}
	else if (x == 3) {
		return go[gcab] - go[gcall];
	}
	else if (x == 5) {
		swap(b, c);
		return go[gcac] - go[gcall];
	}
	else if (x == 6) {
		swap(a, c);
		return go[gcbc] - go[gcall];
	}
	else if (x == 7) {
		return go[gcall];
	}
	assert(false);
}


/*
ll get(int a, int b, int c) {
	ll ans = 0;
	int mx = max({a, b, c});
	for (int x = 1; x <= mx; ++x)
		for (int y = x; y <= mx; ++y)
			for (int z = y; z <= mx; ++z) {
				int fl = 0;
				vector<int> go = {x, y, z};
				do {
					if (a % go[0] == 0 && b % go[1] == 0 && c % go[2] == 0)
						fl = 1;
				} while (!fl && next_permutation(go.begin(), go.end()));
				if (fl)
					++ans;
			}
	return ans;
}*/

vector<int> tmp, p;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 1; i < MAXN; ++i) {
		for (int j = i; j < MAXN; j += i)
			go[j] += 1;
	}
	int tt;
	cin >> tt;
	for (int it = 0; it < tt; ++it) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = 1; i <= 6; ++i)
			ans[i] = 0;
		gcall = gcd(gcd(a, b), c);
		gcab = gcd(a, b);
		gcbc = gcd(b, c);
		gcac = gcd(a, c);
		for (int x = 1; x < 8; ++x) {
			if (((x >> 0) & 1) != 1)
				continue;
			for (int y = 1; y < 8; ++y) {
				if (((y >> 1) & 1) != 1)
					continue;
				for (int z = 1; z < 8; ++z) {
					if (((z >> 2) & 1) != 1)
						continue;
					tmp = {x, y, z};
					p = {0, 1, 2};
					int cnt = 0;
					do {
						int fl = 1;
						for (int j = 0; j < 3; ++j)
							if (!((tmp[j] >> p[j]) & 1))
								fl = 0;
						cnt += fl;
					} while (next_permutation(p.begin(), p.end()));
					ll xc = gcnt(a, b, c, x);
					ll yc = gcnt(a, b, c, y);
					ll zc = gcnt(a, b, c, z);
					ll now = xc * yc * zc;
					if (x == y && x == z) {
						ans[1] += xc;
						ans[1] += xc * (xc - 1);
						now -= xc;
						now -= 3 * xc * (xc - 1);
						ans[cnt] += now;
					}
					else if (x == y) {
						ans[cnt / 2] += xc * zc;
						now -= xc * zc;
						ans[cnt] += now;
					}
					else if (x == z) {
						ans[cnt / 2] += xc * yc;
						now -= xc * yc;
						ans[cnt] += now;
					}
					else if (y == z) {
						ans[cnt / 2] += zc * xc;
						now -= xc * zc;
						ans[cnt] += now;
					}
					else {
						ans[cnt] += now;
					}
				}
			}
		}
		ll gans = 0;
		for (int i = 1; i <= 6; ++i)
			gans += ans[i] / i;
		cout << gans << "\n";
	}
	return 0;
}