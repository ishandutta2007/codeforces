#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 20;
const ld pi = acos(-1.0l);
const ld eps = 1e-6l;

int n, l, r;
ld lim;
int X[Maxn], Y[Maxn], A[Maxn];
ld dist[1 << Maxn];

ld Dot(ld ax, ld ay, ld bx, ld by) { return ax * bx + ay * by; }

ld Len(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

ld nPoint(ld x, int lig)
{
	ld ax = X[lig] - (l + x), ay = Y[lig] - 0;
	ld bx = 1, by = 0;
	ld alen = Len(ax, ay);
	ld ang = acos(Dot(ax, ay, bx, by) / alen);
	ld my = A[lig] / 180.0 * pi;
	ld lft = pi - my - ang;
	if (lft < eps) return lim;
	ld dist = sin(my) * alen / sin(lft);
	return min(x + dist, lim);
}

int main()
{
	scanf("%d %d %d", &n, &l, &r); lim = r - l;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &X[i], &Y[i], &A[i]);
	dist[0] = 0.0;
	for (int i = 1; i < 1 << n; i++)
		for (int j = 0; j < n; j++) if (i & 1 << j)
			dist[i] = max(dist[i], nPoint(dist[i ^ 1 << j], j));
	printf("%.10lf\n", (double)dist[(1 << n) - 1]);
	return 0;
}