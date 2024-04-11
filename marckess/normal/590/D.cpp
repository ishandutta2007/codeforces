#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 150, inf = 1e9;
int dp[2][MX+2][75*75+2];
int n, k, s, a[MX+5];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (s >= 75 * 75) {
		sort(a, a+n);
		int res = 0;
		for (int i = 0; i < k; i++)
			res += a[i];
		cout << res << endl;
		return 0;
	}

	for (int j = 0; j < MX+2; j++)
		for (int l = 0; l < 75*75+2; l++)
			dp[0][j][l] = inf;
	dp[0][0][s] = 0;

	for (int i = 0; i < n; i++) {
		int x = i % 2, y = 1 - x;
		
		for (int j = 0; j <= min(i+1, k); j++)
			for (int l = 0; l <= s; l++)
				dp[y][j][l] = inf;

		for (int j = 0; j <= min(i, k); j++)
			for (int l = 0; l <= s; l++) {
				dp[y][j][l] = min(dp[y][j][l], dp[x][j][l]);

				if (i - j <= l)
					dp[y][j+1][l-(i-j)] = min(dp[y][j+1][l-(i-j)], dp[x][j][l] + a[i]);
			}
	}

	int res = inf;
	for (int i = 0; i <= s; i++)
		res = min(res, dp[n%2][k][i]);
	cout << res << endl;

	return 0;
}