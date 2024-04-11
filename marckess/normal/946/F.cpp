#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 105, mod = 1e9+7;

int n, x;
ll dp[MX][MX][MX], f[MX];
string s;

ll pot (ll b, ll p, int mod) {
	ll res = 1;
	b %= mod;
	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}
	return res;
} 

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') dp[0][i][i] = 1;
		else dp[1][i][i] = 1;
	}

	f[0] = f[1] = 1;
	for (int i = 2; i <= x; i++) {
		f[i] = (f[i-1] + f[i-2]) % (mod-1);

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ll &_ = dp[i][j][k];

				_ = (dp[i-1][j][k] * (k == n - 1 ? pot(2, f[i-2], mod) : 1)
				   + dp[i-2][j][k] * (j == 0 ? pot(2, f[i-1], mod) : 1))
				   % mod;

				for (int l = j; l < k; l++)
					_ += dp[i-1][j][l] * dp[i-2][l+1][k] % mod;
				_ %= mod;
			}
		}
	}

	cout << dp[x][0][n-1] << endl;

	return 0;
}