#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll n, a, b, k, m = 1e9+9, z;
string s;

ll pot (ll b, int p, int m) {
	ll res = 1;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}

		b *= b;
		b %= m;
		p /= 2;
	}

	return res;
}

ll geo (ll a, ll r, int p) {
	if (r == 1)
		return MOD(a * p, m);

	ll res = MOD(pot(r, p, m) - 1, m);
	res *= pot(r - 1, m-2, m);
	res %= m;

	return (a * res) % m;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b >> k >> s;
	z = (n + 1) / k - 1;

	ll res = 0;
	for (int i = 0; i < k; i++) {
		ll sig;
		if (s[i] == '-')
			sig = -1;
		else
			sig = 1;
		res += sig * pot(a, n-i, m) * pot(b, i, m) % m;
		res %= m; 
	}

	ll x = pot(b, k, m);
	ll y = pot(a, k, m);

	res *= geo(1, x * pot (y, m-2, m) % m, z + 1);
	res = MOD(res, m);

	cout << res << endl;

	return 0;
}