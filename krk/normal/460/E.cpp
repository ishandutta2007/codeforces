#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 9;
const int nil = 241;
const int Maxm = 485;
const int Maxr = 31;

int n, r;
int dy[Maxr];
int dp[Maxn][Maxm][Maxm];
ii par[Maxn][Maxm][Maxm];

int main()
{
	scanf("%d %d", &n, &r);
	dy[0] = r;
	for (int i = 1; i <= r; i++) {
		dy[i] = dy[i - 1];
		while (dy[i] * dy[i] + i * i > r * r) dy[i]--;
	}
	fill((int*)dp, (int*)dp + Maxn * Maxm * Maxm, -1);
	dp[0][nil][nil] = 0;
	for (int i = 0; i < n; i++)
		for (int xsum = 0; xsum < Maxm; xsum++)
			for (int ysum = 0; ysum < Maxm; ysum++) 
				if (dp[i][xsum][ysum] != -1)
					for (int x = -r; x <= r; x++)
						for (int m = -1; m <= 1; m += 2) {
							int y = dy[abs(x)] * m;
							int cand = dp[i][xsum][ysum] + (n - 1) * x * x + (n - 1) * y * y - 2 * (xsum - nil) * x - 2 * (ysum - nil) * y;
							int ni = i + 1, nxsum = xsum + x, nysum = ysum + y;
							if (cand > dp[ni][nxsum][nysum]) {
								dp[ni][nxsum][nysum] = cand;
								par[ni][nxsum][nysum] = ii(x, y);
							}
						}
	int bxsum = 0, bysum = 0;
	for (int xsum = 0; xsum < Maxm; xsum++)
		for (int ysum = 0; ysum < Maxm; ysum++)
			if (dp[n][xsum][ysum] > dp[n][bxsum][bysum])
				bxsum = xsum, bysum = ysum;
	printf("%d\n", dp[n][bxsum][bysum]);
	for (int i = n; i >= 1; i--) {
		ii pnt = par[i][bxsum][bysum];
		printf("%d %d\n", pnt.first, pnt.second);
		bxsum -= pnt.first; bysum -= pnt.second;
	}
	return 0;
}