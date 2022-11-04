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

const int MX = 105;
int n, m;
ll a[MX][MX], dp1[MX][MX], dp2[MX][MX], res;

void solve () {
	cin >> n >> m;

	forn (i, n) forn (j, m) cin >> a[i][j];

	res = 2e18;
	forn (i, n) forn (j, m) {
		for (int x = i; x < n; x++)
			for (int y = j; y < m; y++) {
				dp1[x][y] = 2e18;

				if (x == i && y == j) {
					dp1[x][y] = 0;
					continue;
				}

				ll act = a[i][j] + (x - i) + (y - j);
				if (a[x][y] < act) continue;

				if (x - i) dp1[x][y] = min(dp1[x][y], dp1[x - 1][y] + a[x][y] - act);
				if (y - j) dp1[x][y] = min(dp1[x][y], dp1[x][y - 1] + a[x][y] - act);
			}

		for (int x = i; x >= 0; x--)
			for (int y = j; y >= 0; y--) {
				dp2[x][y] = 2e18;

				if (x == i && y == j) {
					dp2[x][y] = 0;
					continue;
				}

				ll act = a[i][j] - (i - x) - (j - y);
				if (a[x][y] < act) continue;

				if (i - x) dp2[x][y] = min(dp2[x][y], dp2[x + 1][y] + a[x][y] - act);
				if (j - y) dp2[x][y] = min(dp2[x][y], dp2[x][y + 1] + a[x][y] - act);
			}

		res = min(res, dp1[n - 1][m - 1] + dp2[0][0]);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}