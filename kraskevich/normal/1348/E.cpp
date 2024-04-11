#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
 
const ll INF = (ll)1e18;
 
const int N = 505;
 
ll dp[N][N];
ll a[N];
ll b[N];
 
int main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int ra = 0; ra < k; ra++) {
			dp[i][ra] = -INF;
		}
	}
	dp[0][0] = 0;
	ll sa = 0;
	ll sb = 0;
	for (int pos = 0; pos < n; pos++) {
		for (int ra = 0; ra < k; ra++) {
			for (int add_ra = 0; add_ra < min<int>(k, a[pos] + 1); add_ra++) {
				if (dp[pos][ra] == -INF) {
					continue;
				}
				int rb = sa + sb - dp[pos][ra] * k - ra;
				assert(0 <= rb && rb < k);
				ll tot_pos = (a[pos] - add_ra) + b[pos];
				ll add = tot_pos / k;
				int add_rb = tot_pos - add * k;
				if (add_rb > b[pos]) {
					continue;
				}
				if (ra + add_ra >= k) {
					add++;
				}
				if (rb + add_rb >= k) {
					add++;
				}
				int new_ra = (ra + add_ra) % k;
				dp[pos + 1][new_ra] = max(dp[pos + 1][new_ra], dp[pos][ra] + add);
			}
		}
		sa += a[pos];
		sb += b[pos];
	}
	if (k == 1) {
		cout << sa + sb << "\n";
		return 0;
	}
	ll res = 0;
	for (int ra = 0; ra < k; ra++) {
		res = max(res, dp[n][ra]);
	}
	cout << res;
}