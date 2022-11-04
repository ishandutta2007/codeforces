#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int t;
ll n, x, y, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> x >> y >> d;

		ll res = 1e18;

		if ((x - y) % d == 0) {
			res = abs(x - y) / d;
		}

		if ((y - 1) % d == 0) {
			ll e = (x - 1 + d - 1) / d;
			res = min(res, e + (y - 1) / d);
		}

		if ((n - y) % d == 0) {
			ll e = (n - x + d - 1) / d;
			res = min(res, e + (n - y) / d);
		}

		if (res == 1e18) cout << -1 << endl;
		else cout << res << endl;
	}

	return 0;
}