#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxd = 32;
const int Maxm = 245;

int d, sumTime;
int minTime[Maxd], maxTime[Maxd];
int par[Maxd][Maxm];

void Print(int r, int c)
{
	if (r > 1) { Print(r - 1, c - par[r][c]); printf(" "); }
	printf("%d", par[r][c]);
}

int main()
{
	scanf("%d %d", &d, &sumTime);
	fill((int*)par, (int*)par + Maxd * Maxm, -1);
	par[0][0] = 0;
	for (int i = 0; i < d; i++) {
		scanf("%d %d", &minTime[i], &maxTime[i]);
		for (int j = 0; j < Maxm; j++) if (par[i][j] != -1)
			for (int k = minTime[i]; k <= maxTime[i] && j + k < Maxm; k++)
				par[i + 1][j + k] = k;
	}
	if (par[d][sumTime] != -1) {
		printf("YES\n");
		Print(d, sumTime); printf("\n");
	} else printf("NO\n");
	return 0;
}