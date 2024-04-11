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

const int MX = 200005, mod = 998244353;
int n, k, a[MX], _n;
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
	if (n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = i * fac[i-1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n >> k;
	_n = n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int aux = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != a[(i+1)%n])
			aux++;
	n = aux;

	ll res = pot(k, n);
	for (int i = 0; i <= n / 2; i++) {
		res -= comb(n, i) * comb(n - i, i) % mod * pot(k - 2, n - 2 * i) % mod;
		res %= mod;
	}

	cout << MOD(res * pot(2, mod - 2), mod) * pot(k, _n - n) % mod << endl;

	return 0;
}