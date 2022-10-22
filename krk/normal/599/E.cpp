#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 13;
const int MaxN = 1 << Maxn;

int n, m, q;
bool edge[Maxn][Maxn];
int lca[Maxn][Maxn];
ll dp[Maxn][MaxN];

void addEdge(vector <int> neigh[], int a, int b)
{
	neigh[a].push_back(b);
	neigh[b].push_back(a);
}

void Fill(int v, int c, vector <int> neigh[], int col[])
{
	if (col[v]) return;
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++)
		Fill(neigh[v][i], c, neigh, col);
}

ll Get(int v, int mask)
{
	if (dp[v][mask] == -1) {
		if (mask == 0) return dp[v][mask] = 1;
		vector <int> neigh[Maxn];
		int cur = 1, col[Maxn] = {};
		int nws[Maxn + 1] = {};
		int has[Maxn + 1]; fill(has, has + Maxn + 1, -1);
		for (int i = 0; i < n; i++)
			if (mask & 1 << i) {
				if (lca[v][i] != -1 && lca[v][i] != v) return dp[v][mask] = 0;
				for (int j = 0; j < n; j++)
					if (mask & 1 << j) {
						if (lca[i][j] != -1)
							if (mask & 1 << lca[i][j]) {
								addEdge(neigh, i, lca[i][j]);
								addEdge(neigh, j, lca[i][j]);
							} else if (lca[i][j] != v) return dp[v][mask] = 0;
						if (edge[i][j]) addEdge(neigh, i, j);
					}
			}
		for (int i = 0; i < n; i++)
			if ((mask & 1 << i)) {
				if (!col[i]) {
					Fill(i, cur, neigh, col); cur++;
				}
				nws[col[i]] |= 1 << i;
				if (edge[i][v])
					if (has[col[i]] != -1) return dp[v][mask] = 0;
					else has[col[i]] = i;
			}
		ll res = 0;
		cur--;
		for (int i = 1; i < 1 << cur; i += 2) {
			int h = -1;
			int tot = 0;
			for (int j = 0; j < cur; j++)
				if (i & 1 << j) {
					tot |= nws[j + 1];
					if (has[j + 1] != -1)
						if (h != -1) h = -2;
						else h = has[j + 1];
				}
			if (h == -1) {
				ll tmp = 0;
				for (int j = 0; j < n; j++)
					if (tot & 1 << j) tmp += Get(j, (tot ^ (1 << j)));
				res += tmp * Get(v, mask ^ tot);
			} else if (h != -2) res += Get(h, (tot ^ (1 << h))) * Get(v, mask ^ tot);
		}
		dp[v][mask] = res;
	}
	return dp[v][mask];
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		edge[a][b] = edge[b][a] = true;
	}
	fill((int*)lca, (int*)lca + Maxn * Maxn, -1);
	while (q--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--; c--;
		if (lca[a][b] != -1 && lca[a][b] != c || a == b && a != c) {
			printf("0\n"); return 0;
		}
		if (a != b) lca[a][b] = lca[b][a] = c;
	}
	fill((ll*)dp, (ll*)dp + Maxn * MaxN, -1ll);
	printf("%I64d\n", Get(0, (1 << n) - 2));
	return 0;
}