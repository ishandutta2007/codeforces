#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 998244353;
ll n, a[MX];

ll pot (ll b, ll p, int mod) {
	ll res = 1;
	b %= mod;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

ll f (ll n) {
	if (!n) return 1;
	return (n + 2) * pot(2, n-1, mod) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll res = 0;

	for (int i = 0; i < n; i++) {
		res += a[i] * f(n-i-1) % mod;
		res %= mod;
	}

	cout << res << endl;

	return 0;
}