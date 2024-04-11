#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 300005, mod = 998244353;
int n, m, l[MX], r[MX], u[22], v[22], cn[MX];
ll fac[MX], inv[MX], res, acu[MX][2][44];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n >> m;

	forn (i, n) {
		cin >> l[i] >> r[i];
		cn[l[i]]++;
		cn[r[i] + 1]--;
	}

	forn (i, m) {
		cin >> u[i] >> v[i];
		u[i]--;
		v[i]--;
	}

	forn (mk, (1 << m)) {
		int mn = 1, mx = n;
		set<int> st;

		forn (j, m) if (mk & (1 << j)) {
			mn = max({mn, l[u[j]], l[v[j]]});
			mx = min({mx, r[u[j]], r[v[j]]});

			st.insert(u[j]);
			st.insert(v[j]);
		}

		if (mn <= mx) {
			int x = __builtin_popcount(mk) & 1, y = st.size();
			acu[mn][x][y]++;
			acu[mx + 1][x][y]--;
		}
	}

	for (int i = 1; i <= n; i++) {
		cn[i] += cn[i - 1];

		for (int j = 0; j <= 40; j++) {
			acu[i][0][j] += acu[i - 1][0][j];
			acu[i][1][j] += acu[i - 1][1][j];

			(res += acu[i][0][j] * comb(cn[i] - j, i - j)) %= mod;
			(res -= acu[i][1][j] * comb(cn[i] - j, i - j)) %= mod;
		}
	}

	cout << MOD(res, mod) << endl;

	return 0;
}