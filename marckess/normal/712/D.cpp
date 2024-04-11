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

const int mod = 1'000'000'007;
const int MX = 200105;
int dpa[2][MX] = {0}, dpb[2][MX] = {0}, a, b, k, t;

void calcDP (int dp[2][MX], int a) {
	dp[0][100000+a] = 1;

	for (int i = 0; i < t; i++) {
		int x = i % 2, y = 1 - x;
		memset(dp[y], 0, sizeof(dp[y]));

		for (int j = 0; j < MX; j++) {
			int l = max(0, j - k);
			dp[y][l] += dp[x][j];
			dp[y][l] %= mod;

			l = j + k + 1;
			if (l < MX) {
				dp[y][l] -= dp[x][j];
				dp[y][l] %= mod;
			}
		}

		for (int j = 1; j < MX; j++) {
			dp[y][j] += dp[y][j-1];
			dp[y][j] %= mod;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> k >> t;

	calcDP(dpa, a);
	calcDP(dpb, b);

	ll res = 0, acu = 0;
	int x = t % 2;

	for (int i = 0; i < MX; i++) {
		res += acu * dpa[x][i] % mod;
		res %= mod;
		acu += dpb[x][i];
		acu %= mod;
	}

	cout << MOD(res, mod) << endl;

	return 0;
}