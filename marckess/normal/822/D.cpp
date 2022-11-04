#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const ll inf = numeric_limits<ll>::max();
const int MX = 5000005, mod = 1'000'000'007;
ll t, l, r, f[MX], p[MX];
bitset<MX> bs;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (ll i = 2; i < MX; i++) {
		p[i] = i * (i - 1) / 2;
		f[i] = inf;
	}

	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			f[i] = p[i];
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
		}

	for (int i = 2; i < MX; i++)
		for (int j = 2 * i, k = 2; j < MX; j += i, k++)
			f[j] = min(f[j], i * p[k] + f[i]);

	for (int i = 2; i < MX; i++)
		f[i] %= mod;

	cin >> t >> l >> r;

	ll res = 0, x = 1;
	for (int i = l; i <= r; i++) {
		res += x * f[i];
		res %= mod;
		x *= t;
		x %= mod;
	}

	cout << res << endl;

	return 0;
}