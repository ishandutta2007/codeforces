#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
int n, m, q, cnt[1 << 12], w[12];
int res[1 << 12][101];
void dfs(int i, int cur, int mask, int sum) {
	if (i == n) {
		if (sum <= 100)res[mask][sum] += cnt[cur];
		return;
	}
	for (int j = 0; j < 2; j++) {
		dfs(i + 1, cur + (j ? 1 << i : 0), mask, sum + ((j == (mask&(1 << i) ? 1 : 0)) ? w[i] : 0));
	}
}
int main() {
	char s[99];
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)scanf("%d", &w[i]);
	while (m--) {
		scanf("%s", s);
		int h = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				h += 1 << i;
		cnt[h] ++;
	}
	for (int i = 0; i < (1<<n); i++) {
		dfs(0, 0, i, 0);
		for (int j = 1; j <= 100; j++)
			res[i][j] += res[i][j - 1];
	}
	while (q--) {
		int x;
		scanf("%s%d", s, &x);
		int h = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				h += 1 << i;
		printf("%d\n", res[h][x]);
	}
	return 0;
}