#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const int Maxn = 100005;
const int Maxd = 3;
const ld pi = acos(-1.0l);

struct matrix {
	ld m[Maxd][Maxd];
	matrix(ld diag = 0.0l) {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = (i == j) * diag;
	}
	matrix operator*(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int l = 0; l < Maxd; l++)
					c.m[i][j] += m[i][l] * b.m[l][j];
		return c;
	}
};

int n, q;
int X[Maxn], Y[Maxn];
int pin1, pin2;
ld cX, cY;
matrix M(1);
bool was;

matrix Move(ld ax, ld ay)
{
	matrix R(1.0l);
	R.m[0][2] = ax; R.m[1][2] = ay;
	return R;
}

matrix Rot(ld ang)
{
	matrix R;
	R.m[0][0] = R.m[1][1] = cos(ang);
	R.m[0][1] = sin(ang);
	R.m[1][0] = -R.m[0][1];
	R.m[2][2] = 1;
	return R;
}

ldld Get(ld x, ld y)
{
	return ldld(x * M.m[0][0] + y * M.m[0][1] + M.m[0][2],
				x * M.m[1][0] + y * M.m[1][1] + M.m[1][2]);
}

void Fix(int ind)
{
	ldld top = Get(X[ind], Y[ind]);
	ldld mid = Get(cX, cY);
	M = Move(-top.first, -top.second) * M;
	ld ang = atan2(mid.second - top.second, mid.first - top.first);
	M = Rot(ang + pi / 2.0l) * M;
	M = Move(top.first, top.second) * M;
	top = Get(X[ind], Y[ind]);
	mid = Get(cX, cY);
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &X[i], &Y[i]);
	ld moveX = X[0], moveY = Y[0];
	for (int i = 0; i < n; i++)
		X[i] -= moveX, Y[i] -= moveY;
	ld area = 0, xsum = 0, ysum = 0;
	for (int i = 0; i <= n - 1; i++) {
		int ni = (i + 1) % n;
		ld areasum = ld(X[i]) * Y[ni] - ld(X[ni]) * Y[i];
		xsum += ld(X[i] + X[ni]) * areasum;
		ysum += ld(Y[i] + Y[ni]) * areasum;
		area += areasum; 
	}
	pin1 = 0, pin2 = 1;
	cX = xsum / (3 * area) + moveX, cY = ysum / (3 * area) + moveY;
	for (int i = 0; i < n; i++)
		X[i] += moveX, Y[i] += moveY;
	while (q--) {
		int t, a, b; scanf("%d %d", &t, &a); a--;
		if (t == 1) {
			scanf("%d", &b); b--;
			if (a == pin1) { Fix(pin2); pin1 = b; }
			else { Fix(pin1); pin2 = b; }
			was = true;
		} else {
			double res1, res2;
			if (!was) { res1 = X[a]; res2 = Y[a]; }
			else {
				ldld res = Get(X[a], Y[a]);
				res1 = res.first; res2 = res.second;
			}
			printf("%.10f %.10f\n", res1, res2);
		}
	}
	return 0;
}