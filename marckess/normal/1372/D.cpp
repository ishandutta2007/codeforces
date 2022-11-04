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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
ll dp[MX], res;

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];

	res = 0;

	for (int i = 0; i < n; i += 2)
		dp[0] += a[i];
	res = max(res, dp[0]);

	for (int i = 1; i < n; i += 2)
		dp[1] += a[i];
	dp[1] += a[0];
	res = max(res, dp[1]);

	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 2];
		dp[i] -= a[i - 2];
		dp[i] += a[i - 1];

		res = max(res, dp[i]);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}