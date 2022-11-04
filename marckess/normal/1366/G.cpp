#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10005;
int n, m, dp[MX][MX], a[MX];
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s >> t;
	n = s.size(), m = t.size();

	forn (i, m) dp[n][i] = 1e9;

	for (int i = n - 1; i >= 0; i--) {
		int to = -1, x = 0;

		for (int k = i; k < n; k++) {
			if (s[k] == '.') x--;
			else x++;

			if (x < 0) break;
			if (!x) {
				to = k;
				break;
			}
		}

		for (int j = m; j >= 0; j--) {
			dp[i][j] = dp[i + 1][j] + 1;
			if (to != -1) dp[i][j] = min(dp[i][j], dp[to + 1][j]);
			if (j < m && s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
		}
	}

	cout << dp[0][0] << endl;

	return 0;
}