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

const int MX = 5005, mod = 1000000007;
int n, k;
ll a[MX], p[MX], res = 1;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	forn (i, n) {
		cin >> a[i];
		(res *= a[i]) %= mod;
	}

	p[0] = 1;

	forn (i, n) {
		for (int j = min(n, k); j; j--)
			p[j] = (p[j] * a[i] - p[j - 1]) % mod;
		(p[0] *= a[i]) %= mod;
	}

	for (ll i = 0, x = 1; i <= min(n, k); i++) {
		(res -= p[i] * x % mod * pot(n, mod - 1 - i)) %= mod;
		(x *= k - i) %= mod;
	}

	cout << MOD(res, mod) << endl;

	return 0;
}