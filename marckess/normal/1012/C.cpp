#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 5005, inf = 2e9;
int dp[MX][MX][2], n, a[MX];

#define mini(a,b) ((a) < (b) ? (a) : (b))
#define upd(a,b) (a) = mini(a, b)

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			dp[i][j][0] = dp[i][j][1] = inf;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = a[n+1] = -1;
	for (int i = 1; i <= n; i++) {
		dp[i][0][0] = 0;

		for (int j = 0; j <= i; j++) {
			if (dp[i][j][0] != inf) {
				upd(dp[i+1][j][0], dp[i][j][0]);

				int x = a[i-1] - a[i] + 1;
				int y = a[i+1] - a[i] + 1;
				if (x < 0) x = 0;
				if (y < 0) y = 0;

				upd(dp[i+2][j+1][1], dp[i][j][0] + x + y);
			}

			if (dp[i][j][1] != inf) {
				upd(dp[i+1][j][0], dp[i][j][1]);

				int x = a[i-1] - a[i] + 1;
				int y = a[i+1] - a[i] + 1;

				if (a[i-1] >= a[i-2])
					x = (a[i-2] - 1) - a[i] + 1;

				if (x < 0) x = 0;
				if (y < 0) y = 0;

				upd(dp[i+2][j+1][1], dp[i][j][1] + x + y);
			}
		}
	}

	for (int i = 1; i <= (n + 1) / 2; i++)
		cout << min({dp[n+1][i][0], dp[n+1][i][1], dp[n+2][i][1]}) << " ";
	cout << endl;

	return 0;
}