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

const int MX = 200005, mod = 1000000007;
int n, l[MX], r[MX];
ll acu, res, x[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p >>= 1;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) cin >> l[i+1];
	forn (i, n) cin >> r[i+1];

	for (int i = n; i; i--) {
		x[i] = min(r[i], r[i - 1]) - max(l[i], l[i - 1]) + 1;

		if (x[i] < 0) x[i] = 0;
		else (x[i] *= pot(ll(r[i - 1] - l[i - 1] + 1) * (r[i] - l[i] + 1) % mod, mod - 2)) %= mod;
		x[i] = 1 - x[i];

		(res += x[i]) %= mod;

		if (i + 2 <= n) (acu += x[i + 2]) %= mod;
		(res += 2 * x[i] * acu) %= mod;

		if (i + 1 <= n) {
			ll y = min({r[i + 1], r[i], r[i - 1]}) - max({l[i + 1], l[i], l[i - 1]}) + 1;
			
			if (y > 0) {
				(y *= pot(
					ll(r[i + 1] - l[i + 1] + 1) * (r[i] - l[i] + 1) % mod * (r[i - 1] - l[i - 1] + 1) % mod,
					mod - 2
				)) %= mod;
			} else {
				y = 0;
			}

			(res += 2 * (x[i] + x[i + 1] + y - 1)) %= mod;
		}
	}

	cout << MOD(res, mod) << endl;

	return 0;
}