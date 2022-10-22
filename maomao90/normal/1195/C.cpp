#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int h[2][100005];

long long memo[100005][5];
long long dp(int i, int prev) {
	if (i >= n) return 0;
	if (memo[i][prev] != -1) return memo[i][prev];
	return memo[i][prev] = max(dp(i + 1, 1 - prev) + h[1 - prev][i], dp(i + 1, prev));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) scanf("%d", &h[i][j]);
	memset(memo, -1, sizeof memo);
	printf("%lld\n", max(dp(0, 0), dp(0, 1)));
	return 0;
}