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

const int MX = 2005, mod = 1000000007;
int n, k;
ll dp[MX][MX], acu[MX];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;

	dp[0][k] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) {
			ll &res = dp[i][j];
			res = (s[i-1]-'a') * (dp[i-1][j] + acu[j]);
			for (int l = i, m = n-i+1; l > 0 && j+m <= k; l--, m += n-i+1)
				res += ('z' - s[i-1]) * dp[l-1][j+m];
			res %= mod;
			acu[j] += dp[i-1][j];
			acu[j] %= mod;
		}

	ll res = 0;
	for (int i = 0; i <= n; i++)
		res += dp[i][0];
	cout << res % mod << endl;

	return 0;
}