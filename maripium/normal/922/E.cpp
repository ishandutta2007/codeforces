#include <iostream>
#include <cstring>
using namespace std;

long long dp[1005][10005];

int main() {
	long long n, w, b, x, sum = 0, ans = 0;
	cin >> n >> w >> b >> x;
	long long c[n], cost[n];
	for(long long i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
	}
	for(long long i = 0; i < n; i++) cin >> cost[i];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = w;
	for(long long i = 1; i <= n; i++) {
		for(long long j = 0; j <= sum; j++) {
			for(long long k = 0; k <= min(j, c[i-1]); k++) {
				if(dp[i-1][j-k] >= 0 && min(dp[i-1][j-k] + x, w + (j - k) * b) - cost[i-1] * k >= 0) {
					dp[i][j] = max(dp[i][j], min(min(dp[i-1][j-k] + x, w + (j - k) * b) - cost[i-1] * k, w + j*b));
					ans = max(ans, j);
				}
			}
		}
	}
	cout << ans;
}