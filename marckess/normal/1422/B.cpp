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

const int MX = 105;
int n, m, a[MX][MX];
ll res;

void solve () {
	cin >> n >> m;
	forn (i, n) forn (j, m) cin >> a[i][j];
	
	res = 0;
	
	forn (i, n) forn (j, m) {
		int x = n - i - 1;
		int y = m - j - 1;
		vi v;
		
		if (i != x && j != y) {
			v = {a[i][j], a[i][y], a[x][j], a[x][y]};
		} else if (i != x) {
			v = {a[i][j], a[x][j]};
		} else if (j != y) {
			v = {a[i][j], a[i][y]};
		} else {
			v = {a[i][j]};
		}
		
		sort(all(v));
		
		forn (i, v.size())
			res += abs(v[v.size() / 2] - v[i]);
			
		a[i][j] = a[i][y] = a[x][j] = a[x][y] = v[v.size() / 2];
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}