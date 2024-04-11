#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxd = 5;
const int Maxn = 1010;
const int Maxm = 1 << 16;
const int Inf = 1000000000;

int n;
int cost[Maxd];
string B[Maxd];
int rmask[Maxn];
vector <int> masks[Maxd];
int cur, dp[2][Maxm];

int getId(int r, int c)
{
	return r * 4 + c;
}

int addRow(int mask, int row)
{
	mask >>= 4;
	if (row < n) mask |= rmask[row] << 12;
	return mask;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < Maxd; i++) {
		scanf("%d", &cost[i]);
		for (int j = 0; j + i <= 4; j++) {
			int mask = (Maxm - 1);
			for (int r = 0; r < i; r++)
				for (int c = j; c < j + i; c++)
					mask ^= 1 << getId(r, c);
			masks[i].push_back(mask);
		}
	}
	for (int i = 0; i < 4; i++)
		cin >> B[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			rmask[i] |= int(B[j][i] == '*') << j;
	fill((int*)dp, (int*)dp + 2 * Maxm, Inf);
	int my = 0;
	for (int i = 0; i < 4; i++)
		my = addRow(my, i);
	dp[cur][my] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = Maxm - 1; j >= 0; j--) if (dp[cur][j] < Inf) {
			if (!(j & 15)) {
				int nj = addRow(j, i + 4);
				dp[!cur][nj] = min(dp[!cur][nj], dp[cur][j]);
			}
			for (int k = 1; k < Maxd && i + k <= n; k++)
				for (int z = 0; z < masks[k].size(); z++) {
					int nj = (j & masks[k][z]);
					dp[cur][nj] = min(dp[cur][nj], dp[cur][j] + cost[k]);
				}
			dp[cur][j] = Inf;
		}
		cur = !cur;
	}
	printf("%d\n", dp[cur][0]);
	return 0;
}