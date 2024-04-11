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

const int Maxn = 1005;
const int Maxk = 52;
const int Inf = 1000000000;

int n, p, k;
int A[Maxn], B[Maxn], C[Maxn];
short dp[Maxn][Maxn][Maxk][2];

short Get(int wh, int l, int r)
{
	l = max(l, 1), r = min(r, Maxn - 1);
	if (l > r) return 0;
	return wh == 0? A[r] - A[l - 1]: B[r] - B[l - 1];
}

short getBoth(int l, int r)
{
	l = max(l, 1), r = min(r, Maxn - 1);
	if (l > r) return 0;
	return C[r] - C[l - 1];
}

int main()
{
	scanf("%d %d %d", &n, &p, &k);
	int r; scanf("%d", &r);
	while (r--) {
		int a; scanf("%d", &a);
		A[a]++;
		C[a]++;
	}
	int s; scanf("%d", &s);
	while (s--) {
		int b; scanf("%d", &b);
		B[b]++;
		C[b]++;
	}
	for (int i = 1; i < Maxn; i++) {
		A[i] += A[i - 1]; 
		B[i] += B[i - 1];
		C[i] = C[i - 1] + int(C[i] == 2);
	}
	fill((short*)dp, (short*)dp + Maxn * Maxn * Maxk * 2, -Maxn);
	dp[1][p][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = p; j >= 0; j--)
			for (int h = 0; h <= k; h++)
				for (int w = 0; w < 2; w++) if (dp[i][j][h][w] >= 0) {
					short my = dp[i][j][h][w];
					dp[i + 1][j][max(0, h - 1)][w] = max(dp[i + 1][j][max(0, h - 1)][w], my);
					if (j > 0)
						if (h == 0) {
							dp[i][j - 1][k][0] = max(dp[i][j - 1][k][0], (short)(my + Get(0, i, i + k - 1)));
							dp[i][j - 1][k][1] = max(dp[i][j - 1][k][1], (short)(my + Get(1, i, i + k - 1)));
						} else {
							int oth = 1 - w;
							short add = Get(oth, i, i + k - 1) - getBoth(i, i + h - 1);
							int ni = min(i + h, n + 1);
							dp[ni][j - 1][k - h][oth] = max(dp[ni][j - 1][k - h][oth], short(my + add));
						}
				}
			}
	short res = 0;
	for (int j = 0; j <= p; j++)
		for (int h = 0; h <= k; h++)
			for (int w = 0; w < 2; w++)
				res = max(res, dp[n + 1][j][h][w]);
	printf("%d\n", int(res));
	return 0;
}