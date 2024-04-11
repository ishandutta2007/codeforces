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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 3605, mod = 998244353;
ll comb[MX][MX], dpf[MX][MX], dpc[MX][MX], fil[MX], col[MX], fac[MX], res;
int n, m, kk, nc, nf;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> kk;
	while (kk--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		fil[a] = fil[c] = 1;
		col[b] = col[d] = 1;

		nf += 1 + (a != c);
		nc += 1 + (b != d);
	}

	for (int i = 0; i < MX; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
			if (comb[i][j] >= mod) comb[i][j] -= mod;
		}
		if (i) fac[i] = i * fac[i-1] % mod;
		else fac[i] = 1;
	}

	dpf[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= (i >> 1); j++) {
			dpf[i][j] = dpf[i-1][j];
			if (i > 1 && !fil[i] && !fil[i-1]) {
				dpf[i][j] += dpf[i-2][j-1];
				if (dpf[i][j] >= mod) dpf[i][j] -= mod;
			}
		}

	dpc[0][0] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= (i >> 1); j++) {
			dpc[i][j] = dpc[i-1][j];
			if (i > 1 && !col[i] && !col[i-1]) {
				dpc[i][j] += dpc[i-2][j-1];
				if (dpc[i][j] >= mod) dpc[i][j] -= mod;
			}
		}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (2 * i + j <= n - nf && i + 2 * j <= m - nc)
				(res += dpf[n][i] * dpc[m][j] % mod 
					  * comb[n - nf - 2 * i][j] % mod
					  * comb[m - nc - 2 * j][i] % mod
					  * fac[i] % mod 
					  * fac[j]) %= mod;

	cout << res << endl;

	return 0;
}