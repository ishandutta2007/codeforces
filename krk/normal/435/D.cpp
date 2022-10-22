#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 405;
const int Maxm = 815;
const int nil = 401;

int n, m;
char B[Maxn][Maxn], Bn[Maxn][Maxn];
int row[Maxn][Maxn], col[Maxn][Maxn];
int diag1[Maxm][Maxn], diag2[Maxm][Maxn];
int res;

int calcRes()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			row[i][j] = row[i][j - 1] + (B[i][j] == '1');
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++)
			col[j][i] = col[j][i - 1] + (B[i][j] == '1');
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++) {
			diag1[i + j][j] = diag1[i + j][j - 1] + (B[i][j] == '1');
			diag2[i - j + nil][j] = diag2[i - j + nil][j - 1] + (B[i][j] == '1');
		}
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			for (int r = 1; i + r <= n && j + r <= m; r++)
				res += row[i][j + r] - row[i][j - 1] == 0 &&
					   col[j][i + r] - col[j][i - 1] == 0 &&
					   diag1[i + j + r][j + r] - diag1[i + j + r][j - 1] == 0;
			for (int r = 1; i - r >= 1 && j - r >= 1 && j + r <= m; r++)
				res += row[i - r][j + r] - row[i - r][j - r - 1] == 0 &&
					   diag1[i + j][j + r] - diag1[i + j][j - 1] == 0 &&
					   diag2[i - j + nil][j] - diag2[i - j + nil][j - r - 1] == 0;
		}
	return res;
}

void Rotate()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			Bn[j][n - i + 1] = B[i][j];
	swap(n, m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			B[i][j] = Bn[i][j];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", B[i] + 1);
	for (int i = 0; i < 4; i++) {
		res += calcRes();
		Rotate();
	}
	printf("%d\n", res);
	return 0;
}