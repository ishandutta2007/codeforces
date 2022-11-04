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

const int MX = 300005, mod = 998244353;
ll n, a[MX], b[MX], x[MX], y[MX], z[MX], s, res;
bitset<MX> bs;

ll pot (ll b, int p) {
	ll res = 1;
	b %= mod;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		s += a[i];
	}

	for (int k = s - 1; k >= 0; k--) {
		ll inv = pot(s * (1 - y[k + 1]) + k * (n - 2 + y[k + 1]), mod - 2); 
 		y[k] = k * (n - 1) % mod * inv % mod;
		z[k] = (s * (n - 1) + (s - k) * z[k + 1]) % mod * inv % mod;
		
		if (!inv) {
			z[k - 1] = b[k - 1] = -(s * (n - 1) + (s - k) * z[k + 1]) % mod * pot(k * (n - 1), mod - 2) % mod;
			bs[k] = 1;
			k--;
		}
	}

	b[0] = z[0];
	for (int k = 1; k < s; k++)
		if (!bs[k])
			b[k] = (y[k] * b[k - 1] + z[k]) % mod;

	forn (i, n) res += b[a[i]];
	res %= mod;

	res = (n * res - n * (n - 1) % mod * b[0]) % mod;
	(res *= pot(n * n, mod - 2)) %= mod;

	cout << MOD(res, mod) << endl;

	return 0;
}