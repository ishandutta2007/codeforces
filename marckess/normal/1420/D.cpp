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
int n, k;
ll fac[MX], inv[MX], res;
vi ini;
map<int, int> fin;

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

	cin >> n >> k;

	forn (i, n) {
		int l, r;
		cin >> l >> r;
		ini.pb(l);
		fin[r]++;
	}

	sort(all(ini));

	int i = 0, cn = 0;

	for (auto it : fin) {
		while (i < n && ini[i] <= it.fi) {
			i++;
			cn++;
		}

		for (int j = 1; j <= it.se; j++) {
			(res += comb(it.se, j) * comb(cn - it.se, k - j)) %= mod;
		}

		cn -= it.se;
	}

	cout << res << endl;

	return 0;
}