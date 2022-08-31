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

const int LOG = 30;
const int MAXN = 1020;
const ll MOD = 7340033;

ll dp[LOG][MAXN];
ll tmp[MAXN];


void init() {
	dp[0][0] = 1;
	for (int i = 1; i < LOG; ++i) {
		for (int j = 0; j < MAXN - 1; ++j)
			dp[i][j + 1] = dp[i - 1][j];
		dp[i][0] = 0;
		for (int it = 0; it < 3; ++it) {
			memset(tmp, 0, sizeof(tmp));
			for (int i1 = 0; i1 < MAXN; ++i1)
				for (int j1 = 0; i1 + j1 < MAXN; ++j1)
					tmp[i1 + j1] = (tmp[i1 + j1] + dp[i - 1][i1] * dp[i][j1]) % MOD;
			memcpy(dp[i], tmp, sizeof(tmp));
		}
		dp[i][0] = 1;
	}
}

int main() {
	init();
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int cnt = 0;
		while (n >= 3 && n % 2 == 1) {
			++cnt;
			n = (n - 1) / 2;
		}
		printf("%lld\n", dp[cnt][k]);
	}
	return 0;
}