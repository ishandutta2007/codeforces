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
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353;
int n, m;
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

ll comb (int n, int k) {
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
	if (n == 2) cout << 0 << endl;
	else cout << comb(m, n - 1) * (n - 2) % mod * pot(2, n - 3) % mod << endl;

	return 0;
}