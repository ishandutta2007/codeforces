#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 5005;

int n;
int a[Maxn];
int best[Maxn][Maxn];

int main()
{
	fill((int*)best, (int*)best + Maxn * Maxn, Inf);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	best[1][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) best[i + 1][i] = min(best[i + 1][i], best[i][j] + 1);
			else best[i + 1][j] = min(best[i + 1][j], best[i][j] + 1);
			best[i + 1][i] = min(best[i + 1][i], best[i][j] + max(0, a[i] - a[j]));
		}
	int res = Inf;
	for (int j = 0; j <= n; j++)
		res = min(res, best[n + 1][j]);
	printf("%d\n", res);
	return 0;
}