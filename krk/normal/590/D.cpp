#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 151;
const int Maxm = Maxn * (Maxn - 1) / 2;
const int Inf = 1000000000;

int n, k, s;
int a[Maxn];
int dp1[Maxn][Maxm], dp2[Maxn][Maxm];
int sum, best;

int main()
{
	scanf("%d %d %d", &n, &k, &s); s = min(s, n * (n - 1) / 2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
		if (i < k) sum += a[i];
	}
	fill((int*)dp1, (int*)dp1 + (k + 1) * Maxm, -Inf);
	fill((int*)dp2, (int*)dp2 + (n - k + 1) * Maxm, Inf);
	
	int mx = min(k, n - k);

	int lim1 = k * (k - 1) / 2;
	dp1[0][0] = 0;
	for (int i = k - 1; i >= 0; i--) 
		for (int j = min(k - 1 - i, mx - 1); j >= 0; j--)
			for (int l = 0; l <= lim1; l++) if (dp1[j][l] != -Inf) {
				int nj = j + 1, nl = l + k - 1 - j - i;
				dp1[nj][nl] = max(dp1[nj][nl], dp1[j][l] + a[i]);
			}

	int lim2 = (n - k) * (n - k - 1) / 2;
	dp2[0][0] = 0;
	for (int i = k; i < n; i++)
		for (int j = min(i - k, mx - 1); j >= 0; j--)
			for (int l = 0; l <= lim2; l++) if (dp2[j][l] != Inf) {
				int nj = j + 1, nl = l + i - k - j;
				dp2[nj][nl] = min(dp2[nj][nl], dp2[j][l] + a[i]);
			}

	for (int j = 0; j <= mx; j++) {
		for (int l = 1; l <= lim2; l++)
			dp2[j][l] = min(dp2[j][l], dp2[j][l - 1]);
		for (int l = 0; l <= lim1; l++) {
			int tk = min(lim2, s - l - j * j);
			if (tk >= 0) best = min(best, -dp1[j][l] + dp2[j][tk]);
		}
	}
	printf("%d\n", sum + best);
	return 0;
}