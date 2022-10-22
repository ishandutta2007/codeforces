#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 8;
const int Maxd = 4;
const int dy[Maxd] = {-2, -2, 2, 2};
const int dx[Maxd] = {-2, 2, -2, 2};

int t;
char B[Maxn][Maxn];
bool was[Maxn][Maxn][Maxn][Maxn];

bool Traverse(int sx, int sy, int ex, int ey)
{
	if (sx < 0 || sx >= Maxn || sy < 0 || sy >= Maxn || ex < 0 || ex >= Maxn || ey < 0 || ey >= Maxn ||
		was[sx][sy][ex][ey]) return false;
	if (sx == ex && sy == ey && B[sx][sy] == '.') return true;
	was[sx][sy][ex][ey] = true;
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			if (Traverse(sx + dy[i], sy + dx[i], ex + dy[j], ey + dx[j])) return true;
	return false;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		int sx = -1, sy;
		int ex, ey;
		for (int i = 0; i < Maxn; i++)
			for (int j = 0; j < Maxn; j++) {
				scanf(" %c", &B[i][j]);
				if (B[i][j] == 'K') {
					B[i][j] = '.';
					if (sx == -1) { sx = i; sy = j; }
					else { ex = i; ey = j; }
				}
			}
		fill((bool*)was, (bool*)was + Maxn * Maxn * Maxn * Maxn, false);
		printf("%s\n", Traverse(sx, sy, ex, ey)? "YES": "NO");
	}
	return 0;
}