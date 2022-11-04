#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, ft[MX], ini[MX], fin[MX];
vi c;
ii a[MX];
vi pos[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void clear () {
	for (int i = 1; i <= 2 * n; i++) {
		ft[i] = 0;
		ini[i] = 0;
		fin[i] = 0;
		pos[i].clear();
	}
	c.clear();
}

void solve () {
	cin >> n;
	clear();
	
	forn (i, n) {
		cin >> a[i].fi >> a[i].se;
		c.pb(a[i].fi);
		c.pb(a[i].se);
	}
	
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	
	forn (i, n) {
		a[i].fi = upper_bound(all(c), a[i].fi) - c.begin();
		a[i].se = upper_bound(all(c), a[i].se) - c.begin();
		
		ini[a[i].fi]++;
		fin[a[i].se]++;
		
		pos[a[i].se].pb(i);
	}
	
	int res = 0;
	int acu = 0;
	
	for (int i = 1; i <= c.size(); i++) {
		acu += ini[i];
		acu -= fin[i];
		update(i, fin[i]);
		
		for (int j : pos[i])
			res = max(res, acu + query(i) - query(a[j].fi - 1));
	}
	
	cout << n - res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}