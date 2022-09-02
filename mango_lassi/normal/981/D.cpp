#include <iostream>
typedef long long ll;

const int N = 50;
const int K = 50 + 1;
ll vals[N];
int dp[N + 1][K + 1];

void clear() {
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1;
}

bool canDo(ll v, int n, int k) {
	if (dp[n][k] != -1) return dp[n][k];
	int ans = 0;
	ll sum = 0;
	for (int i = n-1; i >= 0; --i) {
		sum += vals[i];
		if ((v & sum) == v) {
			if (canDo(v, i, k - 1)) ans = 1;
		}
	}
	dp[n][k] = ans;
	return ans;
}

int main() {
	int k, n;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> vals[i];
	}
	ll ans = 0;
	for (ll j = (1ll)<<62; j > 0; j >>= 1) {
		clear();
		if (canDo(ans | j, n, k)) {
			ans |= j;
		}
	}
	std::cout << ans << '\n';
}