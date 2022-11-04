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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef vector<ll> vl;
typedef vector<vl> vvl;

const int mod = 1000000007;
ll n, f1, f2, f3, c;

vvl mul (const vvl& a, const vvl& b, int mod) {
	vvl res(a.size(), vl(b[0].size()));

	forn (i, a.size()) forn (j, b[0].size()) forn (k, b.size())
		(res[i][j] += a[i][k] * b[k][j]) %= mod;

	return res;
}

vvl pot (vvl b, ll p, int mod) {
	vvl res(b.size(), vl(b.size()));
	forn (i, res.size()) res[i][i] = 1;

	while (p) {
		if (p & 1) res = mul(res, b, mod);
		b = mul(b, b, mod);
		p /= 2;
	}

	return res;
}

ll pot (ll b, ll p, int mod) {
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
	
	cin >> n >> f1 >> f2 >> f3 >> c;

	vvl b = {
		{1, 1, 1},
		{1, 0, 0},
		{0, 1, 0},
	};

	b = pot(b, n - 3, mod - 1);

	ll res = pot(f1, b[0][2], mod) * pot(f2, b[0][1], mod) % mod * pot(f3, b[0][0], mod) % mod;

	b = {
		{1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1},
	};

	b = pot(b, n - 3, mod - 1);

	(res *= pot(c * c % mod, b[0][3] + b[0][4], mod)) %= mod;

	cout << res << endl;

	return 0;
}