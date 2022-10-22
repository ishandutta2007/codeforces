#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
int lef[Maxn], rig[Maxn];
vector <int> neigh[Maxn];
ll dp[Maxn][2];

void Solve(int v, int p)
{
	dp[v][0] = dp[v][1] = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v);
		dp[v][0] += max(dp[u][0] + abs(lef[u] - lef[v]), dp[u][1] + abs(rig[u] - lef[v]));
		dp[v][1] += max(dp[u][0] + abs(lef[u] - rig[v]), dp[u][1] + abs(rig[u] - rig[v]));
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &lef[i], &rig[i]);
			neigh[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		}
		Solve(1, 0);
		printf("%I64d\n", max(dp[1][0], dp[1][1]));
	}
    return 0;
}