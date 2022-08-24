#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

char s[20][100010];
int n, m;
int dp[1 << 21][21];

void add(int x) {
	int cnt = __builtin_popcount(x);
	int now = 0;
	for (int i = 0; i < n; ++i) {
		++dp[now][cnt];
		if ((x >> i) & 1)
			now = now * 2 + 2;
		else
			now = now * 2 + 1;
	}
	++dp[now][cnt];
}

void rchange(int now, int h, int dst) {
	if (h == dst) {
		dp[now][0] = dp[now * 2 + 2][1];
		dp[now][n] = dp[now * 2 + 1][n - 1];
		for (int i = 1; i < n; ++i)
			dp[now][i] = dp[now * 2 + 1][i - 1] + dp[now * 2 + 2][i + 1];
	}
	else {
		rchange(now * 2 + 1, h + 1, dst);
		rchange(now * 2 + 2, h + 1, dst);
		for (int i = 0; i <= n; ++i)
			dp[now][i] = dp[now * 2 + 1][i] + dp[now * 2 + 2][i];
	}
}


void change(int x) {
	rchange(0, 0, x);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf(" %s", s[i]);
	for (int i = 0; i < m; ++i) {
		int k = 0;
		for (int j = 0; j < n; ++j)
			k = k * 2 + (s[j][i] - '0');
		add(k);
	}
	int ans = n * m;
	for (int i = 0; i < (1 << n); ++i) {
		int sm = 0;
		for (int j = 0; j <= n; ++j)
			sm += min(j, n - j) * dp[0][j];
		ans = min(ans, sm);
		if (i + 1 != (1 << n)) {
			for (int j = 0; j < n; ++j)
				if (((i >> j) & 1) == 0) {
					change(j);
					break;
				}
		}
	}
	cout << ans << "\n";
	return 0;
}