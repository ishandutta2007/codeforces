#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 105;
const int Inf = 1000000000;

int n, k;
int L[Maxm], R[Maxm];
int dp[2][2][Maxn];
ii give[2][2][Maxn];
ii D[Maxn];
int lef, rig;
int cur;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
		scanf("%d %d", &L[i], &R[i]);
	L[k] = 2 * n; R[k] = 2 * n;
	fill((int*)dp, (int*)dp + 2 * 2 * Maxn, Inf);
	fill((ii*)give, (ii*)give + 2 * 2 * Maxn, ii(-1, -1));
	dp[cur][0][L[0]] = 0;
	for (int i = 0; i < k; i++) {
		int my = R[i] - L[i];
		int shift = L[i + 1] - R[i];
		for (int j = 0; j < 2; j++) {
			lef = rig = 0;
			for (int l = 0; l <= 2 * n; l++) {
				int val = dp[cur][j][l]; dp[cur][j][l] = Inf;
				if (give[cur][j][l].first != -1) {
					while (lef < rig && D[rig - 1].first >= give[cur][j][l].first) rig--;
					D[rig++] = give[cur][j][l]; give[cur][j][l] = ii(-1, -1);
				}
				while (lef < rig && D[lef].second < l) lef++;
				if (lef < rig) val = min(val, D[lef].first);
				if (val >= Inf) continue;
				if (j == 0) {
					int nl = l + my + shift;
					dp[!cur][0][nl] = min(dp[!cur][0][nl], val);
					nl = l;
					if (give[!cur][1][nl].first == -1 || val + 1 < give[!cur][1][nl].first) {
						give[!cur][1][nl] = ii(val + 1, nl + my);
					}
					nl = l + shift;
					if (give[!cur][0][nl].first == -1 || val + 2 < give[!cur][0][nl].first)
						give[!cur][0][nl] = ii(val + 2, nl + my);
				} else {
					int nl = l;
					dp[!cur][1][nl] = min(dp[!cur][1][nl], val);
					nl = l + shift;
					if (give[!cur][0][nl].first == -1 || val + 1 < give[!cur][0][nl].first)
						give[!cur][0][nl] = ii(val + 1, nl + my);
					nl = l;
					if (give[!cur][1][nl].first == -1 || val + 2 < give[!cur][1][nl].first)
						give[!cur][1][nl] = ii(val + 2, nl + my);
				}
			}
		}
		cur = !cur;
	}
	int res = Inf;
	for (int j = 0; j < 2; j++) {
		lef = rig = 0;
		for (int l = 0; l <= n; l++) {
			int val = dp[cur][j][l];
			if (give[cur][j][l].first != -1) {
				while (lef < rig && D[rig - 1].first >= give[cur][j][l].first) rig--;
				D[rig++] = give[cur][j][l]; give[cur][j][l] = ii(-1, -1);
			}
			while (lef < rig && D[lef].second < l) lef++;
			if (lef < rig) val = min(val, D[lef].first);
			if (l == n) res = min(res, val);
		}
	}
	if (res >= Inf) printf("Hungry\n");
	else printf("Full\n%d\n", res);
	return 0;
}