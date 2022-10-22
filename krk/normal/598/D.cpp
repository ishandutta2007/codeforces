#include <cstdio>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, k;
char B[Maxn][Maxn];
int cur, tk[Maxn][Maxn];
int has[Maxn * Maxn];

int Fill(int r, int c, int cur)
{
	if (B[r][c] == '*' || tk[r][c]) return 0;
	tk[r][c] = cur;
	int res = 0;
	for (int i = 0; i < Maxd; i++)
		res += B[r + dy[i]][c + dx[i]] == '*';
	for (int i = 0; i < Maxd; i++)
		res += Fill(r + dy[i], c + dx[i], cur);
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (B[i][j] == '.' && !tk[i][j]) {
				cur++;
				has[cur] = Fill(i, j, cur);
			}
	while (k--) {
		int r, c; scanf("%d %d", &r, &c);
		printf("%d\n", has[tk[r][c]]);
	}
	return 0;
}