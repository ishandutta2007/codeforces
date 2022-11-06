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

const int MX = 2005;
int n, m;
char ch[MX][MX];
vi ra, rb, rc, rd;

bool pos(int w) {
	int a = 1e9, b = 1e9, c = 0, d = 0;
	forn (i, n) forn(j, m) if (ch[i][j] == w) {
		a = min(a, i);
		b = min(b, j);
		c = max(c, i);
		d = max(d, j);
	}

	if (a == 1e9) {
		if (ra.size()) {
			ra.pb(ra.back());
			rb.pb(rb.back());
			rc.pb(rc.back());
			rd.pb(rd.back());
		}
		return 1;
	} else if (a < c && b < d) {
		return 0;
	} else {
		for (int i = a; i <= c; i++)
			for (int j = b; j <= d; j++) {
				if (ch[i][j] != w && ch[i][j] != '*') 
					return 0;
				ch[i][j] = '*';
			}
	}
	ra.pb(a), rb.pb(b), rc.pb(c), rd.pb(d);
	return 1;
}

void solve () {
	cin >> n >> m;
	forn (i, n) cin >> ch[i];

	ra.clear(), rb.clear(), rc.clear(), rd.clear();
	for (int i = 'z'; i >= 'a'; i--)
		if (!pos(i)) {
			cout << "NO" << endl;
			return;
		}

	cout << "YES" << endl << ra.size() << endl;
	for (int i = (int)ra.size() - 1; i >= 0; i--)
		cout << ra[i]+1 << " " << rb[i]+1 << " " << rc[i]+1 << " " << rd[i]+1 << endl; 
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}