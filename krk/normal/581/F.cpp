#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Inf = 1000000000;

int n;
vector <int> neigh[Maxn];
int cnt[Maxn], dp[Maxn][2][Maxn];
int root;

void Traverse(int v, int p = 0)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		cnt[v] += cnt[u];
	}
	if (neigh[v].size() == 1) dp[v][0][1] = dp[v][1][0] = 0;
	else dp[v][0][0] = dp[v][1][0] = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (cnt[u] > cnt[v] / 2)
			for (int j = 0; j < 2; j++)
				for (int l = 0; l <= cnt[u]; l++)
					dp[v][j][l] = min(dp[u][j][l], dp[u][1 - j][l] + 1);
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (cnt[u] <= cnt[v] / 2)
			for (int j = 0; j < 2; j++)
				for (int l = cnt[v]; l >= 0; l--) {
					dp[v][j][l] += min(dp[u][j][0], dp[u][1 - j][0] + 1);
					for (int z = 1; z <= cnt[u] && l - z >= 0; z++)
						dp[v][j][l] = min(dp[v][j][l], dp[v][j][l - z] + min(dp[u][j][z], dp[u][1 - j][z] + 1));
				}
	}
}

int main()
{
	scanf("%d", &n);
	if (n == 2) { printf("1\n"); return 0; }
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k <= n; k++)
				dp[i][j][k] = Inf;
	root = 1;
	while (neigh[root].size() == 1) root++;
	Traverse(root);
	int leaves = 0;
	for (int i = 1; i <= n; i++)
		leaves += neigh[i].size() == 1;
	printf("%d\n", dp[root][0][leaves / 2]);
	return 0;
}