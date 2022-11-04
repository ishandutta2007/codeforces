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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 998244353;
int n, a[MX], dp[2][205][2];

void sum (int &a, int b) {
	if (b < 0) b += mod;
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = 1;
	dp[0][1][0] = 1;
	for (int i = 0; i <= n; i++) {
		int x = i % 2, y = 1 - x;
		memset(dp[y], 0, sizeof(dp[y]));

		for (int j = 1; j <= 200; j++)
			sum(dp[x][j][0], dp[x][j-1][0]);
		for (int j = 199; j >= 0; j--)
			sum(dp[x][j][1], dp[x][j+1][1]);

		for (int j = 1; j <= 200; j++)
			if (a[i] == -1 || a[i] == j) {
				sum(dp[y][j+1][0], dp[x][j][0]);
				sum(dp[y][j][1], dp[x][j][0]);
				sum(dp[y][j-1][1], -dp[x][j][0]);

				sum(dp[y][j+1][0], dp[x][j][1]);
				sum(dp[y][j][1], dp[x][j][1]);
			}
	}

	int res = 0;
	if (a[n] != -1) res = dp[n%2][a[n]][1];
	else
		for (int i = 1; i <= 200; i++)
			sum(res, dp[n%2][i][1]);

	cout << res << endl;

	return 0;
}