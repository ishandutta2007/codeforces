#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const int Maxn = 300005;
const int Maxd = 3;
const int Maxm = 2097152;
const ld pi = acos(-1.0l);

struct matrix {
	ld m[Maxd][Maxd];
	matrix(int diag = 0) { 
		fill((ld*)m, (ld*)m + Maxd * Maxd, 0.0l); 
		if (diag) 
			for (int i = 0; i < Maxd; i++)
				m[i][i] = diag;
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int l = 0; l < Maxd; l++)
					c.m[i][j] += m[i][l] * b.m[l][j];
		return c;
	}
};

int n, m;
ld col[Maxn][Maxd];
matrix st[Maxm];
bool flag[Maxm];

matrix Rot(ld deg)
{
	matrix c;
	c.m[0][0] = cos(deg); c.m[0][1] = sin(deg);
	c.m[1][0] = -sin(deg); c.m[1][1] = cos(deg);
	c.m[2][2] = 1;
	return c;
}

matrix Move(ld x, ld y)
{
	matrix c;
	c.m[0][0] = 1; c.m[0][2] = x;
	c.m[1][1] = 1; c.m[1][2] = y;
	c.m[2][2] = 1;
	return c;
}

void downOn(int v, const matrix &b)
{
	flag[v] = true; st[v] = b * st[v];
}

void Down(int v)
{
	if (flag[v]) {
		downOn(2 * v, st[v]); downOn(2 * v + 1, st[v]);
		flag[v] = false;
		st[v] = matrix(1);
	}
}

void Create(int v, int l, int r)
{
	st[v] = matrix(1);
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	} 
}

void Update(int v, int l, int r, int a, int b, const matrix &M)
{
	if (l == a && r == b) downOn(v, M);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), M);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, M);
	}
}

ldld Get(int v, int l, int r, int x)
{
	if (l == r) {
		ld myx = 0, myy = 0;
		for (int j = 0; j < Maxd; j++) {
			myx += st[v].m[0][j] * col[x][j];
			myy += st[v].m[1][j] * col[x][j];
		}
		return ldld(myx, myy);
	} else {
		Down(v);
		int m = l + r >> 1;
		if (x <= m) return Get(2 * v, l, m, x);
		else return Get(2 * v + 1, m + 1, r, x);
	}
}

ld Get(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		col[i][0] = i; col[i][2] = 1;
	}
	Create(1, 0, n);
	while (m--) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			ldld prev = Get(1, 0, n, y - 1);
			ldld cur = Get(1, 0, n, y);
			ld len = Get(cur.first - prev.first, cur.second - prev.second);
			matrix m = Move((cur.first - prev.first) / len * z, (cur.second - prev.second) / len * z);
			Update(1, 0, n, y, n, m);
		} else {
			ldld cur = Get(1, 0, n, y - 1);
			matrix m = Move(cur.first, cur.second) * (Rot(z / 180.0l * pi) * Move(-cur.first, -cur.second));
			Update(1, 0, n, y, n, m);
		}
		ldld my = Get(1, 0, n, n);
		printf("%.10lf %.10lf\n", double(my.first), double(my.second));
	}
	return 0;
}