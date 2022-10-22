#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 16;
const int Maxm = 200;
const int Inf = 1000000000;

int n;
char C[Maxn];
int R[Maxn], B[Maxn];
int sumr, sumb;
int dp[1 << Maxn][Maxm];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %d %d", &C[i], &R[i], &B[i]);
		sumr += R[i]; sumb += B[i];
	}
	fill((int*)dp, (int*)dp + (1 << Maxn) * Maxm, -1);
	dp[0][0] = 0;
	for (int i = 0; i + 1 < 1 << n; i++) {
		int hadr = 0, hadb = 0;
		for (int j = 0; j < n; j++)
			if (i & 1 << j)
				if (C[j] == 'R') hadr++;
				else hadb++;
		for (int j = 0; j < Maxm; j++) if (dp[i][j] != -1) {
			for (int k = 0; k < n; k++) if (!(i & 1 << k)) {
				int nwr = j + min(R[k], hadr);
				int nwb = dp[i][j] + min(B[k], hadb);
				dp[i | 1 << k][nwr] = max(dp[i | 1 << k][nwr], nwb);
			}
		}
	}
	int goal = (1 << n) - 1;
	int res = Inf;
	for (int j = 0; j < Maxm; j++) if (dp[goal][j] != -1)
		res = min(res, max(sumr - j, sumb - dp[goal][j]));
	printf("%d\n", res + n);
	return 0;
}