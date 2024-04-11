#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 505;

int h, w;
char B[Maxn][Maxn];
int V[Maxn][Maxn], H[Maxn][Maxn];
int q;
int r1, c1, r2, c2;

int Get(int V[][Maxn], int r1, int c1, int r2, int c2)
{
	return V[r2][c2] - V[r1 - 1][c2] - V[r2][c1 - 1] + V[r1 - 1][c1 - 1];
}

int main()
{
	scanf("%d %d", &h, &w);
	for (int i = 1; i <= h; i++)
		scanf("%s", B[i] + 1);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			int my = (i < h && B[i][j] == '.' && B[i + 1][j] == '.')? 1: 0;
			V[i][j] = my + V[i - 1][j] + V[i][j - 1] - V[i - 1][j - 1];
			my = (j < w && B[i][j] == '.' && B[i][j + 1] == '.')? 1: 0;
			H[i][j] = my + H[i - 1][j] + H[i][j - 1] - H[i - 1][j - 1];
		}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		int res = Get(V, r1, c1, r2 - 1, c2) + Get(H, r1, c1, r2, c2 - 1);
		printf("%d\n", res);
	}
	return 0;
}