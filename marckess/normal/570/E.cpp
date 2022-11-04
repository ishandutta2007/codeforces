#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 505, mod = 1'000'000'007;
int dp[2][MX][MX], n, m;
char mp[MX][MX];

void sum (int &a, int b) {
	a += b;
	a %= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mp[i];

	if (mp[0][0] != mp[n-1][m-1]) {
		cout << 0 << endl;
		return 0;
	}

	dp[0][0][0] = 1;

	int x, y;

	for (int i = 0; 2 * i < n + m - 3; i++) {
		x = i % 2, y = 1 - x;
		memset(dp[y], 0, sizeof(dp[y]));

		for (int j = 0; j < n && i - j >= 0; j++) {
			if (i - j >= m)
				continue;

			for (int k = 0; k < n && i - k >= 0; k++) {
				if (i - k >= m)
					continue;

				int a = j, b = i - j;
				int c = n - 1 - k, d = m - 1 - (i - k);

				if (a + 1 < n) {
					if (c - 1 >= 0 && mp[a+1][b] == mp[c-1][d]) {
						//printf("%d,%d -> %d,%d\n", a+1, b, c-1, d);
						sum(dp[y][a+1][n-1-(c-1)], dp[x][j][k]);
					}
					
					if (d - 1 >= 0 && mp[a+1][b] == mp[c][d-1]){
						//printf("%d,%d -> %d,%d\n", a+1, b, c, d-1);
						sum(dp[y][a+1][n-1-c], dp[x][j][k]);
					}
				}

				if (b + 1 < m) {
					if (c - 1 >= 0 && mp[a][b+1] == mp[c-1][d]) {
						//printf("%d,%d -> %d,%d\n", a, b+1, c-1, d);
						sum(dp[y][a][n-1-(c-1)], dp[x][j][k]);
					}
					
					if (d - 1 >= 0 && mp[a][b+1] == mp[c][d-1]) {
						//printf("%d,%d -> %d,%d\n", a, b+1, c, d-1);
						sum(dp[y][a][n-1-c], dp[x][j][k]);
					}
				}
			}
		}
	}

	int res = 0;

	if ((n + m) % 2) {
		for (int i = 0; i < n; i++)
			for (int k = 0; k < 2; k++)
				if (n - 1 - k >= 0)
					sum(res, dp[y][i][n-1-(i+k)]);
	} else {
		for (int i = 0; i < n; i++)
			sum(res, dp[y][i][n-1-i]);
	}

	cout << res << endl;

	return 0;
}