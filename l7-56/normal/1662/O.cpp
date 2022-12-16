#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 1e6 + 10;
int n,vis[30][400];

int cir[30][400],lin[400][30];
void cov(int r, int L, int R) { cir[r][L]++, cir[r][R]--; }

int ans;
void dfs(int r, int d) {
	if (vis[r][d] || ans) return;
	vis[r][d] = 1;
	if (r == 20) return ans = 1, void();
	if (r && !cir[r][d]) dfs(r - 1, d);
	if (!cir[r + 1][d]) dfs(r + 1, d);
	if (!lin[d][r]) dfs(r, (d + 359) % 360);
	if (!lin[(d + 1) % 360][r]) dfs(r, (d + 1) % 360);
}

void work() {
	scanf("%d", &n);
	memset(cir, 0, sizeof cir);
	memset(lin, 0, sizeof lin);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; ++i) {
		char ch[3]; scanf("%s", ch);
		if (ch[0] == 'C') {
			int r, a1, a2;
			scanf("%d%d%d", &r, &a1, &a2);
			if (a1 < a2) cov(r, a1, a2);
			else cov(r, a1, 360), cov(r, 0, a2);
		}
		else {
			int r1, r2, aa;
			scanf("%d%d%d", &r1, &r2, &aa);
			lin[aa][r1]++, lin[aa][r2]--;
		}
	}
	for (int i = 0; i < 360; ++i)
		for (int j = 1; j <= 20; ++j)
			lin[i][j] += lin[i][j - 1];
	for (int i = 1; i <= 20; ++i)
		for (int j = 1; j < 360; ++j)
			cir[i][j] += cir[i][j - 1];
	ans = 0;
	dfs(0, 0);
	if (ans) printf("YES\n");
	else printf("NO\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}