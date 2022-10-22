#include <cstdio>
using namespace std;

const int Maxn = 1005;

int n, m, k;
bool B[Maxn][Maxn];

bool Is(int r1, int c1, int r2, int c2)
{
	return 1 <= r1 && 1 <= c1 && r2 <= n && c2 <= m && B[r1][c1] && B[r1][c2] && B[r2][c1] && B[r2][c2];
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int r, c; scanf("%d %d", &r, &c);
		B[r][c] = true;
		if (Is(r, c, r + 1, c + 1) || Is(r, c - 1, r + 1, c) || Is(r - 1, c, r, c + 1) || Is(r - 1, c - 1, r, c)) {
			printf("%d\n", i); return 0;
		}
	}
	printf("0\n");
	return 0;
}