#include <cstdio>
using namespace std;

const int Maxl = 9;
const int Maxn = 505;

int n, m;
char B[Maxn][Maxn];
int id[Maxl][Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i + (1 << 1) <= n; i++)
		for (int j = 0; j + (1 << 1) <= m; j++)
			id[1][i][j] = (B[i][j] == '.') << 3 | (B[i][j + 1] == '.') << 2 | (B[i + 1][j] == '.') << 1 | (B[i + 1][j + 1] == '.');
	for (int l = 2; l < Maxl; l++)
		for (int i = 0; i + (1 << l) <= n; i++)
			for (int j = 0; j + (1 << l) <= m; j++) {
				id[l][i][j] = -1;
				int ni = i + (1 << l - 1), nj = j + (1 << l - 1);
				for (int k = 0; k < 1 << 4; k++) {
					if (k & 1 << 3 && id[l - 1][i][j] != k || !(k & 1 << 3) && id[l - 1][i][j] != 0) continue;
					if (k & 1 << 2 && id[l - 1][i][nj] != k || !(k & 1 << 2) && id[l - 1][i][nj] != 0) continue;
					if (k & 1 << 1 && id[l - 1][ni][j] != k || !(k & 1 << 1) && id[l - 1][ni][j] != 0) continue;
					if (k & 1 << 0 && id[l - 1][ni][nj] != k || !(k & 1 << 0) && id[l - 1][ni][nj] != 0) continue;
					id[l][i][j] = k; res++;
					break;
				}
			}
	printf("%d\n", res);
	return 0;
}