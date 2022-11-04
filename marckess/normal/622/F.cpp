#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1'000'005, mod = 1'000'000'007;
int n, k;
ll y[MX];

ll pot (ll b, ll p) {
	ll res = 1;
	b %= mod;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= k+1; i++)
		y[i] = (y[i-1] + pot(i, k)) % mod;

	if (n <= k+1) {
		cout << y[n] << endl;
		return 0;
	}

	ll f = 1, res = 0;
	for (int i = 0; i <= k+1; i++)
		if (i != 1)
			f = f * (n - i) % mod * pot(1-i, mod-2) % mod;

	for (int i = 1; i <= k+1; i++) {
		res += y[i] * f % mod;
		res %= mod;
		f = f * (n - i) % mod * (i - (k + 1)) % mod
		      * pot(n - (i + 1), mod-2) % mod 
		      * pot(i + 1, mod-2) % mod;
	}

	cout << MOD(res, mod) << endl;
	
	return 0;
}