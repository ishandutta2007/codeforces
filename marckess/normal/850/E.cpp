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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = (1 << 20) + 5, inv2 = 500000004, mod = 1000000007;

void fwt (int *a, int n, int f = 0) { 
	for (int len = 2; len <= n; len *= 2)
		for (int k = 0; k < n; k += len)
			for (int i = k, j = k + len / 2; j < k + len; i++, j++)
				if (f) {
					int x = a[i], y = a[j];
					a[i] = ll(x + y) * inv2 % mod;
					a[j] = ll(x - y + mod) * inv2 % mod;
				} else {
					int x = a[i], y = a[j];
					a[i] = (x + y) % mod;
					a[j] = (x - y + mod) % mod;
				}
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int n, _n, a[MX];
ll res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	_n = n;
	n = 1 << n;

	forn (i, n) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}

	fwt(a, n);
	forn (i, n)
		a[i] = 1ll * a[i] * a[i] % mod;
	fwt(a, n, 1);

	forn (i, n)
		(res += a[i] * pot(2, _n - __builtin_popcount(i))) % mod;
	cout << 3 * res % mod << endl;

	return 0;
}