#include <cstdio>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 505;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, k;
char B[Maxn][Maxn];
bool taken[Maxn][Maxn];

void Go(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == '#' || taken[r][c])
		return;
	taken[r][c] = true;
	for (int i = 0; i < Maxd; i++)
		Go(r + dy[i], c + dx[i]);
	if (k) { B[r][c] = 'X'; k--; }
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	bool f = false;
	for (int i = 0; i < n && !f; i++)
		for (int j = 0; j < m && !f; j++)
			if (B[i][j] == '.') { Go(i, j); f = true; }
	for (int i = 0; i < n; i++)
		printf("%s\n", B[i]);
	return 0;
}