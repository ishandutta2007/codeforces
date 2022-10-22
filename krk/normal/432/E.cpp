#include <cstdio>
using namespace std;

const int Maxn = 105;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];

bool forbColour(int r, int c, char col)
{
	int tlen = 0;
	for (int i = 0; i < Maxd; i++) {
		int nr = r + dy[i], nc = c + dx[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] == col)
			return true;
	}
	return false;
}

bool Check(int r1, int c1, int r2, int c2, char col)
{
	if (r1 < 0 || r2 >= n || c1 < 0 || c2 >= m) return false;
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			if (B[i][j] != '.' || forbColour(i, j, col)) return false;
	return true;
}

bool checkDist(int r, int c, int d, char col)
{

	for (char ch = 'A'; ch < col; ch++)
		if (Check(r, c + d, r, c + d, ch))
			return false;
	return Check(r, c + d, r + d, c + d, col) && Check(r + d, c, r + d, c + d, col);
}

void Colour(int r1, int c1, int r2, int c2, char col)
{
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			B[i][j] = col;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			B[i][j] = '.';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == '.')
				for (char ch = 'A'; ; ch++) if (checkDist(i, j, 0, ch)) {
					int d = 1;
					while (checkDist(i, j, d, ch)) d++;
					Colour(i, j, i + d - 1, j + d - 1, ch);
					break;
				}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", B[i][j]);
		printf("\n");
	}
	return 0;
}