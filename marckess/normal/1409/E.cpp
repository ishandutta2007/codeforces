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

const int MX = 200005;
int n, k, dp[MX][2];
vi x;

void solve () {
	cin >> n >> k;
	x.resize(n);

	forn (i, n) cin >> x[i];
	int kk;
	forn (i, n) cin >> kk;

	sort(all(x));

	dp[n][0] = dp[n][1] = 0;
	for (int i = n - 1; i >= 0; i--) {
		int to = upper_bound(all(x), x[i] + k) - x.begin();

		dp[i][0] = max(dp[i + 1][0], dp[to][1] + to - i);
		dp[i][1] = max(dp[i + 1][1], to - i);
	}

	cout << dp[0][0] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}