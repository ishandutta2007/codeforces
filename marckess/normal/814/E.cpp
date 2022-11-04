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

const int MX = 55, mod = 1e9+7;
int n, dp[2][MX][MX][MX][MX], v[MX];

void sum (int &a, ll b) {
	a = (a + b) % mod;
}

ll comb (int n, int k) {
	if (!k) return 1;
	if (k == 1) return n;
	return n * (n - 1) / 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int x, y;
	dp[n%2][0][0][0][0] = 1;

	for (int i = n - 1; i >= 2; i--) {
		x = i % 2, y = 1 - x;

		for (int c = 0; c <= n; c++)
			for (int d = 0; d <= n - c; d++)
				for (int a = 0; a <= n - c - d; a++)
					for (int b = 0; b <= n - c - d - a; b++) {
						int &res = dp[x][a][b][c][d];
						res = 0;

						if (!a && !b) {
							if (c || d) res = dp[x][c][d][0][0];
							continue;
						}

						for (int f = 0; f <= min(c, v[i] - 1); f++)
							for (int g = 0; g <= min(d, v[i] - f - 1); g++) {
								int e = v[i] - f - g - 1;
								ll p = comb(c, f) * comb(d, g);

								if (!e) {
									if (a) sum(res, p * a * dp[y][a-1][b][c-f+g][d-g]);
									if (b) sum(res, p * b * dp[y][a+1][b-1][c-f+g][d-g]);
								} else if (e == 1) {
									if (a) sum(res, p * a * dp[y][a-1][b][c-f+g+1][d-g]);
									if (b) sum(res, p * b * dp[y][a+1][b-1][c-f+g+1][d-g]);
								} else {
									if (a) sum(res, p * a * dp[y][a-1][b][c-f+g][d-g+1]);
									if (b) sum(res, p * b * dp[y][a+1][b-1][c-f+g][d-g+1]);
								}
							}
					}
	}

	cout << dp[0][v[0] == 2][v[0] == 3][v[1] == 2][v[1] == 3] << endl;

	return 0;
}