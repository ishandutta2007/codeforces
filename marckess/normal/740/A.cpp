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

ll n, a, b, c, res = 1e18, dp[30];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(dp+1, dp+30, 1e18);

	cin >> n >> a >> b >> c;

	for (int i = 0; i < 25; i++) {
		dp[i+1] = min(dp[i+1], dp[i]+a);
		dp[i+2] = min(dp[i+2], dp[i]+b);
		dp[i+3] = min(dp[i+3], dp[i]+c);

		if ((i + n) % 4 == 0)
			res = min(res, dp[i]);
	}

	cout << res << endl;

	return 0;
}