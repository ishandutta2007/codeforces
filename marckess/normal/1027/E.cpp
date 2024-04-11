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

const int MX = 505;
int n, k, mod = 998244353;
int dp[MX][MX];
ll res = 0;

ll pot (ll b, ll p, ll mod) {
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
	
	cin >> n >> k;

	for (int i = 0; i <= n; i++) dp[i][i] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = i+1; k <= n; k++) {
				int mx = max(j, k-i);
				dp[k][mx] += dp[i][j];
				if (dp[k][mx] > mod) dp[k][mx] -= mod;
			}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i * j < k) {
				res += (ll)dp[n][i] * dp[n][j];
				res %= mod;
			}

	cout << (res * pot(2, mod-2, mod)) % mod << endl;

	return 0;
}