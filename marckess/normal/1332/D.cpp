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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, m, dp[MX][MX], a[MX][MX];
int k;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> k;
	n = 3, m = 4;
	vector<vi> res = {
		{(1 << 18) - 1,     (1 << 18) - 1,     (1 << 18) - 1, (1 << 18) - 1 - k},
		{(1 << 18) - 1 - k, (1 << 18) - 1 - k, (1 << 17) - 1, (1 << 18) - 1},
		{(1 << 18) - 1 - k, (1 << 18) - 1 - k, (1 << 18) - 1, (1 << 17) - 1}
	};

	cout << n << " " << m << endl;
	forn (i, n) {
		forn (j, m) cout << res[i][j] << " ";
		cout << endl;
	}

	/*cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	dp[0][1] = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j] & a[i][j], dp[i][j - 1] & a[i][j]);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}