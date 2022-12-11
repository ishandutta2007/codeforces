#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long n, m;
long long a[N], b[N], l, r, ans;

inline void init() {
	int it = 1;
	for (int i = 2; i <= n; i++)
		if (a[i + 1] - a[i] > a[it + 1] - a[it]) it = i;
	r = a[it + 1] - a[it] - 1;
	for (int i = 1; i <= n; i++) b[i] = a[i + it];
	long long tmp = b[1];
	for (int i = 1; i <= n; i++) b[i] -= tmp;
}

long long dp[N];
inline bool check(long long x) {
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i - 1] >= b[i] - 1) dp[i] = max(dp[i], b[i] + x);
		if (dp[i - 1] >= b[i] - x - 1) dp[i] = max(dp[i], b[i]);
		if (i > 2 && dp[i - 2] >= b[i] - x - 1) dp[i] = max(dp[i], b[i - 1] + x);
	}
	if (dp[n] >= m - x - 1) return 1;
	dp[2] = max(b[2], x);
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i - 1] >= b[i] - 1) dp[i] = max(dp[i], b[i] + x);
		if (dp[i - 1] >= b[i] - x - 1) dp[i] = max(dp[i], b[i]);
		if (dp[i - 2] >= b[i] - x - 1) dp[i] = max(dp[i], b[i - 1] + x);
	}
	if (dp[n] >= min(m - 1, m + b[2] - x - 1)) return 1;
	return 0;
}

int main() {
	scanf("%lld%lld", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i + n] = a[i] + m;
	}
	if (n == 1) {
		printf("%lld", m - 1);
		return 0;
	}
	sort(a + 1, a + (n << 1) + 1);
	init();
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%lld\n", ans);
}