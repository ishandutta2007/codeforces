#include <bits/stdc++.h>
using namespace std;

void work() {
	int n, k, z;
	scanf("%d%d%d", &n, &k, &z);
	vector <int> a;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	vector < vector <int> > dp(n + 1, vector <int> (z + 1));
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + a[i];
		for (int k = 1; k <= z; k++) {
			dp[i][k] = max(dp[i - 1][k] + a[i], dp[i][k - 1] + a[i - 1] + a[i]);
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int step = i;
		if (step > k) break;
		ans = max(ans, dp[i][0]);
		if (step < k && z) ans = max(ans, dp[i][0] + a[i - 1]);
		for (int s = 1; s <= z; s++) {
			step += 2;
			if (step > k) break;
			ans = max(ans, dp[i][s]);
			if (step < k && s < z) ans = max(ans, dp[i][s] + a[i - 1]);
		}
	}
	printf("%d\n", ans + a[0]);
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();

}