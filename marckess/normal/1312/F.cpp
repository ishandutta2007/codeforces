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
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;

int mex (vi v) {
	forn(i, 4) {
		int f = 1;

		for (int x : v)
			if (x == i)
				f = 0;
		
		if (f)
			return i;
	}
}

struct Game {
	int x, y, z, cyc, col;
	vvi gx, gy, gz;

	void build (int _x, int _y, int _z) {
		x = _x, y = _y, z = _z;
		map<vi, map<vi, map<vi, int>>> mp;

		vi sx = {0, 0, 0, 0, 0}, sy = sx, sz = sx;
		gx.pb(sx), gy.pb(sy), gz.pb(sz);

		for (int i = 1;; i++) {
			int &act = mp[sx][sy][sz];
			if (act) {
				col = act;
				cyc = i - act;
				break;
			}
			act = i;

			#define get(gx, sx, ...) sx.insert(sx.begin(), 0); sx[0] = mex(__VA_ARGS__); gx.pb(sx), sx.pop_back();
			get(gx, sx, {sx[x], sy[y - 1], sz[z - 1]})
			get(gy, sy, {sx[x], sz[z - 1]})
			get(gz, sz, {sx[x], sy[y]})
		}
	}

}games[6][6][6];

int n, x, y, z;
ll a[MX];

void solve () {
	int res = 0, s = 0;
	cin >> n >> x >> y >> z;
	Game &g = games[x][y][z];

	forn (i, n) {
		cin >> a[i];
		if (a[i] >= g.col)
			a[i] = g.col + (a[i] - g.col) % g.cyc;
		s ^= g.gx[a[i]][0];
	}

	forn (i, n) {
		#define sum(x) res += 1 - bool(s ^ g.gx[a[i]][0] ^ x);
		sum(g.gx[a[i]][x]) sum(g.gy[a[i]][y]) sum(g.gz[a[i]][z])
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, 5) forn (j, 5) forn (k, 5)
		games[i + 1][j + 1][k + 1].build(i + 1, j + 1, k + 1);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}