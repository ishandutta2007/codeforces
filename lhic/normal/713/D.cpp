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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int LOG = 10;
const int MAXN = 1010;
int up[LOG][LOG][MAXN][MAXN];
int n, m;
int dp[MAXN][MAXN];
int a[MAXN][MAXN];
int pr[MAXN];

int get(int x1, int y1, int x2, int y2) {
	int k = pr[x2 - x1 + 1];
	int l = pr[y2 - y1 + 1];
	return max({up[k][l][x1][y1], up[k][l][x2 - (1 << k) + 1][y2 - (1 << l) + 1], up[k][l][x1][y2 - (1 << l) + 1], up[k][l][x2 - (1 << k) + 1][y1]});
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= max(n, m); ++i) {
		int k = 0;
		while ((1 << (k + 1)) <= i)
			++k;
		pr[i] = k;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (!a[i][j])
				dp[i][j] = 0;
			else
				dp[i][j] = min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]}) + 1;
		}
	}
	for (int i = 0; i < LOG; ++i)
		for (int j = 0; j < LOG; ++j) {
			for (int k = 0; k < n; ++k)
				for (int l = 0; l < m; ++l) {
					if (i != 0) {
						up[i][j][k][l] = up[i - 1][j][k][l];
						if (k + (1 << (i - 1)) < n)
							up[i][j][k][l] = max(up[i][j][k][l], up[i - 1][j][k + (1 << (i - 1))][l]);
					}
					else if (j != 0) {
						up[i][j][k][l] = up[i][j - 1][k][l];
						if (l + (1 << (j - 1)) < m)
							up[i][j][k][l] = max(up[i][j][k][l], up[i][j - 1][k][l + (1 << (j - 1))]);
					}
					else {
						up[0][0][k][l] = dp[k][l];
					}
				}
		}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		--x1, --y1, --x2, --y2;
		int l = 0;
		int r = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (get(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid)
				l = mid;
			else
				r = mid;
		}
		printf("%d\n", l);
	}
	return 0;
}