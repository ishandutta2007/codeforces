#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;

const ld Inf = 1e36l;
const int Maxn = 100005;

int n, k;
int x[Maxn], y[Maxn];
ld dist[Maxn];
ld l0[Maxn], l1[Maxn], l2[Maxn], r0[Maxn], r1[Maxn], r2[Maxn];
ld res = Inf;

ld Dist(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

ld Solve(int l, int r)
{
	if (l > r) return 0.0l;
	return min(dist[l], dist[r]) + x[r] - x[l];
}

int main()
{
	scanf("%d %d", &n, &k); k--;
	for (int i = 0; i <= n; i++)
		scanf("%d", &x[i]);
	scanf("%d", &y[n]);
	int mem;
	if (k != n) mem = x[k];
	sort(x, x + n);
	if (k != n) k = lower_bound(x, x + n, mem) - x;
	for (int i = 0; i < n; i++)
		dist[i] = Dist(x[n] - x[i], y[n] - y[i]);
	if (k == n) res = Solve(0, n - 1);
	else {
		for (int i = k; i < n; i++)
			res = min(res, min(x[k] - x[0] + x[i] - x[0] + dist[i], x[i] - x[k] + x[i] - x[0] + dist[0]) + Solve(i + 1, n - 1));
		for (int i = 0; i <= k; i++)
			res = min(res, min(x[n - 1] - x[k] + x[n - 1] - x[i] + dist[i], x[k] - x[i] + x[n - 1] - x[i] + dist[n - 1]) + Solve(0, i - 1));
	}
	printf("%.10lf\n", double(res));
	return 0;
}