#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m, k;
int a[Maxn][Maxn];
int row[Maxn];
int res = Maxn;

int solveCols()
{
	int res = 0;
	for (int j = 0; j < m; j++) {
		int mn = Maxn;
		for (int t = 0; t < 2; t++) {
			int cur = 0;
			for (int i = 0; i < n; i++)
				cur += a[i][j] != row[i];
			mn = min(mn, cur);
			for (int i = 0; i < n; i++)
				row[i] = !row[i];
		}
		res += mn;
	}
	return res > k? Maxn: res;
}

int solveRows()
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		int mn = Maxn;
		for (int t = 0; t < 2; t++) {
			int cur = 0;
			for (int j = 0; j < m; j++)
				cur += a[i][j] != row[j];
			mn = min(mn, cur);
			for (int j = 0; j < m; j++)
				row[j] = !row[j];
		}
		res += mn;
	}
	return res > k? Maxn: res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	if (n <= k)
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 0; j < n; j++)
				row[j] = bool(i & 1 << j);
			res = min(res, solveCols());
		}
	else for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				row[j] = a[i][j];
			res = min(res, solveRows());
		}
	printf("%d\n", res == Maxn? -1: res);
	return 0;
}