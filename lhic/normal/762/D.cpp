#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120000;
const ll INF = 1e18;

ll dp[MAXN][3][2];
ll a[MAXN][3];
int n;

void upd(ll &a, ll b) {
	a = max(a, b);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lld", &a[j][i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 2; ++k)
				dp[i][j][k] = -INF;
	dp[0][0][0] = a[0][0];
	for (int i = 0; i < n - 1; ++i) {
		upd(dp[i + 1][0][0], dp[i][0][0] + a[i + 1][0]);
		upd(dp[i + 1][0][1], dp[i][0][0] + a[i + 1][0]);
		upd(dp[i + 1][1][0], dp[i][0][0] + a[i][1] + a[i + 1][1]);
		upd(dp[i + 1][2][0], dp[i][0][0] + a[i][1] + a[i][2] + a[i + 1][2]);
		upd(dp[i + 1][1][0], dp[i][1][0] + a[i + 1][1]);
		upd(dp[i + 1][0][0], dp[i][1][0] + a[i][0] + a[i + 1][0]);
		upd(dp[i + 1][2][0], dp[i][1][0] + a[i][2] + a[i + 1][2]);
		upd(dp[i + 1][2][0], dp[i][2][0] + a[i + 1][2]);
		upd(dp[i + 1][2][1], dp[i][2][0] + a[i + 1][2]);
		upd(dp[i + 1][1][0], dp[i][2][0] + a[i][1] + a[i + 1][1]);
		upd(dp[i + 1][0][0], dp[i][2][0] + a[i][1] + a[i][0] + a[i + 1][0]);
		if (i > 0) {
			upd(dp[i + 1][2][0], dp[i][0][1] + a[i][1] + a[i][2] + a[i - 1][1] + a[i - 1][2] + a[i + 1][2]);
			upd(dp[i + 1][0][0], dp[i][2][1] + a[i][1] + a[i][0] + a[i - 1][1] + a[i - 1][0] + a[i + 1][0]);
		}
	}
	ll ans = -INF;
	upd(ans, dp[n - 1][2][0]);
	upd(ans, dp[n - 1][1][0] + a[n - 1][2]);
	upd(ans, dp[n - 1][0][0] + a[n - 1][1] + a[n - 1][2]);
	if (n > 1)
		upd(ans, dp[n - 1][0][1] + a[n - 1][1] + a[n - 1][2] + a[n - 2][1] + a[n - 2][2]);
	cout << ans << "\n";
	return 0;
}