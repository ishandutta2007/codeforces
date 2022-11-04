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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
const ld eps = 1e-20; 

int n, t;
ll p = 0, q = 0;
ii a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> a[i].se;
	for (int i = 0; i < n; i++) cin >> a[i].fi;

	for (int i = 0; i < n; i++) {
		p += a[i].fi * a[i].se;
		q += a[i].se;
	}

	sort(a, a+n);

	if (p == t * q) {
		cout << q << endl;
		return 0;
	}

	if (p < t * q) {
		for (int i = 0; i < n; i++)
			if (p - a[i].fi * a[i].se >= t * (q - a[i].se)) {
				cout << q - ld(t * q - p) / (t - a[i].fi) << endl;
				return 0;
			} else {
				p -= a[i].fi * a[i].se;
				q -= a[i].se;
			}
	} else {
		for (int i = n-1; i >= 0; i--)
			if (p - a[i].fi * a[i].se <= t * (q - a[i].se)) {
				cout << q - ld(t * q - p) / (t - a[i].fi) << endl;
				return 0;
			} else {
				p -= a[i].fi * a[i].se;
				q -= a[i].se;
			}
	}

	cout << 0 << endl;

	return 0;
}