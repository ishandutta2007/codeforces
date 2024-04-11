#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <ld, ld> ldld;

const ld pi = acos(-1.0l);
const ld eps = 1e-9l;
const int Maxn = 100005;

int X0, Y0, v, T;
int n;
int X[Maxn], Y[Maxn], R[Maxn];
vector <ldld> V, nw;

ld Len(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

void Push(ld a, ld b)
{
	if (a <= b + eps) V.push_back(ldld(a, b));
	else { V.push_back(ldld(a, 2 * pi)); V.push_back(ldld(0, b)); }
}

void Rot(ld x, ld y, ld &nx, ld &ny, ld cs, ld sn)
{
	nx = cs * x - sn * y;
	ny = sn * x + cs * y;
}

void calcInside(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2)
{
	ld d = Len(x1 - x2, y1 - y2);
	ld sina = r2 / d;
	ld cosa = sqrt(1.0l - sina * sina);
	ld ax = x2 - x1, ay = y2 - y1, bx, by, cx, cy;
	Rot(ax, ay, bx, by, cosa, -sina);
	Rot(ax, ay, cx, cy, cosa, sina);

	ld val1 = atan2(by, bx) + pi;
	ld val2 = atan2(cy, cx) + pi;

	Push(val1, val2);
}

void Intersect(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2)
{
	ld d = Len(x1 - x2, y1 - y2);
	if (r1 + r2 + eps < d) return;
	if (r1 + eps >= d) { calcInside(x1, y1, r1, x2, y2, r2); return; }
	ld a = (r1 * r1 - r2 * r2 + d * d) / (2.0l * d);
	ld h = sqrt(r1 * r1 - a * a);
	ld px = x1 + (x2 - x1) / d * a;
	ld py = y1 + (y2 - y1) / d * a;
	ldld res1 = ldld(px + (y2 - y1) / d * h, py + (x1 - x2) / d * h);
	ldld res2 = ldld(px + (y1 - y2) / d * h, py + (x2 - x1) / d * h);

	ld val1 = atan2(res1.second - y1, res1.first - x1) + pi;
	ld val2 = atan2(res2.second - y1, res2.first - x1) + pi;

	Push(val1, val2);
}

int main()
{
	scanf("%d %d %d %d", &X0, &Y0, &v, &T);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &X[i], &Y[i], &R[i]);
		if (ll(X0 - X[i]) * (X0 - X[i]) + ll(Y0 - Y[i]) * (Y0 - Y[i]) <= ll(R[i]) * R[i]) {
			printf("1.00000000000\n"); return 0;
		}
		if (v != 0 && T != 0 && R[i] != 0)
			Intersect(X0, Y0, ll(v) * T, X[i], Y[i], R[i]);
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++)
		if (nw.empty() || nw.back().second + eps < V[i].first)
			nw.push_back(V[i]);
		else nw.back().second = max(nw.back().second, V[i].second);
	ld got = 0;
	for (int i = 0; i < nw.size(); i++)
		got += nw[i].second - nw[i].first;
	cout << fixed << setprecision(15) << got / (2 * pi) << endl;
	return 0;
}