#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 505;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
int sr, sc;
int fr, fc;
bool tk[Maxn][Maxn];

void Fill(int r, int c)
{
	if (B[r][c] == 'X' || tk[r][c]) return;
	tk[r][c] = true;
	for (int i = 0; i < Maxd; i++)
		Fill(r + dy[i], c + dx[i]);
}

bool findPath()
{
	fill((bool*)tk, (bool*)tk + Maxn * Maxn, false);
	Fill(sr, sc);
	return tk[fr][fc];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", B[i] + 1);
		B[i][0] = B[i][m + 1] = 'X';
	}
	for (int j = 0; j <= m + 1; j++)
		B[0][j] = B[n + 1][j] = 'X';
	scanf("%d %d", &sr, &sc); B[sr][sc] = '.';
	scanf("%d %d", &fr, &fc);
	if (B[fr][fc] == 'X') { B[fr][fc] = '.'; printf("%s\n", findPath()? "YES": "NO"); return 0; }
	for (int i = 0; i < Maxd; i++) {
		int nr = fr + dy[i], nc = fc + dx[i];
		if (B[nr][nc] == '.') {
			B[nr][nc] = 'X';
			if (findPath()) { printf("YES\n"); return 0; }
			B[nr][nc] = '.';
		}
	}
	printf("NO\n");
	return 0;
}