#include <iostream>
using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;
const int N = 1e6;
const int M = 20;
ll dp[M][3]; // Power of 2, power of 3
ll cou[M][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int mj = 0;
	for (int i = 0; (1<<i) <= n; ++i) {
		cou[i][0] = n / (1<<i);
		cou[i][1] = n / (3 * (1<<i));
		mj = i;
	}

	// Possible first values
	dp[mj][0] = cou[mj][0];
	if (mj > 0) dp[mj-1][1] = cou[mj-1][1];

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= mj; ++j) {
			for (int t = 0; t <= 1; ++t) {
				ll nxt = dp[j][t] * max((ll)0, (cou[j][t] - i)) % MOD;
				nxt += (dp[j+1][t] * max((ll)0, (cou[j][t] - i - max((ll)0, cou[j+1][t] - i))) % MOD);
				nxt += (dp[j][t+1] * max((ll)0, (cou[j][t] - i - max((ll)0, cou[j][t+1] - i))) % MOD);
				dp[j][t] = nxt % MOD;
			}
		}
	}
	cout << dp[0][0] << '\n';
}