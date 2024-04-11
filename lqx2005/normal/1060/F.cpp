#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<i64, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 51;
int n, siz[N];
vector<int> g[N];
db C[N][N];
db dp[N][N], f[N];

void merge(int u, int v) {
	memset(f, 0, sizeof(f));
	for(int i = 0; i <= siz[u]; i++) {
		for(int j = 0; j <= siz[v]; j++) {
			f[i + j] += dp[u][i] * dp[v][j];
		}
	}
	memcpy(dp[u], f, sizeof(dp[u]));
	siz[u] += siz[v];
	return;
}

void dfs(int u, int fa) {
	memset(dp[u], 0, sizeof(dp[u]));
	dp[u][0] = 1;
	siz[u] = 0;
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		merge(u, v);
	}
	if(fa) {
		memset(f, 0, sizeof(f));
		for(int i = 0; i <= siz[u]; i++) {
			f[i + 1] += dp[u][i];
			for(int j = i; j >= 0; j--) {
				f[j] += dp[u][i] * C[siz[u] + 1][j] / (siz[u] + 1) / 2 / C[siz[u]][i];
			}
		}
		memcpy(dp[u], f, sizeof(f));
		siz[u]++;
	}
//	for(int i = 0; i <= siz[u]; i++) printf("%.10lf ", dp[u][i]);
//	printf("\n");
	return;
} 

int main() {
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		dfs(i, 0);
		printf("%.10lf\n", dp[i][0]);
	}
	return 0;
}