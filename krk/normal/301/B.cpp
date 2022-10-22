#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const ll Inf = 1000000000000000000ll;

int n, d;
int a[Maxn];
int x[Maxn], y[Maxn];
ll dist[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &d);
	for (int i = 2; i <= n - 1; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) dist[i][j] = Inf;
			else dist[i][j] = ll(d) * ll(abs(x[i] - x[j]) + abs(y[i] - y[j]));
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], max(dist[i][k], dist[i][k] - a[k] + dist[k][j]));
	printf("%I64d\n", max(0ll, dist[1][n]));
	return 0;
}