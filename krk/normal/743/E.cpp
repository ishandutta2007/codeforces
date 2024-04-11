#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxm = 8;
const int Maxt = 130;

int n;
int a[Maxn];
int pos[Maxn][Maxt];
int lst[Maxm];
int dp[Maxn][1 << Maxm];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i]--;
	}
	for (int i = 0; i < Maxt; i++)
		pos[n][i] = n + 1;
	for (int i = 0; i < Maxm; i++)
		lst[i] = n;
	for (int i = n - 1; i >= 0; i--) {
		int val = a[i];
		pos[i][1] = i + 1;
		for (int j = 2; j < Maxt; j++)
			pos[i][j] = pos[lst[val]][j - 1];
		lst[val] = i;
	}
	for (int i = 125; i > 0; i--) {
		fill((int*)dp, (int*)dp + Maxn * (1 << Maxm), -10000000); dp[0][0] = 0;
		for (int j = 0; j < n; j++) {
			int val = a[j];
			for (int k = 0; k < 1 << Maxm; k++) {
				dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
				if (!(k & 1 << val)) {
					int nj = pos[j][i];
					if (nj <= n) dp[nj][k | 1 << val] = max(dp[nj][k | 1 << val], dp[j][k] + i);
					nj = pos[j][i + 1];
					if (nj <= n) dp[nj][k | 1 << val] = max(dp[nj][k | 1 << val], dp[j][k] + i + 1);
				}
			}
		}
		int res = dp[n][(1 << Maxm) - 1];
		if (res >= 0) { printf("%d\n", res); return 0; }
	}
	int mask = 0;
	for (int i = 0; i < n; i++)
		mask |= 1 << a[i];
	printf("%d\n", __builtin_popcount(mask));
	return 0;
}