#include <cstdio>
using namespace std;

const int Maxn = 1005;

int n;
int B[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	if (n == 4) { printf("-1\n"); return 0; }
	for (int i = 0; i < n; i++) B[i][(i + 1) % n] = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 2; j < n; j++) if (i != 0 || j != n - 1)
			if ((j - i) % 2) B[j][i] = 1;
			else B[i][j] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
	return 0;
}