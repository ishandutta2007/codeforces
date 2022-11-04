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

const int MX = 1000005, mod = 998244353;
int n, ini[MX], dis[MX], dp[MX][3];
vi v;

/*ll dp (int n, int f) {
	if (n == 0) return 1;
	if (n == 1) return f != 2;
	ll &res = mem[n][f];
	if (res != -1) return res;
	res = 0;

	for (int a = max(0, ini[n] - (dis[n] >> 1)); a <= ini[n] && a <= (dis[n] >> 1); a++) {
		int b = ini[n] - a;
		if (f == 1 && (((dis[n] >> 1) - 1 + b) & 1) == 1) continue;
		if (f == 2 && (((dis[n] >> 1) - 1 + a) & 1) == 0) continue;
		res += dp(dis[n] / 2 - 1 + a, 1) * dp(dis[n] / 2 - 1 + b, 2);
	}

	return res;
}*/

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	ini[1] = 1, dis[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (ini[i-1] == dis[i-1])
			ini[i] = 1, dis[i] = 2 * dis[i-1];
		else
			ini[i] = ini[i-1] + 1, dis[i] = dis[i-1];
	}

	dp[0][1] = dp[0][2] = 1;
	dp[1][1] = 1;
	v = {0, 1};

	for (int i = 2; i <= n; i++) {
		for (int j : v) {
			int a = j - dis[i] / 2 + 1;
			if (max(0, ini[i] - dis[i] / 2) <= a && a <= min(ini[i], dis[i] / 2)) {
				int b = ini[i] - a;
				if (i == n || (dis[i] / 2 - 1 + b) % 2 == 0) dp[i][1] += dp[dis[i] / 2 - 1 + a][1] * dp[dis[i] / 2 - 1 + b][2];
				if (i == n || (dis[i] / 2 - 1 + a) % 2 == 1) dp[i][2] += dp[dis[i] / 2 - 1 + a][1] * dp[dis[i] / 2 - 1 + b][2];
			}
		}

		if (dp[i][1] || dp[i][2])
			v.pb(i);
	}

	cout << (dp[n][1] | dp[n][2]) << endl;

	return 0;
}