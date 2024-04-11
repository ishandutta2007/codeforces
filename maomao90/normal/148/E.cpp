#include <bits/stdc++.h>
using namespace std;

int n, m;
int sze[105];
int items[105][105];
int maxval[105][105];

int memo[105][10005];
int dp(int i, int rem) {
	if (i >= n) return 0;
	if (rem == 0) return 0;
	if (memo[i][rem] != -1) return memo[i][rem];
	int curmax = 0;
	for (int j = 0; j <= sze[i]; j++) {
		if (j > rem) break;
		curmax = max(curmax, dp(i + 1, rem - j) + maxval[i][j]);
	}
	return memo[i][rem] = curmax;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sze[i]);
		for (int j = 0; j < sze[i]; j++) {
			scanf("%d", &items[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= sze[i]; j++) {
			int cur = 0;
			for (int k = sze[i] - 1; k >= sze[i] - j; k--) 
				cur += items[i][k];
			for (int k = 0; k <= j; k++) {
				maxval[i][j] = max(maxval[i][j], cur);
				cur -= items[i][sze[i] - j + k];
				cur += items[i][k];
			}
		}
	}
	memset(memo, -1, sizeof memo);
	printf("%d\n", dp(0, m));
	return 0;
}