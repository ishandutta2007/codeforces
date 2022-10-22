#include <cstdio>
#include <algorithm>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <char, ii> cii;

const int Maxn = 505;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
vector <cii> res;

void Go(int r, int c, bool root)
{
	B[r][c] = '#'; res.push_back(cii('B', ii(r, c)));
	for (int i = 0; i < Maxd; i++) {
		int nr = r + dy[i], nc = c + dx[i];
		if (1 <= nr && nr <= n && 1 <= nc && nc <= m && B[nr][nc] == '.')
			Go(nr, nc, false);
	}
	if (!root) { res.push_back(cii('D', ii(r, c))); res.push_back(cii('R', ii(r, c))); }
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n + 1; i++) B[i][0] = B[i][m + 1] = '#';
	for (int j = 0; j <= m + 1; j++) B[0][j] = B[n + 1][j] = '#';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) scanf(" %c", &B[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (B[i][j] == '.')
			Go(i, j, true);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%c %d %d\n", res[i].first, res[i].second.first, res[i].second.second);
	return 0;
}