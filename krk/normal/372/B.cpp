#include <cstdio>
using namespace std;

const int Maxn = 42;

int n, m, q;
int tot[Maxn][Maxn];
int cnt[Maxn][Maxn][Maxn][Maxn];
int dp[Maxn][Maxn];
int res;

bool Empty(int r1, int c1, int r2, int c2)
{
	return (tot[r2][c2] - tot[r1 - 1][c2] - tot[r2][c1 - 1] + tot[r1 - 1][c1 - 1]) == 0;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char ch; scanf(" %c", &ch);
			tot[i][j] = (ch == '1') + tot[i - 1][j] + tot[i][j - 1] - tot[i - 1][j - 1];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cnt[i][j][i][j] = Empty(i, j, i, j);
			for (int j2 = j - 1; j2 > 0; j2--)
				cnt[i][j][i][j2] = Empty(i, j2, i, j) + cnt[i][j][i][j2 + 1];
			for (int i2 = i - 1; i2 > 0; i2--)
				cnt[i][j][i2][j] = Empty(i2, j, i, j) + cnt[i][j][i2 + 1][j];
			for (int i2 = i - 1; i2 > 0; i2--)
				for (int j2 = j - 1; j2 > 0; j2--)
					cnt[i][j][i2][j2] = Empty(i2, j2, i, j) + cnt[i][j][i2 + 1][j2] + cnt[i][j][i2][j2 + 1] - cnt[i][j][i2 + 1][j2 + 1];
		}
	while (q--) {
		int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		res = 0;
		for (int i = r1; i <= r2; i++)
			for (int j = c1; j <= c2; j++)
				res += cnt[i][j][r1][c1];
		printf("%d\n", res);
	}
	return 0;
}