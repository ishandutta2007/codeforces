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

const ll MX = 1000000000000000000;

vector<ll> v;
ll t, n;

ll sqr (ll n) {
	ll x = sqrt(n), res = x-2;

	for (ll i = x - 2; i <= x + 2; i++)
		if (i * i <= n)
			res = i;

	return res;
}

void pre () {
	ll h, d, lim;
	for (ll i = 2; i <= 1e6; i++) {
		h = i * i * i, lim = MX / i;

		d = sqr(h);
		if (d * d != h) v.pb(h);

		while (h <= lim) {
			h *= i;

			d = sqr(h);
			if (d * d != h) v.pb(h);
		}
	}

	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> t;
	while (t--) {
		cin >> n;
		cout << n - (sqr(n) + (upper_bound(ALL(v), n) - v.begin())) << endl;
	}

	return 0;
}