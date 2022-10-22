#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 5;
const int Maxn = 52;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
bool vis[Maxn][Maxn];
int res = Inf;

void Fill(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] != '#' || vis[r][c]) return;
	vis[r][c] = true;
	for (int i = 0; i < Maxd; i++)
		Fill(r + dy[i], c + dx[i]);
}

bool Test()
{
	fill((bool*)vis, (bool*)vis + Maxn * Maxn, false);
	bool was = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (B[i][j] == '#' && !vis[i][j]) {
			if (was) return true;
			else was = true;
			Fill(i, j);
		}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (B[i][j] == '#') {
			B[i][j] = '.';
			if (Test()) { printf("1\n"); return 0; }
			B[i][j] = '#';
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (B[i][j] == '#') {
			int cand = 0;
			for (int k = 0; k < Maxd; k++) {
				int ni = i + dy[k], nj = j + dx[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < m && (B[ni][nj] == '#' || B[ni][nj] == 'S'))
					cand++;
			}
			if (cand == 1) B[i][j] = 'S';
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (B[i][j] == '#' || B[i][j] == 'S') {
			int cand = 0;
			for (int k = 0; k < Maxd; k++) {
				int ni = i + dy[k], nj = j + dx[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < m && B[ni][nj] == '#')
					cand++;
			}
			if (cand) res = min(res, cand);
		}
	printf("%d\n", res == Inf? -1: res);
	return 0;
}