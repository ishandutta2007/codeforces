#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 505;
const int Maxk = 11;

int n, m, k;
int R[Maxn][Maxn];
int D[Maxn][Maxn];
int dp[Maxk][Maxn][Maxn];
vector <ii> seq;
ii mseq[Maxn * Maxn];
int len;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if (k % 2) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				printf("-1%c", j + 1 < m? ' ': '\n');
		return 0;
	}
	k /= 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < m; j++)
			scanf("%d", &R[i][j]);
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &D[i][j]);
	fill((int*)dp, (int*)dp + Maxk * Maxn * Maxn, Inf);
	for (int i = -k; i <= k; i++)
		for (int j = -k; j <= k; j++)
			if (abs(i) + abs(j) <= k)
				seq.push_back(ii(i, j));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			for (int z = 0; z < seq.size(); z++) {
				int ni = i + seq[z].first;
				int nj = j + seq[z].second;
				if (0 <= ni && ni < n && 0 <= nj && nj < m)
					mseq[len++] = ii(ni, nj);
			}
			dp[0][i][j] = 0;
			for (int l = 0; l < k; l++)
				for (int z = 0; z < len; z++) {
					int r = mseq[z].first;
					int c = mseq[z].second;
					if (dp[l][r][c] >= Inf) continue;
					if (r + 1 < n)
						dp[l + 1][r + 1][c] = min(dp[l + 1][r + 1][c], dp[l][r][c] + D[r][c]);
					if (r - 1 >= 0)
						dp[l + 1][r - 1][c] = min(dp[l + 1][r - 1][c], dp[l][r][c] + D[r - 1][c]);
					if (c + 1 < m)
						dp[l + 1][r][c + 1] = min(dp[l + 1][r][c + 1], dp[l][r][c] + R[r][c]);
					if (c - 1 >= 0)
						dp[l + 1][r][c - 1] = min(dp[l + 1][r][c - 1], dp[l][r][c] + R[r][c - 1]);
				}
			int res = Inf;
			for (int z = 0; z < len; z++) {
				int r = mseq[z].first;
				int c = mseq[z].second;
				res = min(res, dp[k][r][c]);
				for (int l = 0; l <= k; l++)
					dp[l][r][c] = Inf;
			}
			len = 0;
			printf("%d%c", 2 * res, j + 1 < m? ' ': '\n');
		}
    return 0;
}