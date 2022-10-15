/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MOD 1000000007

int n;
char s[80];

int check(int l, int r) {
	int ret = (s[l]=='1');
	while (l++ != r) {
		ret = ret << 1 | (s[l] == '1');
	}
	return ret;
}
vector<int> dp[80];
int ans = 0, top[80], map[80][80];

int get(int x) {
	int k = 1;
	while (k <= x)  k <<= 1;
	return k - 1;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	memset(map, -1, sizeof(map));
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			map[i][j] = check(i, j) - 1;
			if (map[i][j] >= 20) {map[i][j] = -1; break;}
		}
	dp[0].resize(262144); dp[0][0] = 1; top[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i].resize(262144); dp[i][0] = 1; top[i] = 0;
		for (int j = i; j; j--) {
			if (map[j][i] == -1) continue;
			int v = 1<<map[j][i]; int q = j - 1;;
			top[i] = max(top[i], get(top[q]|v));
			if (dp[i].size() <= top[i]) dp[i].resize(top[i] + 1);
			for (int k = top[q]; k > -1; k--) if ((dp[i][k | v] += dp[q][k]) >= MOD) dp[i][k | v] -= MOD;
		}
		while (top[i] && !dp[i][top[i]]) top[i]--;
		for (int k = 1; k <= top[i]; k = ((k + 1) << 1) - 1) {
			if ((ans += dp[i][k]) >= MOD) ans -= MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}