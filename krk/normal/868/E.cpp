#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 53;
const int Inf = 1000000000;

int n;
int dist[Maxn][Maxn];
vector <ii> neigh[Maxn];
int dp[Maxn][Maxn][Maxn][Maxn];
vector <int> leaves;
int s;
int col[Maxn];
int m;
int has[Maxn];

void Fill(int v, int p, int c)
{
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (p == u) continue;
		Fill(u, v, c);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = (i != j) * Inf;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= n; i++)
		if (neigh[i].size() == 1) leaves.push_back(i);
	for (int j = 0; j < leaves.size(); j++)
		for (int k = 0; k <= leaves.size(); k++)
			dp[0][j][k][0] = 0;
	for (int i = 1; i < Maxn; i++)
		for (int j = 0; j < leaves.size(); j++) {
			dp[i][j][0][i] = Inf;
			for (int k = 0; k < leaves.size(); k++)
				for (int l = 0; l <= i; l++) {
					dp[i][j][k + 1][l] = max(dp[i][j][k + 1][l], dp[i][j][k][l]);
					for (int z = 1; z <= l; z++) {
						int cand = min(dp[i][j][k][l], dist[leaves[j]][leaves[k]] + dp[i - z][k][leaves.size()][0]);
						dp[i][j][k + 1][l - z] = max(dp[i][j][k + 1][l - z], cand);
					}
				}
		}
	scanf("%d", &s);
	for (int i = 0; i < neigh[s].size(); i++) {
		int v = neigh[s][i].first;
		Fill(v, s, i + 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		has[col[x]]++;
	}
	int mn = Inf;
	for (int i = 1; i <= neigh[s].size(); i++) if (has[i] > 0) {
		int dp2[Maxn] = {};
		dp2[0] = Inf;
		for (int j = 0; j < leaves.size(); j++) if (col[leaves[j]] == i)
			for (int l = has[i]; l >= 0; l--)
				for (int z = 1; z <= l; z++) {
					int cand = min(dp2[l - z], dist[s][leaves[j]] + dp[m - z][j][leaves.size()][0]);
					dp2[l] = max(dp2[l], cand);
				}
		mn = min(mn, dp2[has[i]]);
	}
	printf("%d\n", mn);
	return 0;
}