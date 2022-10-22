#include <bits/stdc++.h>
using namespace std;

int t;
int n, p, k;
char a[100005];
int x, y;

int memo[100005];
int dp(int i) {
	if (i >= n) return 0;
	if (memo[i] != -1) return memo[i];
	memo[i] = dp(i + k);
	if (a[i] == '0') memo[i] += x;
	return memo[i];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &p, &k);
		scanf(" %s", a);
		scanf("%d%d", &x, &y);
		memset(memo, -1, sizeof memo);
		int ans = 1000000005;
		for (int i = 0; i < n; i++) {
			if (i + p - 1 >= n) break;
			ans = min(ans, dp(i + p - 1) + y * i);
		}
		printf("%d\n", ans);
	}
	return 0;
}