#include <cstdio>
using namespace std;

const int Maxn = 1005;

int n, m;
char B[Maxn][Maxn];
bool stop;
int a[Maxn], b[Maxn];

void writeCols()
{
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			B[i][j] = '0' + (i % 2 == 0? a[j]: b[j]);
	for (int i = 0; i < n; i++)
		printf("%s\n", B[i]);
}

void writeRows()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			B[i][j] = '0' + (j % 2 == 0? a[i]: b[i]);
	for (int i = 0; i < n; i++)
		printf("%s\n", B[i]);
}

bool checkCol(int c, int a, int b)
{
	for (int i = 0; i < n; i++)
		if (B[i][c] != '0' && (i % 2 == 0 && B[i][c] != a + '0' || i % 2 && B[i][c] != b + '0'))
			return false;
	return true;
}

bool checkRow(int r, int a, int b)
{
	for (int j = 0; j < m; j++)
		if (B[r][j] != '0' && (j % 2 == 0 && B[r][j] != a + '0' || j % 2 && B[r][j] != b + '0'))
			return false;
	return true;
}

void checkCols(int c, int i, int j, int k, int l)
{
	if (c == m) { writeCols(); stop = true; }
	else if (checkCol(c, i, j)) { a[c] = i; b[c] = j; checkCols(c + 1, k, l, i, j); }
	     else if (checkCol(c, j, i)) { a[c] = j; b[c] = i; checkCols(c + 1, k, l, i, j); }
}

void checkRows(int r, int i, int j, int k, int l)
{
	if (r == n) { writeRows(); stop = true; }
	else if (checkRow(r, i, j)) { a[r] = i; b[r] = j; checkRows(r + 1, k, l, i, j); }
	     else if (checkRow(r, j, i)) { a[r] = j; b[r] = i; checkRows(r + 1, k, l, i, j); }
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 1; i <= 4 && !stop; i++)
		for (int j = i + 1; j <= 4 && !stop; j++)
			for (int k = 1; k <= 4 && !stop; k++) if (k != i && k != j)
				for (int l = k + 1; l <= 4 && !stop; l++) if (l != i && l != j) {
					checkCols(0, i, j, k, l);
					if (!stop) checkRows(0, i, j, k, l);
				}
	if (!stop) printf("0\n");
	return 0;
}