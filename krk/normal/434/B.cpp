#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, m, q;
int a[4][Maxn][Maxn];
int has[4][Maxn][Maxn];

void Prec(int has[][Maxn], int a[][Maxn], int r, int c)
{
	for (int i = c; i > 0; i--) {
		if (a[r][i] == 1) has[r][i] = has[r][i + 1] + 1;
		else has[r][i] = 0;
	}
}

void Precompute()
{
	for (int i = 1; i <= n; i++) {
		Prec(has[0], a[0], i, m);
		Prec(has[1], a[1], i, m);
	}
	for (int i = 1; i <= m; i++) {
		Prec(has[2], a[2], i, n);
		Prec(has[3], a[3], i, n);
	}
}

void Change(int r, int c)
{
	a[0][r][c] = 1 - a[0][r][c]; Prec(has[0], a[0], r, c);
	int c2 = m - c + 1;
	a[1][r][c2] = 1 - a[1][r][c2]; Prec(has[1], a[1], r, c2);
	a[2][c][r] = 1 - a[2][c][r]; Prec(has[2], a[2], c, r);
	int r2 = n - r + 1;
	a[3][c][r2] = 1 - a[3][c][r2]; Prec(has[3], a[3], c, r2);
}

int Gt(int has[][Maxn], int r, int c, int lef, int rig)
{
	int tkr = 1, tkc = has[r][c];
	int res = tkr * tkc;
	int p1 = r - 1, p2 = r + 1;
	while (p1 >= lef || p2 <= rig) {
		tkr++;
		if (p1 >= lef && (p2 > rig || has[p1][c] >= has[p2][c])) {
			tkc = min(tkc, has[p1][c]); p1--;
		} else {
			tkc = min(tkc, has[p2][c]); p2++;
		}
		res = max(res, tkr * tkc);
	}
	return res;
}

int Get(int r, int c)
{
	int res = Gt(has[0], r, c, 1, n);
	res = max(res, Gt(has[1], r, m - c + 1, 1, n));
	res = max(res, Gt(has[2], c, r, 1, m));
	res = max(res, Gt(has[3], c, n - r + 1, 1, m));
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[0][i][j]);
			a[1][i][m - j + 1] = a[2][j][i] = a[3][j][n - i + 1] = a[0][i][j];
		}
	Precompute();
	while (q--) {
		int op, x, y; scanf("%d %d %d", &op, &x, &y);
		if (op == 1) Change(x, y);
		else printf("%d\n", Get(x, y));
	}
	return 0;
}