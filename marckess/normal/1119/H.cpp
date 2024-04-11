#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 998244353;
int n, k, a[MX], b[MX], c[MX], acu, f[4][MX], res[MX];
ll inv2, x, y, z;

ll pot (ll b, int p) {
	ll res = 1;
	b %= mod;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void fwht (int *a, int n, int f = 0) {
	for (int len = 2; len <= n; len *= 2)
		for (int k = 0; k < n; k += len)
			for (int i = k, j = k + len / 2; j < k + len; i++, j++)
				if (f) {
					int x = a[i], y = a[j];
					a[i] = ll(x + y) * inv2 % mod;
					a[j] = ll(x - y + mod) * inv2 % mod;
				} else {
					int x = a[i], y = a[j];
					a[i] = (x + y) % mod;
					a[j] = (x - y + mod) % mod;
				}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	inv2 = pot(2, mod - 2);

	cin >> n >> k >> x >> y >> z;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		
		f[0][0]++;
		f[1][a[i] ^ b[i]]++;
		f[2][a[i] ^ c[i]]++;
		f[3][b[i] ^ c[i]]++;
		acu ^= a[i];
	}

	fwht(f[0], 1 << k), fwht(f[1], 1 << k), fwht(f[2], 1 << k), fwht(f[3], 1 << k);

	for (int i = 0; i < (1 << k); i++) {
		int p1 = MOD((1ll * f[0][i] + f[1][i] + f[2][i] + f[3][i]) % mod * inv2 % mod * inv2, mod);
		int p2 = MOD((1ll * f[0][i] + f[1][i] - f[2][i] - f[3][i]) % mod * inv2 % mod * inv2, mod);
		int p3 = MOD((1ll * f[0][i] - f[1][i] + f[2][i] - f[3][i]) % mod * inv2 % mod * inv2, mod);
		int p4 = MOD((1ll * f[0][i] - f[1][i] - f[2][i] + f[3][i]) % mod * inv2 % mod * inv2, mod);

		res[i] = MOD(pot(x + y + z, p1) * pot(x + y - z, p2) % mod * pot(x - y + z, p3) % mod * pot(x - y - z, p4), mod);
	}

	fwht(res, 1 << k, 1);

	for (int i = 0; i < (1 << k); i++)
		cout << res[i ^ acu] << " ";
	cout << endl;

	return 0;
}