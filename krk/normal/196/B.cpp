#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 1505;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
int sr, sc;
ii vis[Maxn][Maxn];

ii getNext(const ii &col, int nr, int nc)
{
	if (nr < 0) return ii(col.first - 1, col.second);
	if (nr >= n) return ii(col.first + 1, col.second);
	if (nc < 0) return ii(col.first, col.second - 1);
	if (nc >= m) return ii(col.first, col.second + 1);
	return col;
}

bool getRes(int r, int c, const ii &col)
{
	if (B[r][c] == '#') return false;
	if (vis[r][c].first != Inf)
		if (vis[r][c] != col) return true;
		else return false;
	vis[r][c] = col;
	for (int i = 0; i < Maxd; i++) {
		int nr = r + dy[i], nc = c + dx[i];
		if (getRes((nr + n) % n, (nc + m) % m, getNext(col, nr, nc)))
			return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == 'S') { sr = i; sc = j; }
			vis[i][j] = ii(Inf, Inf);
		}
	printf("%s\n", getRes(sr, sc, ii(0, 0))? "Yes": "No");
	return 0;
}