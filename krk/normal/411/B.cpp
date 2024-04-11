#include <cstdio>
using namespace std;

const int Maxn = 105;

int n, m, k;
int B[Maxn][Maxn];
int lock[Maxn];
int tims[Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &B[i][j]);
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) if (!lock[i] && B[i][j])
			tims[B[i][j]]++;
		for (int i = 1; i <= n; i++) if (!lock[i] && B[i][j])
			if (tims[B[i][j]] == 1) tims[B[i][j]]--;
			else lock[i] = j;
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", lock[i]);
	return 0;
}