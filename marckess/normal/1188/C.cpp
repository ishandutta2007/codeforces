#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int mod = 998244353;
int n, k, dp[1005][1005], a[1005], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	forn(i, n) cin >> a[i+1];
	sort(a+1, a+n+1);
	for (int x = 1; x <= 100000 / (k - 1); x++) {
		for (int i = 1, j = 0; i <= n; i++) {
			while (j < i && a[i] - x >= a[j + 1]) j++;
			for (int l = 1; l <= k; l++) {
				dp[i][l] = dp[i-1][l] + dp[j][l-1] + (l == 1);
				if (dp[i][l] >= mod) dp[i][l] -= mod;
			}
		}
		(res += dp[n][k]) %= mod;
	}
	cout << res << endl;

	return 0;
}