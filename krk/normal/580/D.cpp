#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 18;

int n, m, k;
ll a[Maxn];
int neigh[Maxn][Maxn];
ll dp[1 << Maxn][Maxn];
ll best;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	while (k--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
		neigh[a][b] = c;
	}
	for (int i = 0; i < n; i++)
		dp[1 << i][i] = a[i];
	for (int i = 0; i < 1 << n; i++) {
		int bts = 0;
		for (int j = 0; j < n; j++)
			if (i & 1 << j) bts++;
		if (bts > m) continue;
		for (int j = 0; j < n; j++) if (i & 1 << j) {
			if (bts == m) { best = max(best, dp[i][j]); continue; }
			for (int l = 0; l < n; l++) if (!(i & 1 << l))
				dp[i | 1 << l][l] = max(dp[i | 1 << l][l], dp[i][j] + ll(neigh[j][l]) + a[l]);
		}
	}
	printf("%I64d\n", best);
	return 0;
}