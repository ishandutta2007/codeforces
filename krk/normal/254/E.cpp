#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 405;
const int Inf = 1000000000;

int n, v;
int a[Maxn];
int m;
vector <ii> f[Maxn];
int dp[Maxn][Maxn], par[Maxn][Maxn], wth[Maxn][Maxn];

void Print(int r, int c)
{
	if (r == 0) return;
	Print(r - 1, par[r][c]);
	printf("%d", wth[r][c]);
	for (int k = 0; k < wth[r][c]; k++)
		printf(" %d", f[r - 1][k].second);
	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &v);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int l, r, nd; scanf("%d %d %d", &l, &r, &nd); l--; r--;
		for (int j = l; j <= r; j++)
			f[j].push_back(ii(nd, i));
	}
	for (int i = 0; i < n; i++)
		sort(f[i].begin(), f[i].end());
	fill((int*)dp, (int*)dp + Maxn * Maxn, -Inf); dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < Maxn; j++) if (dp[i][j] != -Inf) {
			int old = j, nw = a[i];
			if (old + nw < v) continue;
			if (v <= old) old -= v;
			else { nw -= v - old; old = 0; }
			if (dp[i][j] > dp[i + 1][nw]) { dp[i + 1][nw] = dp[i][j]; par[i + 1][nw] = j; wth[i + 1][nw] = 0; }
			for (int k = 0; k < f[i].size(); k++) {
				if (old + nw < f[i][k].first) break;
				if (f[i][k].first <= old) old -= f[i][k].first;
				else { nw -= f[i][k].first - old; old = 0; }
				if (dp[i][j] + k + 1 > dp[i + 1][nw]) { dp[i + 1][nw] = dp[i][j] + k + 1; par[i + 1][nw] = j; wth[i + 1][nw] = k + 1; }
			}
		}
	int bj = 0;
	for (int j = 1; j < Maxn; j++) 
		if (dp[n][j] > dp[n][bj]) bj = j;
	printf("%d\n", dp[n][bj]);
	Print(n, bj);
	return 0;
}