#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Maxd = 10;
const int Inf = 1000000000;

int T;
int n;
char B[Maxn][Maxn];
int lef[Maxd], rig[Maxd];
int bot[Maxd], tp[Maxd];
int curmn[Maxd], curmx[Maxd];
int res[Maxd];

int main()
{
	scanf("%d", &T);
	while (T--) {
		fill(lef, lef + Maxd, Inf);
		fill(rig, rig + Maxd, -Inf);
		fill(bot, bot + Maxd, Inf);
		fill(tp, tp + Maxd, -Inf);
		fill(res, res + Maxd, 0);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", B[i]);
			for (int j = 0; j < n; j++) {
				lef[B[i][j] - '0'] = min(lef[B[i][j] - '0'], j);
				rig[B[i][j] - '0'] = max(rig[B[i][j] - '0'], j);
				bot[B[i][j] - '0'] = min(bot[B[i][j] - '0'], i);
				tp[B[i][j] - '0'] = max(bot[B[i][j] - '0'], i);
			}
		}
		for (int i = 0; i < n; i++) {
			fill(curmn, curmn + Maxd, Inf);
			fill(curmx, curmx + Maxd, -Inf);
			for (int j = 0; j < n; j++) {
				int dig = B[i][j] - '0';
				res[dig] = max(res[dig], max(j, n - 1 - j) * max(i - bot[dig], tp[dig] - i));
				curmn[dig] = min(curmn[dig], j);
				curmx[dig] = max(curmx[dig], j);
			}
			for (int dig = 0; dig < 10; dig++) if (curmn[dig] != Inf)
				res[dig] = max(res[dig], (curmx[dig] - curmn[dig]) * max(i, n - 1 - i));
		}
		for (int j = 0; j < n; j++) {
			fill(curmn, curmn + Maxd, Inf);
			fill(curmx, curmx + Maxd, -Inf);
			for (int i = 0; i < n; i++) {
				int dig = B[i][j] - '0';
				res[dig] = max(res[dig], max(i, n - 1 - i) * max(j - lef[dig], rig[dig] - j));
				curmn[dig] = max(curmn[dig], i);
				curmx[dig] = max(curmx[dig], i);
			}
			for (int dig = 0; dig < 10; dig++) if (curmn[dig] != Inf)
				res[dig] = max(res[dig], (curmx[dig] - curmn[dig]) * max(j, n - 1 - j));
		}
		for (int i = 0; i < Maxd; i++)
			printf("%d%c", res[i], i + 1 < Maxd? ' ': '\n');
	}
    return 0;
}