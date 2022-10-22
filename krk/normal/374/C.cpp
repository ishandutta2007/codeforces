#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 0, 1};
const int dx[Maxd] = {0, -1, 1, 0};

int n, m;
char B[Maxn][Maxn];
map <char, char> M;
int got[Maxn][Maxn];
int res;

int Get(int r, int c)
{
	if (got[r][c] == -2) return Inf;
	if (got[r][c] == -1) {
		got[r][c] = -2;
		int cost = B[r][c] == 'D', best = cost;
		for (int i = 0; i < Maxd; i++) {
			int nr = r + dy[i], nc = c + dx[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] == M[B[r][c]])
				best = max(best, Get(nr, nc) + cost);
		}
		got[r][c] = min(best, Inf);
	}
	return got[r][c];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &B[i][j]);
	M['A'] = 'M'; M['M'] = 'I'; M['I'] = 'D'; M['D'] = 'A';
	fill((int*)got, (int*)got + Maxn * Maxn, -1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == 'A') res = max(res, Get(i, j));
	if (res == 0) printf("Poor Dima!\n");
	else if (res == Inf) printf("Poor Inna!\n");
	else printf("%d\n", res);
	return 0;
}