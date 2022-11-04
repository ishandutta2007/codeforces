#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int MX = 200005, mod = 998244353;
int n, m, a[MX], w[MX], sa, sb, res[MX];
ll dp[2][102][152][152], inv[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 1; i < MX; i++)
		inv[i] = pot(i, mod - 2);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		if (a[i]) sa += w[i];
		else sb += w[i];
	}

	for (int j = 0; j <= 100; j++)
		for (int k = 0; k <= 100; k++)
			for (int l = 0; l <= 100; l++)
				dp[0][j][k][l] = j;

	int x = 1, y = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				for (int l = 0; l <= 100; l++) {
					dp[x][j][k][l] = 0;
					if (j + (sa - 50 + k) + (sb - 50 + l) < 0) continue;

					if (j < 100) dp[x][j][k][l] += j * dp[y][j+1][k][l];
					if (k < 100) dp[x][j][k][l] += (sa - 50 + k) * dp[y][j][k+1][l];
					if (l) dp[x][j][k][l] += (sb - 50 + l) * dp[y][j][k][l-1];
					
					dp[x][j][k][l] %= mod;
					(dp[x][j][k][l] *= inv[j + (sa - 50 + k) + (sb - 50 + l)]) %= mod;
				}
			}
		}
		x ^= 1;
		y ^= 1;
	}

	for (int i = 0; i < n; i++)
		if (a[i])
			res[i] = dp[m % 2][w[i]][50 - w[i]][50];

	// -----------------------------------------------------------

	for (int j = 0; j <= 100; j++)
		for (int k = 0; k <= 100; k++)
			for (int l = 0; l <= 100; l++)
				dp[0][j][k][l] = j;

	x = 1, y = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= 50; j++) {
			for (int k = 0; k <= 100; k++) {
				for (int l = 0; l <= 100; l++) {
					dp[x][j][k][l] = 0;
					if (j + (sa - 50 + k) + (sb - 100 + l) < 0) continue;

					if (j) dp[x][j][k][l] += j * dp[y][j-1][k][l];
					if (k < 100) dp[x][j][k][l] += (sa - 50 + k) * dp[y][j][k+1][l];
					if (l) dp[x][j][k][l] += (sb - 100ll + l) * dp[y][j][k][l-1];
					
					dp[x][j][k][l] %= mod;
					(dp[x][j][k][l] *= inv[j + (sa - 50 + k) + (sb - 100 + l)]) %= mod;
				}
			}
		}
		x ^= 1;
		y ^= 1;
	}

	for (int i = 0; i < n; i++)
		if (!a[i])
			res[i] = dp[m % 2][w[i]][50][100 - w[i]];

	for (int i = 0; i < n; i++)
		cout << res[i] << endl;
 
	return 0;
}