#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 42;
const int Maxd = 3;

int t[Maxd][Maxd];
int n;
ll f[Maxn][Maxd][Maxd];

int main()
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			scanf("%d", &t[i][j]);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int a = 0; a < 3; a++)
			for (int c = 0; c < 3; c++) if (a != c) {
				int b = 3 - a - c;
				f[i][a][c] = min(f[i - 1][a][b] + t[a][c] + f[i - 1][b][c], f[i - 1][a][c] + t[a][b] + f[i - 1][c][a] + t[b][c] + f[i - 1][a][c]);
			}
	printf("%I64d\n", f[n][0][2]);
	return 0;
}