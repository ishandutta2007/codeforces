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

const ll INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const ll MAXN = 5100;
int n, s, e;

ll dp[MAXN];
ll dp2[MAXN];
int x[MAXN];
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];

int main() {
	scanf("%d%d%d", &n, &s, &e);
	--s;
	--e;
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", d + i);
	for (int i = 1; i <= n; ++i)
		dp[i] = INF;
	for (int i = n - 1; i >= 0; --i) {
		fill(dp2, dp2 + n + 1, INF);
		for (int j = 0; j <= n; ++j) {
			if (dp[j] >= INF)
				continue;
			ll now = dp[j];
			int l = j;
			int r = j;
			if (i < n - 1) {
				now += ((ll)x[i + 1] - x[i]) * 2ll * (ll)j;
				if (s > i)
					now -= (x[i + 1] - x[i]), --r;
				if (e > i)
					now -= (x[i + 1] - x[i]), --l;
			}
			if (i != s && i != e) {
				if (r > 0)
					dp2[j] = min(dp2[j], now + d[i] + a[i]);
				if (l > 0)
					dp2[j] = min(dp2[j], now + c[i] + b[i]);
				if (j > 0 && l > 0 && r > 0)
					dp2[j - 1] = min(dp2[j - 1], now + b[i] + d[i]);
				dp2[j + 1] = min(dp2[j + 1], now + a[i] + c[i]);
			}
			else if (i == s) {
				dp2[j + 1] = min(dp2[j + 1], now + c[i]);
				if (r > 0)
					dp2[j] = min(dp2[j], now + d[i]);
			}
			else {
				dp2[j + 1] = min(dp2[j + 1], now + a[i]);
				if (l > 0)
					dp2[j] = min(dp2[j], now + b[i]);
			}
		}
		dp2[0] = INF;
		if (i > 0 && s >= i && e >= i)
			dp2[1] = INF;
		memcpy(dp, dp2, sizeof(dp2));
	}
	cout << dp[1] << "\n";
	return 0;
}