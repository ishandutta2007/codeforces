#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 16000;
const int Maxn = 2005;
const int Maxk = 10;

int n, m, k, s;
int a[Maxn][Maxn];
short dist[Maxk][Maxn][Maxn], cur[Maxk][Maxn][Maxn];
short d[Maxk][Maxk];
int res;

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int c = 1; c <= k; c++) {
		for (int i = 1; i <= n; i++)
			dist[c][i][0] = dist[c][i][m + 1] = cur[c][i][0] = cur[c][i][m + 1] = -Inf;
		for (int j = 1; j <= m; j++)
			dist[c][0][j] = dist[c][n + 1][j] = cur[c][0][j] = cur[c][n + 1][j] = -Inf;
	}
	for (int c = 1; c <= k; c++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				dist[c][i][j] = a[i][j] == c? 0: -Inf;
				dist[c][i][j] = max(dist[c][i][j], (short)(max(dist[c][i - 1][j], dist[c][i][j - 1]) + 1));
			} 
	for (int c = 1; c <= k; c++)
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= 1; j--) {
				cur[c][i][j] = a[i][j] == c? 0: -Inf;
				cur[c][i][j] = max(cur[c][i][j], (short)(max(cur[c][i - 1][j], cur[c][i][j + 1]) + 1));
				dist[c][i][j] = max(dist[c][i][j], cur[c][i][j]);
			}
	for (int c = 1; c <= k; c++)
		for (int i = n; i >= 1; i--)
			for (int j = 1; j <= m; j++) {
				cur[c][i][j] = a[i][j] == c? 0: -Inf;
				cur[c][i][j] = max(cur[c][i][j], (short)(max(cur[c][i + 1][j], cur[c][i][j - 1]) + 1));
				dist[c][i][j] = max(dist[c][i][j], cur[c][i][j]);
			}
	for (int c = 1; c <= k; c++)
		for (int i = n; i >= 1; i--)
			for (int j = m; j >= 1; j--) {
				cur[c][i][j] = a[i][j] == c? 0: -Inf;
				cur[c][i][j] = max(cur[c][i][j], (short)(max(cur[c][i + 1][j], cur[c][i][j + 1]) + 1));
				dist[c][i][j] = max(dist[c][i][j], cur[c][i][j]);
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int c = 1; c <= k; c++)
				d[a[i][j]][c] = max(d[a[i][j]][c], dist[c][i][j]);
	int lst; scanf("%d", &lst); s--;
	while (s--) {
		int cr; scanf("%d", &cr);
		res = max(res, (int)d[lst][cr]); lst = cr;
	}
	printf("%d\n", res);
	return 0;
}