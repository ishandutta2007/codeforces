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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll n, a, ant, mx, res;

void solve () {
	cin >> n;

	mx = -1e18;
	forn (i, n) {
		cin >> a;
		if (i) {
			if (a < 0 != ant < 0) {
				res += mx;
				mx = a;
			} else {
				mx = max(mx, a);
			}
		} else {
			mx = a;
		}
		ant = a;
	}
	res += mx;

	cout << res << endl;
	res = 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}