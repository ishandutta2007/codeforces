#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 505050

int n, K;
struct Edge {
	int v, w;
};
vector <Edge> E[N];

LL dp[N][2];

void dfs(int x, int fa) {
	dp[x][0] = dp[x][1] = 0;
	priority_queue <LL> q;
	for (auto v : E[x]) if (v.v != fa){
		dfs(v.v, x);
		dp[x][0] += dp[v.v][0];
		if (v.w + dp[v.v][1] - dp[v.v][0] > 0) q.push(v.w + dp[v.v][1] - dp[v.v][0]);
	}
	for (int i = K - 1; i && q.size(); i--) {
		dp[x][0] += q.top();
		q.pop();
	}
	dp[x][1] = dp[x][0];
	if (q.size()) dp[x][0] += q.top();
}

void work() {
	read(n); read(K);
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v, w;
		read(u); read(v); read(w);
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}
	dfs(1, -1);
	printf("%lld\n", dp[1][0]);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}