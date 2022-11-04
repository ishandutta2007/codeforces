#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, a[MX], b[MX];
vi x, y;

void solve () {
	cin >> n >> m;
	x.clear(), y.clear();
	
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	forn (i, n) {
		if (b[i] == 1) x.pb(a[i]);
		else y.pb(a[i]);
	}
	
	sort(all(x));
	sort(all(y));
	
	x.pb(0), y.pb(0);
	reverse(all(x));
	reverse(all(y));
	
	for (int i = 1; i < x.size(); i++) x[i] += x[i - 1];
	for (int i = 1; i < y.size(); i++) y[i] += y[i - 1];
	
	int res = 1e9;
	forn (i, x.size()) {
		int j = lower_bound(all(y), m - x[i]) - y.begin();
		if (j < y.size()) res = min(res, i + 2 * j);
	}
	
	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}