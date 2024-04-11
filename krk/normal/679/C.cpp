#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 505;
const int Maxm = Maxn * Maxn;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, k;
char B[Maxn][Maxn];
int cur;
int tk[Maxn][Maxn];
int siz[Maxm];
int tot;
int status[Maxm];
int res;

void Add(int col)
{
	if (status[col]++ == 0) tot += siz[col];
}

void Rem(int col)
{
	if (--status[col] == 0) tot -= siz[col];
}

void addRow(int r, int c1, int c2)
{
	if (r < 0 || r > n) return;
	for (int j = c1; j <= c2; j++)
		Add(tk[r][j]);
}

void remRow(int r, int c1, int c2)
{
	if (r < 0 || r > n) return;
	for (int j = c1; j <= c2; j++)
		Rem(tk[r][j]);
}

void addCol(int c, int r1, int r2)
{
	if (c < 0 || c > n) return;
	for (int i = r1; i <= r2; i++)
		Add(tk[i][c]);
}

void remCol(int c, int r1, int r2)
{
	if (c < 0 || c > n) return;
	for (int i = r1; i <= r2; i++)
		Rem(tk[i][c]);
}

int getSiz(int r, int c)
{
	if (tk[r][c]) return 0;
	tk[r][c] = cur; int res = 1;
	for (int i = 0; i < Maxd; i++) if (B[r + dy[i]][c + dx[i]] != 'X')
		res += getSiz(r + dy[i], c + dx[i]);
	return res;
}

int main()
{
	fill((char*)B, (char*)B + Maxn * Maxn, 'X');
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (B[i][j] != 'X' && !tk[i][j]) {
			cur++; siz[cur] = getSiz(i, j);
			res = max(res, siz[cur]);
		}
	for (int i = 1; i + k <= n + 1; i++) {
		fill(status, status + Maxm, 0); tot = 0;
		int forb = 0;
		for (int r = i; r < i + k; r++)
			for (int c = 1; c < k; c++)
				if (B[r][c] == 'X') forb++;
				else Add(tk[r][c]);
		for (int c = k; c <= n; c++) {
			for (int r = i; r < i + k; r++)
				if (B[r][c] == 'X') forb++;
				else Add(tk[r][c]);
			addRow(i - 1, c - k + 1, c);
			addRow(i + k, c - k + 1, c);
			addCol(c - k, i, i + k - 1);
			addCol(c + 1, i, i + k - 1);
			res = max(res, tot + forb);
			remRow(i - 1, c - k + 1, c);
			remRow(i + k, c - k + 1, c);
			remCol(c - k, i, i + k - 1);
			remCol(c + 1, i, i + k - 1);
			for (int r = i; r < i + k; r++)
				if (B[r][c - k + 1] == 'X') forb--;
				else Rem(tk[r][c - k + 1]);
		}
	}
	printf("%d\n", res);
	return 0;
}