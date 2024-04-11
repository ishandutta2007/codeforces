#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 52;
const int Maxm = 105;

int n;
char B[Maxn][Maxn];
bool tk[Maxn][Maxn];
char res[Maxm][Maxm];

bool Check(int dr, int dc)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (B[i][j] == 'o') {
				int ni = i + dr, nj = j + dc;
				if (0 <= ni && ni < n && 0 <= nj && nj < n &&
					B[ni][nj] != 'o' && B[ni][nj] != 'x')
					return false;
			}
	return true;
}

void Insert(int dr, int dc)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (B[i][j] == 'o') {
				int ni = i + dr, nj = j + dc;
				if (0 <= ni && ni < n && 0 <= nj && nj < n)
					tk[ni][nj] = true;
			}
}

bool Ok()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (B[i][j] == 'x' && !tk[i][j])
				return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	fill((char*)res, (char*)res + Maxm * Maxm, '.');
	for (int i = -(n - 1); i <= (n - 1); i++)
		for (int j = -(n - 1); j <= (n - 1); j++) if (i || j)
			if (Check(i, j)) {
				Insert(i, j);
				res[n - 1 + i][n - 1 + j] = 'x';
			}
	if (Ok()) {
		printf("YES\n");
		res[n - 1][n - 1] = 'o';
		for (int i = 0; i < 2 * n - 1; i++) {
			res[i][2 * n - 1] = '\0';
			printf("%s\n", res[i]);
		}
	} else printf("NO\n");
	return 0;
}