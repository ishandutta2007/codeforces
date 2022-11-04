#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = (1 << 16) + 5, LG = 17, mod = 998244353, inv2 = (mod + 1) / 2;
int n, k, c, a[MX], p[LG][LG][MX], aux[LG][LG][MX];
ll fac[MX], inv[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void ft (int *a, int n, int inv = 0) {
	for (int len = 2; len <= n; len *= 2)
		for (int k = 0; k < n; k += len)
			for (int i = k, j = k + len / 2; j < k + len; i++, j++)
				if (inv) {
					int x = a[i], y = a[j];
					a[i] = ll(x + y) * inv2 % mod;
					a[j] = ll(x - y + mod) * inv2 % mod;
				} else {
					int x = a[i], y = a[j];
					a[i] = (x + y) % mod;
					a[j] = (x - y + mod) % mod;
				}
}

void sum (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void solve (int i, int j, int lvl) {
	if (i + k > j) {
		p[lvl][0][i] = 1;
		ft(p[lvl][0] + i, j - i + 1, 0);
		return;
	}
	
	int m = (i + j) / 2;
	solve(i, m, lvl + 1);
	solve(m + 1, j, lvl + 1);
	
	int pre = i, cn = 0;
	
	for (int l = i; l <= j; l++) {
		pre &= l;
		if (a[l] && m + 1 + k <= l)
			cn++;
	}
	
	forn (x, k + 1) forn (y, k + 1 - x) {
		int f = cn & 1;
		
		forn (l, j - m) {
			int in = f ? m + 1 + l : i + l;
			sum(p[lvl][x + y][in], 1ll * p[lvl + 1][x][i + l] * p[lvl + 1][y][m + 1 + l] % mod);
		}
	}
	
	forn (x, k + 1) {
		ft(p[lvl][x] + i, j - m, 1);
		ft(p[lvl][x] + m + 1, j - m, 1);
	}
	
	for (int l = max(i + k, m + 1); l <= min(j, m + k); l++) if (a[l]) {
		for (int x = k; x >= 0; x--) {
			for (int y = x + 1; y <= k; y++) {
				int f = l - (y - x);
				for (int z = i; z <= j; z++)
					sum(p[lvl][y][pre | (z ^ f)], inv[y - x] * p[lvl][x][z] % mod);
			}
			
			forn (b, LG) if (l & (1 << b) & ~pre)
				for (int l = i; l <= j; l++) {
					int z = pre | (l ^ (1 << b));
					if (l < z)
						swap(p[lvl][x][l], p[lvl][x][z]);
				}
		}
	}
	
	forn (x, k + 1) ft(p[lvl][x] + i, j - i + 1, 0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < LG; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
 	
 	cin >> n >> k >> c;
 	
 	forn (i, n) {
 		int in;
 		cin >> in;
 		a[in] = 1;
 	}
 	
 	solve(0, (1 << c) - 1, 0);
 	
 	ft(p[0][k], 1 << c, 1);
 	
 	ll f = pot(n, k);
 	f = pot(f, mod - 2);
 	(f *= fac[k]) %= mod;
 	
 	forn (i, 1 << c)
 		cout << f * p[0][k][i] % mod << " ";
 	cout << endl;

	return 0;
}