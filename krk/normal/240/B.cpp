#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 205;
const int Maxm = 40005;
const int Inf = 1000000000;

int n;
int a, b;
int h[Maxn];
int H;
int best[Maxn][Maxm][2];
int res = Inf;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	for (int i = 0; i < n; i++) 
		scanf("%d", &h[i]);
	fill((int*)best, (int*)best + Maxn * Maxm * 2, Inf);
	if (h[0] <= a) best[0][h[0]][0] = 0;
	if (h[0] <= b) best[0][0][1] = 0;
	for (int i = 1; i < n; i++) {
		H += h[i - 1];
		for (int j = 0; j <= a; j++) {
			int lfta = a - j, lftb = b - (H - j);
			if (best[i - 1][j][0] != Inf) {
				if (h[i] <= lfta) best[i][j + h[i]][0] = min(best[i][j + h[i]][0], best[i - 1][j][0]);
				if (h[i] <= lftb) best[i][j][1] = min(best[i][j][1], best[i - 1][j][0] + min(h[i - 1], h[i]));
			}
			if (best[i - 1][j][1] != Inf) {
				if (h[i] <= lfta) best[i][j + h[i]][0] = min(best[i][j + h[i]][0], best[i - 1][j][1] + min(h[i - 1], h[i]));
				if (h[i] <= lftb) best[i][j][1] = min(best[i][j][1], best[i - 1][j][1]);
			}
		}
	}
	for (int j = 0; j <= a; j++)
		for (int l = 0; l < 2; l++)
			res = min(res, best[n - 1][j][l]);
	printf("%d\n", res == Inf? -1: res);
	return 0;
}