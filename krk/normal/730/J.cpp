#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 102;
const int Maxm = Maxn * Maxn;
const int Inf = Maxm * Maxm;

int n;
int a[Maxn], b[Maxn];
int dp[Maxn][Maxm];

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	fill((int*)dp, (int*)dp + Maxn * Maxm, Inf); dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j >= 0; j--)
			for (int k = Maxm - 1; k >= 0; k--) if (dp[j][k] < Inf) {
				dp[j + 1][k + b[i]] = min(dp[j + 1][k + b[i]], dp[j][k]);
				dp[j][k] += a[i];
			}
	for (int i = 0; i <= n; i++) {
		int res = Inf;
		for (int j = sum; j < Maxm; j++)
			res = min(res, dp[i][j]);
		if (res != Inf) { printf("%d %d\n", i, res); return 0; }
	}
	return 0;
}