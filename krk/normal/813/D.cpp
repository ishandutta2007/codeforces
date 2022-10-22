#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Maxe = 100005;
const int Maxr = 7;

int n;
int a[Maxn];
int lste[Maxe], lstr[Maxr];
int dp[Maxn][Maxn], dpone[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	fill(lste, lste + Maxe, n); fill(lstr, lstr + Maxr, n);
	fill((int*)dp, (int*)dp + Maxn * Maxn, -1000000000);
	for (int i = 0; i < n; i++)
		dp[i][n] = dp[n][i] = 1;
	dp[n][n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			int r = a[j] % Maxr, e = a[j];
			int res = 1 + max(dp[lstr[r]][i], max(dp[lste[e + 1]][i], dp[lste[e - 1]][i]));
			r = a[i] % Maxr, e = a[i];
			res = max(res, 1 + max(dp[j][lstr[r]], max(dp[j][lste[e + 1]], dp[j][lste[e - 1]])));
			dp[i][j] = dp[j][i] = res;
		}
		lste[a[i]] = i; lstr[a[i] % Maxr] = i;
	}
	fill(lste, lste + Maxe, -1); fill(lstr, lstr + Maxr, -1);
	for (int i = 0; i < n; i++) {
		int res = 0;
		int r = a[i] % Maxr, e = a[i];
		if (lstr[r] != -1) res = max(res, 1 + dpone[lstr[r]]);
		if (lste[e + 1] != -1) res = max(res, 1 + dpone[lste[e + 1]]);
		if (lste[e - 1] != -1) res = max(res, 1 + dpone[lste[e - 1]]);
		dpone[i] = res;
		lste[e] = i; lstr[r] = i;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			res = max(res, dpone[i] + dp[i][j]);
	printf("%d\n", res);
	return 0;
}