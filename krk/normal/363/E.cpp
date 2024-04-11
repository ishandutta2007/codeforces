#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int Maxm = 2 * Maxn;

int n, m, r;
int x[Maxn], ox[Maxm];
int sum[Maxn][Maxn];
int my[Maxn][Maxn];
int has[Maxn][Maxn], cnt[Maxn][Maxn];
int res1;
ll res2;

int main()
{
	scanf("%d %d %d", &n, &m, &r);
	int cur = r;
	for (int i = 0; i <= r; i++) {
		while (i * i + cur * cur > r * r) cur--;
		x[i] = cur;
	}
	for (int i = 0; i <= r + r; i++)
		for (int j = max(i - r, 0); j <= min(i, r); j++)
			ox[i] = max(ox[i], x[j] + x[i - j] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &sum[i][j]); sum[i][j] += sum[i][j - 1];
		}
	for (int i = r + 1; i <= n - r; i++)
		for (int j = r + 1; j <= m - r; j++) {
			for (int k = 0; k <= r; k++) {
				my[i][j] += sum[i - k][j + x[k]] - sum[i - k][j - x[k] - 1];
				if (k) my[i][j] += sum[i + k][j + x[k]] - sum[i + k][j - x[k] - 1];
			}
			has[i][j] = has[i][j - 1]; cnt[i][j] = cnt[i][j - 1];
			if (my[i][j] > has[i][j]) { has[i][j] = my[i][j]; cnt[i][j] = 0; }
			if (my[i][j] == has[i][j]) cnt[i][j]++;
		}
	for (int i = r + 1; i <= n - r; i++)
		for (int j = r + 1; j <= m - r; j++)
			for (int k = r + 1; k <= n - r; k++)
				if (abs(i - k) > r + r) {
					if (my[i][j] + has[k][m - r] >= res1) {
						if (my[i][j] + has[k][m - r] > res1) { res1 = my[i][j] + has[k][m - r]; res2 = 0; }
						res2 += cnt[k][m - r];
					}
				} else {
					int col = j - ox[abs(i - k)];
					if (col > r && my[i][j] + has[k][col] >= res1) {
						if (my[i][j] + has[k][col] > res1) { res1 = my[i][j] + has[k][col]; res2 = 0; }
						res2 += 2 * cnt[k][col];
					}
				}
	printf("%d %I64d\n", res1, res2 / 2);
	return 0;
}