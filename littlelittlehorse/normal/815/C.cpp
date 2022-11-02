#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N(5055);
LL inf(1e18);
int siz[N], c[N], d[N];
vector<int> adj[N];
LL dp0[N][N], dp1[N][N], tmp[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= n; i++) {
		scanf("%d%d", &c[i], &d[i]);
		if(i >= 2) {
			int x;
			scanf("%d", &x);
			adj[x].push_back(i);
		}
		fill(dp0[i], dp0[i] + n + 1, inf);
		fill(dp1[i], dp1[i] + n + 1, inf);
	}
	for(int i(n); i >= 1; i--) {
		siz[i] = 1;
		dp1[i][1] = c[i] - d[i];
		dp0[i][0] = 0;
		dp0[i][1] = c[i];
		for(int j : adj[i]) {
			fill(tmp, tmp + siz[i] + siz[j] + 1, inf);
			for(int l(0); l <= siz[j]; l++)
				for(int k(siz[i]); k >= 0; k--)
					tmp[k + l] = min(tmp[k + l], dp1[i][k] + dp1[j][l]);
			copy(tmp, tmp + siz[i] + siz[j] + 1, dp1[i]);
			
			fill(tmp, tmp + siz[i] + siz[j] + 1, inf);
			for(int l(0); l <= siz[j]; l++)
				for(int k(siz[i]); k >= 0; k--)
					tmp[k + l] = min(tmp[k + l], dp0[i][k] + dp0[j][l]);
			copy(tmp, tmp + siz[i] + siz[j] + 1, dp0[i]);
			siz[i] += siz[j];
		}
		for(int j(0); j <= siz[i]; j++)
			dp1[i][j] = min(dp1[i][j], dp0[i][j]);
	}
	int ans(0);
	for(int i(0); i <= n; i++) {
		if(dp1[1][i] <= m)
			ans = i;
	}
	printf("%d\n", ans);
}