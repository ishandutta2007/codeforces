#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Maxd = 8;
const int dy[Maxd] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[Maxd] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
char B[Maxn][Maxn];
bool cur[Maxd];
bool tk[Maxn][Maxn];
ii Q[Maxn * Maxn];
int qlen;

bool Fre(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < m && B[r][c] == '.';
}

bool El(int r, int c)
{
	if (B[r][c] == '.') return false;
	for (int i = 0; i < Maxd; i++)
		cur[i] = Fre(r + dy[i], c + dx[i]);
	for (int i = 0; i < Maxd; i += 2)
		if (cur[i] && cur[i + 1] && cur[(i + 2) % Maxd])
			return true;
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (El(i, j)) { tk[i][j] = true; Q[qlen++] = ii(i, j); }
	for (int i = 0; i < qlen; i++) {
		ii v = Q[i]; B[v.first][v.second] = '.';
		for (int j = 0; j < Maxd; j++) {
			int nr = v.first + dy[j], nc = v.second + dx[j];
			if (0 <= nr && nr < n && 0 <= nc && nc < m && !tk[nr][nc] && El(nr, nc)) {
				Q[qlen++] = ii(nr, nc); tk[nr][nc] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%s\n", B[i]);
	return 0;
}