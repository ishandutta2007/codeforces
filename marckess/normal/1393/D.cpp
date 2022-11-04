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

const int MX = 2005;
int n, m, res[MX][MX], izq[MX][MX], der[MX][MX], arr[MX][MX], aba[MX][MX], acu;
int dp[MX][MX];
char c[MX][MX];

void solve () {
	cin >> n >> m;
	
	forn (i, n) forn (j, m) {
		cin >> c[i][j];
		res[i][j] = MX;
	}

	forn (i, n) {
		forn (j, m) {
			izq[i][j] = 1;
			if (j && c[i][j - 1] == c[i][j]) izq[i][j] += izq[i][j - 1];
		}
		for (int j = m - 1; j >= 0; j--) {
			der[i][j] = 1;
			if (j + 1 < m && c[i][j] == c[i][j + 1]) der[i][j] += der[i][j + 1];
		}
	}

	forn (j, m) {
		forn (i, n) {
			arr[i][j] = 1;
			if (i && c[i - 1][j] == c[i][j]) arr[i][j] += arr[i - 1][j];
		}
		for (int i = n - 1; i >= 0; i--) {
			aba[i][j] = 1;
			if (i + 1 < n && c[i][j] == c[i + 1][j]) aba[i][j] += aba[i + 1][j];
		}
	}

	forn (i, n) forn (j, m) {
		dp[i][j] = min(izq[i][j], der[i][j]);
		if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
		else dp[i][j] = 1;
		res[i][j] = min(res[i][j], dp[i][j]);
	}

	forn (i, n) forn (j, m) {
		dp[i][j] = min(aba[i][j], arr[i][j]);
		if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
		res[i][j] = min(res[i][j], dp[i][j]);
	}

	for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) {
		dp[i][j] = min(izq[i][j], der[i][j]);
		if (i + 1 < n) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
		else dp[i][j] = 1;
		res[i][j] = min(res[i][j], dp[i][j]);
	}

	for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) {
		dp[i][j] = min(aba[i][j], arr[i][j]);
		if (j + 1 < m) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
		else dp[i][j] = 1;
		res[i][j] = min(res[i][j], dp[i][j]);
	}

	forn (i, n) forn (j, m) acu += res[i][j];

	cout << acu << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}