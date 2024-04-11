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
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, m, a[MX][MX];
vvi res;

void op (int z, int b, int c, int d, int e, int f) {
	a[z][b] ^= 1;
	a[c][d] ^= 1;
	a[e][f] ^= 1;
	res.pb({z, b, c, d, e, f});
}

int sum () {
	return a[0][0] + a[1][0] + a[0][1] + a[1][1];
}

void solve () {
	cin >> n >> m;
	
	forn (i, n) forn (j, m) {
		char c;
		cin >> c;
		a[i][j] = c == '1';
	}
	
	res.clear();
	
	for (int i = n - 1; i >= 2; i--)
		for (int j = m - 1; j >= 2; j--)
			if (a[i][j]) {
				op(i, j, i - 1, j, i, j - 1);
			}
	
	for (int i = n - 1; i >= 2; i--) {
		if (a[i][0] && a[i][1]) {
			op(i, 0, i, 1, i - 1, 0);
		} if (a[i][0]) {
			op(i, 0, i - 1, 0, i - 1, 1);
		} else if (a[i][1]) {
			op(i, 1, i - 1, 0, i - 1, 1);
		}
	}
	
	for (int j = m - 1; j >= 2; j--) {
		if (a[0][j] && a[1][j]) {
			op(0, j, 1, j, 0, j - 1);
		} else if (a[0][j]) {
			op(0, j, 0, j - 1, 1, j - 1);
		} else if (a[1][j]) {
			op(1, j, 0, j - 1, 1, j - 1);
		}
	}
	
	if (sum() == 4) {
		op(0, 0, 1, 0, 1, 1);
	}
	
	forn (kk, 2) {
		if (sum() == 1 || sum() == 2) {
			vvi x, y;
			forn (i, 2) forn (j, 2) {
				if (a[i][j]) x.pb({i, j});
				else y.pb({i, j});
			}
			op(x[0][0], x[0][1], y[0][0], y[0][1], y[1][0], y[1][1]);
		}
	}
	
	if (sum() == 3) {
		vvi x, y;
		forn (i, 2) forn (j, 2) {
			if (a[i][j]) x.pb({i, j});
			else y.pb({i, j});
		}
		op(x[0][0], x[0][1], x[1][0], x[1][1], x[2][0], x[2][1]);
	}
	
	cout << res.size() << endl;
	for (vi &v : res) {
		for (int x : v)
			cout << x + 1 << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}