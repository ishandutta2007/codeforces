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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 75;
int n, m, k, a[MX][MX], x, y, dp[MX][MX][MX];
int dp2[MX][MX], b[MX][MX];

void maxi (int &a, int b) {
	a = max(a, b);
}

void solve () {
	cin >> n >> m >> k;
	forn (i, n) forn (j, m) cin >> a[i][j];
	forn (i, n) {
		forn (a, MX) forn (b, MX) forn (c, MX) dp[a][b][c] = -1e9;
		dp[0][0][0] = 0;
		forn (x, m) forn (j, k) forn (l, m / 2 + 1) {
			int y = j + a[i][x];
			y %= k;
			maxi(dp[x + 1][j][l], dp[x][j][l]);
			maxi(dp[x + 1][y][l + 1], dp[x][j][l] + a[i][x]);
		}
		forn (j, MX) b[i][j] = -1e9;
		forn (j, k) forn (l, m / 2 + 1) {
			maxi(b[i][j], dp[m][j][l]);
		}
	}
	forn (a, MX) forn (b, MX) dp2[a][b] = -1e9;
	dp2[0][0] = 0;
	forn (i, n) forn (j, k) forn (l, k) {
		int y = j + l;
		if (y >= k) y -= k;
		maxi(dp2[i + 1][j], dp2[i][j]);
		maxi(dp2[i + 1][y], dp2[i][j] + b[i][l]);
	}
	cout << dp2[n][0] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}