#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005, mod = 1000000007;
int n, k, dp[MX][MX];

void solve () {
	cin >> n >> k;
	
	for (int i = 0; i <= k; i++)
		dp[i][0] = 1;
	
	for (int j = 1; j <= n; j++)
		dp[1][j] = 1;
	
	for (int i = 2; i <= k; i++)
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][n - j];
			if (dp[i][j] >= mod)
				dp[i][j] -= mod;
		}
	
	cout << dp[k][n] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)	
		solve();
	
	return 0;
}