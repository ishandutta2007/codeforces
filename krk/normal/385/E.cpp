#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxd = 6;

int n;

struct matrix {
	int m[Maxd][Maxd];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = diag * (i == j);
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int l = 0; l < Maxd; l++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j] % n) % n;
		return c;
	}
};

int sx, sy, dx, dy;
ll t;
int res1, res2;

int main()
{
	scanf("%d %d %d %d %d %I64d", &n, &sx, &sy, &dx, &dy, &t);
	sx--; sy--;
	while (dx < 0) dx += n;
	while (dx > n) dx -= n;
	while (dy < 0) dy += n;
	while (dy > n) dy -= n;
	matrix r(1), a;
	a.m[0][0] = 2; a.m[0][1] = 1; a.m[0][2] = 1; a.m[0][3] = 0; a.m[0][4] = 1; a.m[0][5] = 2;
	a.m[1][0] = 1; a.m[1][1] = 2; a.m[1][2] = 0; a.m[1][3] = 1; a.m[1][4] = 1; a.m[1][5] = 2;
	a.m[2][0] = 1; a.m[2][1] = 1; a.m[2][2] = 1; a.m[2][3] = 0; a.m[2][4] = 1; a.m[2][5] = 2;
	a.m[3][0] = 1; a.m[3][1] = 1; a.m[3][2] = 0; a.m[3][3] = 1; a.m[3][4] = 1; a.m[3][5] = 2;
	a.m[4][0] = 0; a.m[4][1] = 0; a.m[4][2] = 0; a.m[4][3] = 0; a.m[4][4] = 1; a.m[4][5] = 1;
	a.m[5][0] = 0; a.m[5][1] = 0; a.m[5][2] = 0; a.m[5][3] = 0; a.m[5][4] = 0; a.m[5][5] = 1;
	while (t) {
		if (t & 1ll) r = r * a;
		t >>= 1ll; a = a * a;
	}
	int col[Maxd] = {sx, sy, dx, dy, 0, 1};
	for (int j = 0; j < Maxd; j++)
		res1 = (res1 + ll(r.m[0][j]) * col[j] % n) % n;
	res1++;
	for (int j = 0; j < Maxd; j++)
		res2 = (res2 + ll(r.m[1][j]) * col[j] % n) % n;
	res2++;
	printf("%d %d\n", res1, res2);
	return 0;
}