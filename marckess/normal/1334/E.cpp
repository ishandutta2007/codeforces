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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105, mod = 998244353;
ll d, fact[MX], inv[MX];
int q;
vi p;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

vi fac (ll n) {
	vi p;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) {
			p.pb(i);
			while (n % i == 0)
				n /= i;
		}

	if (n > 1) p.pb(n);
	return p;
}

ll f (ll a, ll b) {
	if (a < b) swap(a, b);
	ll n = a / b, res = 1, sum = 0;

	for (ll d : p) {
		ll pw = 0;
		while (n % d == 0) {
			n /= d;
			pw++;
		}
		(res *= inv[pw]) %= mod;
		sum += pw;
	}

	(res *= fact[sum]) %= mod;
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fact[i] = fact[i - 1] * i % mod;
		inv[i] = pot(fact[i], mod - 2);
	}

	cin >> d >> q;

	p = fac(d);

	while (q--) {
		ll u, v;
		cin >> u >> v;
		ll g = __gcd(u, v);
		cout << f(u, g) * f(v, g) % mod << endl;
	}

	return 0;
}