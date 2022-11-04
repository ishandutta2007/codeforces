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

const int MX = 200005, mod = 998244353;
int n, k;
ll fac[MX], inv[MX], res;

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
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = i * fac[i - 1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n >> k;

	if (n <= k) {
		cout << 0 << endl;
		return 0;
	}

	if (!k) {
		cout << fac[n] << endl;
		return 0;
	}

	res = pot(n - k, n);
	for (int i = 1, f = -1; i < n - k; i++, f *= -1)
		(res += f * pot(n - k - i, n) * comb(n - k, i) % mod) %= mod;
	cout << MOD(2 * res * comb(n, k), mod) << endl;

	return 0;
}