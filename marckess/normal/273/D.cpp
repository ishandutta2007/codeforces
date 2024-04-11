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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 155, mod = 1000000007;
int n, m, dp[MX][2][2][MX][MX], acu[2][2][MX][MX], res;

void sum (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

void pre (int dp[2][2][MX][MX]) {
	forn (i, 2) forn (j, 2)
		for (int a = 1; a <= m; a++)
			for (int b = 1; b <= m; b++) {
				acu[i][j][a][b] = dp[i][j][a][b];
				sum(acu[i][j][a][b], acu[i][j][a - 1][b]);
				sum(acu[i][j][a][b], acu[i][j][a][b - 1]);
				sum(acu[i][j][a][b], -acu[i][j][a - 1][b - 1]);
			}
}

int query (int i, int j, int a1, int a2, int b1, int b2) {
	if (a1 > a2 || b1 > b2) return 0;
	int res = acu[i][j][a2][b2];
	sum(res, -acu[i][j][a1 - 1][b2]);
	sum(res, -acu[i][j][a2][b1 - 1]);
	sum(res, acu[i][j][a1 - 1][b1 - 1]);
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int a = 1; a <= m; a++)
		for (int b = a; b <= m; b++)
			dp[1][0][0][a][b] = dp[1][1][0][a][b] = dp[1][0][1][a][b] = dp[1][1][1][a][b] = 1;
	
	res = n * m * (m + 1) / 2;

	for (int k = 2; k <= n; k++) {
		pre(dp[k - 1]);

		forn (i, 2) forn (j, 2)
			for (int a = 1; a <= m; a++)
				for (int b = a; b <= m; b++) {
					dp[k][i][j][a][b]    = query(0, 0, a + 1, b, a, b - 1);
					sum(dp[k][i][j][a][b], query(0, j, a + 1, b, b, b));
					sum(dp[k][i][j][a][b], query(0, 1, a + 1, b, b + 1, m) * j);

					sum(dp[k][i][j][a][b], query(i, 0, a, a, a, b - 1));
					sum(dp[k][i][j][a][b], query(i, j, a, a, b, b));
					sum(dp[k][i][j][a][b], query(i, 1, a, a, b + 1, m) * j);

					if (!i) continue; 
					
					sum(dp[k][i][j][a][b], query(1, 0, 1, a - 1, a, b - 1));
					sum(dp[k][i][j][a][b], query(1, j, 1, a - 1, b, b));
					sum(dp[k][i][j][a][b], query(1, 1, 1, a - 1, b + 1, m) * j);
				}

		for (int a = 1; a <= m; a++)
			for (int b = a; b <= m; b++)
				sum(res, ll(n - k + 1) * dp[k][1][1][a][b] % mod);
	}

	cout << res << endl;

	return 0;
}