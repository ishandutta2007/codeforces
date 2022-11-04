#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 300005;
int n, a[MX], res;
ll inv;

void solve () {
	cin >> n;

	forn (i, n) cin >> a[i];

	vvi v;

	v.pb({});
	forn (i, n) v.back().pb(a[i]);

	for (int i = 30; i >= 0; i--) {
		ll x = 0, y = 0;
		vvi nex;

		for (vi &a : v) {
			int cn[2] = {0};
			vi f, g;

			forn (j, a.size()) {
				if (a[j] & (1 << i)) {
					y += cn[0];
					cn[1]++;

					f.pb(a[j]);
				} else {
					x += cn[1];
					cn[0]++;

					g.pb(a[j]);
				}
			}

			if (f.size()) nex.pb(f);
			if (g.size()) nex.pb(g);
		}

		if (y < x) {
			inv += y;
			res |= 1 << i;
		} else {
			inv += x;
		}

		v = nex;
	}

	cout << inv << " " << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)	
		solve();

	return 0;
}