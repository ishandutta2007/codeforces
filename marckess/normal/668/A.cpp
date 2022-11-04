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

int n, m, q, a[105][105];
vi b[10005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;

	forn (i, q) {
		int t;
		cin >> t;

		if (t == 1) {
			int r;
			cin >> r;
			b[i] = {t, r - 1};
		} else if (t == 2) {
			int c;
			cin >> c;
			b[i] = {t, c - 1};
		} else {
			int r, c, x;
			cin >> r >> c >> x; 
			b[i] = {t, r - 1, c - 1, x};
		}
	}

	for (int i = q - 1; i >= 0; i--) {
		if (b[i][0] == 1) {
			int r = b[i][1];

			for (int k = m - 2; k >= 0; k--)
				swap(a[r][k], a[r][k + 1]);
		} else if (b[i][0] == 2) {
			int c = b[i][1];

			for (int k = n - 2; k >= 0; k--)
				swap(a[k][c], a[k + 1][c]);
		} else {
			int r = b[i][1];
			int c = b[i][2];
			int x = b[i][3];

			a[r][c] = x;
		}
	}

	forn (i, n) {
		forn (j, m) cout << a[i][j] << " ";
		cout << endl;
	}

	return 0;
}