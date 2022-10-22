#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int t, n;
long long memo[2000005][2];

int main() {
	scanf("%d", &t);
	for (int i = 3; i < 2000005; i++) {
		memo[i][0] = max(memo[i - 1][0], memo[i - 1][1]) + max(memo[i - 2][0], memo[i - 2][1]) * 2;
		memo[i][0] %= MOD;
		memo[i][1] = memo[i - 1][0] + memo[i - 2][0] * 2 + 1;
		memo[i][1] %= MOD;
	}
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", (max(memo[n][0], memo[n][1]) * 4) % MOD);
	}
	return 0;
}