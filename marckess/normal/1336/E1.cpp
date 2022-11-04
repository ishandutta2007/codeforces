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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 60, mod = 998244353, lim = 12;
int n, m, to, off;
ll res[MX], pos[MX][(1 << lim) + 5], aux[MX];
vi b;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

bool add (vi &b, ll x) {
	for (int i = m - 1; i >= 0; i--)
		if (x & (1ll << i))
			x ^= b[i];
 
	if (!x) return 0;
 
	for (int i = m - 1; i >= 0; i--)
		if (!b[i] && (x & (1ll << i))) {
			b[i] = x;
 
			for (int j = i + 1; i < m; i++)
				if (b[j] & (1ll << i))
					b[j] ^= x;
 
			break;
		}
 
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	b.resize(m);
	off = n;

	forn (i, n) {
		ll a;
		cin >> a;
		off -= add(b, a);
	}

	if (m > lim) {
		int mx = m - lim;

		for (ll i = 0; i < (1 << mx); i++) {
			i <<= lim;

			int f = 1;
			ll mk = 0;
			for (ll j = lim; j < m; j++)
				if (i & (1ll << j)) {
					if (!b[j]) f = 0;
					mk ^= b[j];
				}

			if (!f) {
				i >>= lim;
				continue;
			}

			ll a = mk & ((1ll << lim) - 1);
			ll b = mk ^ a;

			pos[__builtin_popcountll(b)][a]++;
			to = max(to, __builtin_popcountll(b));

			i >>= lim;
		}

	} else {
		pos[0][0] = 1;
	}

	int mx = min(m, lim);
	for (ll i = 0; i < (1ll << mx); i++) {
		ll mk = 0;
		int f = 1;

		for (ll j = 0; j < mx; j++)
			if (i & (1ll << j)) {
				if (!b[j]) f = 0;
				mk ^= b[j];
			}

		if (!f) continue;

		for (ll j = 0; j <= to; j++)
			for (int k = 0; k < (1ll << lim); k++) {
				int p = j + __builtin_popcountll(mk ^ k);
				res[p] += pos[j][k];
				if (res[p] >= mod) res[p] -= mod;
			}
	}

	for (int i = 0; i <= m; i++)
		cout << res[i] * pot(2, off) % mod << " ";
	cout << endl;

	return 0;
}