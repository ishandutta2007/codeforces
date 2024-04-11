#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
int st[Maxn][Maxn];
int best[2];

bool Loop(int r, int c)
{
	if (st[r][c] == 2) return false;
	if (st[r][c] == 1) return true;
	st[r][c] = 1;
	if (B[r][c] == '<' && Loop(r, c - 1)) return true;
	if (B[r][c] == '>' && Loop(r, c + 1)) return true;
	if (B[r][c] == '^' && Loop(r - 1, c)) return true;
	if (B[r][c] == 'v' && Loop(r + 1, c)) return true;
	st[r][c] = 2;
	return false;
}

bool fromLeft(int r, int c)
{
	return c > 1 && B[r][c - 1] == '>';
}

bool fromRight(int r, int c)
{
	return c < m && B[r][c + 1] == '<';
}

bool fromUp(int r, int c)
{
	return r > 1 && B[r - 1][c] == 'v';
}

bool fromDown(int r, int c)
{
	return r < n && B[r + 1][c] == '^';
}

int Get(int r, int c)
{
	int mx = 0;
	if (fromLeft(r, c)) mx = max(mx, Get(r, c - 1));
	if (fromRight(r, c)) mx = max(mx, Get(r, c + 1));
	if (fromUp(r, c)) mx = max(mx, Get(r - 1, c));
	if (fromDown(r, c)) mx = max(mx, Get(r + 1, c));
	return mx + 1;
}

void rUpd(int val)
{
	if (val > best[0]) { best[1] = best[0]; best[0] = val; }
	else if (val > best[1]) best[1] = val;
}

void Upd(int val)
{
	rUpd(val); rUpd(val - 1);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			if (1 <= i && i <= n && 1 <= j && j <= m)
				scanf(" %c", &B[i][j]);
			else B[i][j] = '#';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (Loop(i, j)) { printf("-1\n"); return 0; }
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			if (B[i][j] == '#') {
				if (fromLeft(i, j)) Upd(Get(i, j - 1));
				if (fromRight(i, j)) Upd(Get(i, j + 1));
				if (fromUp(i, j)) Upd(Get(i - 1, j));
				if (fromDown(i, j)) Upd(Get(i + 1, j));
			}
	printf("%d\n", best[0] + best[1]);
	return 0;
}