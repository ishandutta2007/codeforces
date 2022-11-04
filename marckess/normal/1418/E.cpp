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

const int MX = 200005, mod = 998244353;
int n, m;
ll s[MX], tot, d[MX], fac[MX], inv[MX];

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
		fac[i] = i * fac[i - 1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n >> m;

	forn (i, n) cin >> d[i];

	sort(d, d + n);

	forn (i, n) {
		(tot += d[i]) %= mod;
		s[i] = d[i];
		if (i) (s[i] += s[i - 1]) %= mod;
	}

	while (m--) {
		ll a, b;
		cin >> a >> b;

		int j = lower_bound(d, d + n, b) - d;

		ll izq = j ? s[j - 1] : 0;
		ll der = tot - izq;
		ll cn = n - j;
		ll res = 0;

		if (cn < a) {
			cout << 0 << endl;
			continue;
		} 

		(res += der * (cn - a) % mod * pot(cn, mod - 2)) %= mod;
		(res += izq * (cn - a + 1) % mod * pot(cn + 1, mod - 2)) %= mod;

		cout << MOD(res, mod) << endl;
	}

	return 0;
}