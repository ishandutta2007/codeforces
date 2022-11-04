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

const int MX = 2005, mod = 1000000007;
int n, m, a[MX];
ll res;
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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = i * fac[i - 1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	sort(a, a + m);

	res = fac[n - m];
	(res *= inv[a[0] - 1]) %= mod;
	(res *= inv[n - a[m - 1]]) %= mod;

	for (int i = 0; i + 1 < m; i++) {
		int x = a[i + 1] - a[i];
		if (x == 1) continue;

		(res *= inv[x - 1]) %= mod;
		(res *= pot(2, x - 2)) %= mod;
	}

	cout << res << endl;

	return 0;
}