#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 100005;

int n;
int x[Maxn], y[Maxn];
int m;
int p[Maxn], q[Maxn];
ll X, Y;
ll X2, Y2;
ld res;

ld Cross(ld ax, ld ay, ld bx, ld by) { return ax * by - ay * bx; }

bool Check(ld mx, ld my)
{
	for (int i = 0; i < m; i++) {
		ld ax = p[(i + 1) % m] - p[i], ay = q[(i + 1) % m] - q[i];
		ld bx = mx - p[i], by = my - q[i];
		if (Cross(bx, by, ax, ay) < 0) return false;
	}
	return true;
}

ld Dist(ld mx, ld my) { return n * mx * mx - 2 * mx * X + X2 + n * my * my - 2 * my * Y + Y2; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		X += x[i]; Y += y[i];
		X2 += ll(x[i]) * x[i]; Y2 += ll(y[i]) * y[i];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &p[i], &q[i]);
	if (Check(ld(X) / n, ld(Y) / n)) { printf("%.8lf\n", double(Dist(ld(X) / n, ld(Y) / n))); return 0; }
	res = Dist(p[0], q[0]);
	for (int i = 0; i < m; i++) {
		ld a = p[i], b = p[(i + 1) % m] - p[i];
		ld c = q[i], d = q[(i + 1) % m] - q[i];
		res = min(res, Dist(a, c));
		ld t = (X * b + Y * d - n * a * b - n * c * d) / (n * (b * b + d * d));
		if (0 < t && t < 1) res = min(res, Dist(a + t * b, c + t * d));
	}
	printf("%.8lf\n", double(res));
	return 0;
}