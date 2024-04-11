#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e6, mod = 1e9+7;
ll f, w, h;
ll a = 0, b = 0;
ll fac[MX], inv[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}
	return res;
}

void pre () {
	fac[0] = 1;
	inv[0] = 1;

	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
}

ll comb (int n, int k) {
	if (n < k || n < 0 || k < 0) return 0;
	return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

ll solve (ll a, ll b, ll x, ll y) {
	if (x < a || y < b) return 0;
	
	if (!b) {
		if (!y) return comb(x - 1, a - 1);
		return 0;
	}

	if (!a) {
		if (!x) return comb(y - 1, a - 1);
		return 0;
	}

	return comb(x - 1, a - 1) * comb(y - 1, b - 1) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> f >> w >> h;

	for (ll i = 1; i <= max(f, w); i++) {
		b += solve(i, i - 1, f, w);
		b += solve(i, i, f, w);
		b += solve(i, i - 1, w, f);
		b += solve(i, i, w, f);

		a += solve(i, i - 1, f, w - h * (i - 1));
		a += solve(i, i, f, w - h * i);
		a += solve(i, i - 1, w - h * i, f);
		a += solve(i, i, w - h * i, f);

		a %= mod, b %= mod;
	}

	cout << a * pot(b, mod - 2) % mod << endl;

	return 0;
}