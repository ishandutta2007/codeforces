#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;

int n, s;
int c[6];
int best = Inf;
int bi, bj, bl;

void Check(int x, int y, int z)
{
	if (0 <= x && x <= y && y <= z) {
		int res = abs(c[3] * x - c[4] * y) + abs(c[4] * y - c[5] * z);
		if (res < best) { best = res; bi = x; bj = y; bl = z; }
	}
}

void gcd(int a, int &x, int b, int &y, int &g)
{
	if (a == 0) { g = b; x = 0; y = 1; }
	else {
		int xx, yy;
		gcd(b % a, xx, a, yy, g);
		x = yy - b / a * xx; y = xx;
	}
}

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		c[num]++;
	}
	int x0, z0, g0; gcd(c[3], x0, c[5], z0, g0);
	if (x0 < 0) {
		int tims = -x0 / (c[5] / g0); x0 += tims * (c[5] / g0); z0 -= tims * (c[3] / g0);
		if (x0 < 0) { x0 += c[5] / g0; z0 -= c[3] / g0; }
	}
	int tims = x0 / (c[5] / g0); x0 -= tims * (c[5] / g0); z0 += tims * (c[3] / g0);
	for (int y = 0; c[4] * y <= s; y++) {
		int lft = s - c[4] * y;
		if (lft % g0) continue;
		int x = lft / g0 * x0, z = lft / g0 * z0;
		int tims = x / (c[5] / g0);
		x -= tims * (c[5] / g0); z += tims * (c[3] / g0);
		Check(x, y, z);
		int tk = (y - x) / (c[5] / g0);
		Check(x + tk * (c[5] / g0), y, z - tk * (c[3] / g0));
		tk = (z - y) / (c[3] / g0);
		Check(x + tk * (c[5] / g0), y, z - tk * (c[3] / g0));
		int nx = c[4] * y / c[3];
		tk = (nx - x) / (c[5] / g0);
		Check(x + (tk - 1) * (c[5] / g0), y, z - (tk - 1) * (c[3] / g0));
		Check(x + tk * (c[5] / g0), y, z - tk * (c[3] / g0));
		Check(x + (tk + 1) * (c[5] / g0), y, z - (tk + 1) * (c[3] / g0));
		int nz = c[4] * y / c[5];
		tk = (z - nz) / (c[3] / g0);
		Check(x + (tk - 1) * (c[5] / g0), y, z - (tk - 1) * (c[3] / g0));
		Check(x + tk * (c[5] / g0), y, z - tk * (c[3] / g0));
		Check(x + (tk + 1) * (c[5] / g0), y, z - (tk + 1) * (c[3] / g0));
	}
	if (best == Inf) printf("-1\n");
	else printf("%d %d %d\n", bi, bj, bl);
	return 0;
}