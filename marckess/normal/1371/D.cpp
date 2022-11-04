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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 305;
int n, k, mat[MX][MX];

#define sq(b) (ll(b)*(b))

void solve () {
	cin >> n >> k;
	
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < n && k; i++)
		for (int j = 0; j < n && k; j++, k--)
			mat[j][(j + i) % n] = 1;

	int a = 1e9, b = 0, c = 1e9, d = 0;
	forn (i, n) {
		int p = 0;
		forn (j, n) p += mat[i][j];
		a = min(a, p);
		b = max(b, p);
	}

	forn (j, n) {
		int p = 0;
		forn (i, n) p += mat[i][j];
		c = min(c, p);
		d = max(d, p);
	}

	cout << sq(a - b) + sq(c - d) << endl;
	forn (i, n) {
		forn (j, n) cout << mat[i][j];
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