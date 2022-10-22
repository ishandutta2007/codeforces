#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 105;
const int Maxm = 100005;

int n, m;
ld dp[Maxn][Maxm];
int myrank;

int main()
{
	scanf("%d %d", &n, &m); int M = n * m;
	if (m == 1) { printf("1.00000000000\n"); return 0; }
	dp[0][0] = 1; dp[0][1] = -1;
	for (int i = 0; i < n; i++) {
		int pl; scanf("%d", &pl); myrank += pl;
		ld cur = 0;
		for (int j = 0; j <= M; j++) {
			cur += dp[i][j];
			ld give = cur / ld(m - 1);
			dp[i + 1][j + 1] += give; dp[i + 1][min(M + 1, j + pl)] -= give;
			dp[i + 1][min(M + 1, j + pl + 1)] += give; dp[i + 1][min(M + 1, j + m + 1)] -= give;
		}
	}
	ld one = 0.0l;
	ld cur = 0;
	for (int j = 0; j <= M && j < myrank; j++) {
		cur += dp[n][j];
		one += cur;
	}
	cout << fixed << setprecision(16) << 1.0l + one * ld(m - 1) << endl;
	return 0;
}