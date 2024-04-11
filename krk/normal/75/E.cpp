#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> dd;

const int Maxn = 32;
const int Maxm = 105;
const ld eps = 1e-11l;
const ld Inf = 1e30l;

int xs, ys, xe, ye;
int n;
int x[Maxn], y[Maxn];
dd pnt[Maxm];
int plen;
ld dist[Maxm][Maxm];

void Get(ld x1, ld y1, ld x2, ld y2, ld &A, ld &B, ld &C)
{
	A = y2 - y1, B = x1 - x2, C = A * x1 + B * y1;
}

bool Equal(ld x, ld y, ld X, ld Y) { return fabs(x - X) < eps && fabs(y - Y) < eps; }

bool Intersect(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x4, ld y4, bool strict, ld &X, ld &Y)
{
	ld A1, B1, C1; Get(x1, y1, x2, y2, A1, B1, C1);
	ld A2, B2, C2; Get(x3, y3, x4, y4, A2, B2, C2);
	ld det = A1 * B2 - A2 * B1;
	if (fabs(det) < eps) return false;
	X = (B2 * C1 - B1 * C2) / det;
	Y = (A1 * C2 - A2 * C1) / det;
	if (Equal(x1, y1, X, Y) || Equal(x2, y2, X, Y)) return false;
	if (strict && (Equal(x3, y3, X, Y) || Equal(x4, y4, X, Y))) return false;
	return min(x1, x2) <= X + eps && X <= max(x1, x2) + eps && min(y1, y2) <= Y + eps && Y <= max(y1, y2) + eps &&
		   min(x3, x4) <= X + eps && X <= max(x3, x4) + eps && min(y3, y4) <= Y + eps && Y <= max(y3, y4) + eps;
}

ld Dist(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

bool testOutside(ld x1, ld y1)
{
	ld x2 = 1000000 + rand(), y2 = rand();
	int tims = 0;
	ld X, Y;
	for (int i = 0; i < n; i++)
		if (Intersect(x1, y1, x2, y2, x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], false, X, Y))
			tims++;
	return tims % 2 == 0;
}

bool onLine(ld X, ld Y, ld x1, ld y1, ld x2, ld y2)
{
	ld ax = x1 - X, ay = y1 - Y;
	ld bx = x2 - X, by = y2 - Y;
	return fabs(ax * by - ay * bx) < eps;
}

int Koef(ld x1, ld y1, ld x2, ld y2)
{
	ld X, Y;
	for (int i = 0; i < n; i++)
		if (Intersect(x1, y1, x2, y2, x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], true, X, Y))
			return 2;
	ld p = rand() + 1;
	ld tx = (x1 + p * x2) / (p + 1.0l), ty = (y1 + p * y2) / (p + 1.0l);
	return testOutside(tx, ty)? 1: 2;
}

bool Less(const dd &a, const dd &b)
{
	return Dist(xs - a.first, ys - a.second) < Dist(xs - b.first, ys - b.second);
}

int main()
{
	scanf("%d %d %d %d", &xs, &ys, &xe, &ye);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	fill((ld*)dist, (ld*)dist + Maxm * Maxm, Inf);
	pnt[plen++] = dd(xs, ys); pnt[plen++] = dd(xe, ye);
	for (int i = 0; i < n; i++) {
		pnt[plen++] = dd(x[i], y[i]);
		if (i + 1 < n) dist[plen - 1][plen] = dist[plen][plen - 1] = Dist(x[i] - x[i + 1], y[i] - y[i + 1]);
		else dist[plen - 1][2] = dist[2][plen - 1] = Dist(x[i] - x[0], y[i] - y[0]);
	}
	for (int i = 0; i < n; i++) {
		ld X, Y;
		if (Intersect(xs, ys, xe, ye, x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], false, X, Y))
			pnt[plen++] = dd(X, Y);
	}
	sort(pnt + n + 2, pnt + plen, Less);
	if (plen == n + 2) { cout << fixed << setprecision(10) << Dist(xs - xe, ys - ye) << endl; return 0; }
	dist[0][n + 2] = dist[n + 2][0] = Dist(xs - pnt[n + 2].first, ys - pnt[n + 2].second);
	dist[plen - 1][1] = dist[1][plen - 1] = Dist(pnt[plen - 1].first - xe, pnt[plen - 1].second - ye);
	for (int i = n + 2; i + 1 < plen; i++)
		dist[i][i + 1] = dist[i + 1][i] = Koef(pnt[i].first, pnt[i].second, pnt[i + 1].first, pnt[i + 1].second) * 
			                              Dist(pnt[i].first - pnt[i + 1].first, pnt[i].second - pnt[i + 1].second);
	for (int i = n + 2; i < plen; i++)
		for (int j = 0; j < n; j++) {
			int nj = (j + 1) % n;
			ld x1 = x[j], y1 = y[j], x2 = x[nj], y2 = y[nj];
			if (onLine(pnt[i].first, pnt[i].second, x1, y1, x2, y2) && 
				min(x1, x2) <= pnt[i].first + eps && pnt[i].first <= max(x1, x2) + eps && 
				min(y1, y2) <= pnt[i].second + eps && pnt[i].second <= max(y1, y2) + eps) {
				dist[i][2 + j] = dist[2 + j][i] = Dist(pnt[i].first - x1, pnt[i].second - y1);
				dist[i][2 + nj] = dist[2 + nj][i] = Dist(pnt[i].first - x2, pnt[i].second - y2);
			}
		}
	for (int k = 0; k < plen; k++)
		for (int i = 0; i < plen; i++)
			for (int j = 0; j < plen; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	cout << fixed << setprecision(10) << dist[0][1] << endl;
	return 0;
}