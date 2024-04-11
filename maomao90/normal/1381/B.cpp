#include <bits/stdc++.h>
using namespace std;

#define INF 1000000005

int t;
int n;
int c[4005];
int dp[4005];
int memo[4005][4005];
bool dp2(int i, int j) {
	if (i > n || j > n) return false;
	if (i == j && i >= n) return true;
	if (memo[i][j] != -1) return memo[i][j];
	bool isPos = false;
	isPos |= dp2(i + dp[i + j], j);
	isPos |= dp2(i, j + dp[i + j]);
	return memo[i][j] = isPos;
}

int main() {
scanf("%d", &t);
while (t--) {
	scanf("%d", &n);
	for (int i = 0; i < n * 2; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n * 2; i++) {
		dp[i] = 1;
		for (int j = i + 1; j < n * 2; j++) {
			if (c[i] > c[j]) {
				dp[i]++;
			} else break;
		}
	}
for (int i = 0; i < 2 * n + 1; i++) {
for (int j = 0; j < 2 * n + 1; j++) {
memo[i][j] = -1;
}
}
	if (dp2(0, 0)) printf("Yes\n");
	else printf("No\n");
}
	return 0;
}