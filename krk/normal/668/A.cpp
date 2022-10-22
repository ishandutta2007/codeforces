#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxq = 10005;

int n, m, q;
int a[Maxq], b[Maxq], c[Maxq], d[Maxq];
int B[Maxn][Maxn];

void Row(int r)
{
	int el = B[r][m - 1];
	for (int j = m - 1; j > 0; j--)
		B[r][j] = B[r][j - 1];
	B[r][0] = el;
}

void Col(int c)
{
	int el = B[n - 1][c];
	for (int i = n - 1; i > 0; i--)
		B[i][c] = B[i - 1][c];
	B[0][c] = el;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &a[i], &b[i]);
		if (a[i] == 3) scanf("%d %d", &c[i], &d[i]);
	}
	for (int i = q - 1; i >= 0; i--)
		if (a[i] == 1) Row(b[i] - 1);
		else if (a[i] == 2) Col(b[i] - 1);
		else B[b[i] - 1][c[i] - 1] = d[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d%c", B[i][j], j + 1 < m? ' ': '\n');
	return 0;
}