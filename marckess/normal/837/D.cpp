#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
//
typedef vector<ll> vi;
//
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

const ll LOG = log(1e18) / log(5);

typedef vector<vvi> vvvi;
vvvi dp(2, vvi(205, vi(200 * LOG + 5, -1e9)));
ll n, k, a;
vi p2(205), p5(205);

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a;

		for (ll x = a; x % 2 == 0; x /= 2)
			p2[i]++;

		for (ll x = a; x % 5 == 0; x /= 5)
			p5[i]++;
	}

	dp[n%2][0][0] = 0;

	for (int i = n - 1; i >= 0; i--) {
		int l = i % 2;
		dp[l][0][0] = 0;

		for (int j = 0; j <= k; j++) {
			if (j)
				for (int k = 0; k <= 200 * LOG; k++) {
					dp[l][j][k] = dp[1-l][j][k];
					if (k - p5[i] >= 0)
						dp[l][j][k] = max(dp[l][j][k], dp[1-l][j-1][k-p5[i]] + p2[i]);
				}
			else
				for (int k = 1; k <= 200 * LOG; k++)
					dp[l][j][k] = -1e9;
		}
	}

	ll res = 0;
	for (int i = 0; i <= 200 * LOG; i++)
		res = max(res, min(dp[0][k][i], ll(i)));

	cout << res << endl;

	return 0;
}