#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 405;
const int Inf = 1000000000;
const int mod = 998244353;

int n, m;
int dist[Maxn][Maxn];
vector <int> neigh[Maxn];
int res[Maxn][Maxn];
int was[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = (i != j) * Inf;
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		dist[a][b] = dist[b][a] = 1;
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			fill(was, was + dist[i][j], 0);
			int ans = 1;
			for (int a = 1; a <= n; a++) if (a != i && a != j)
				if (dist[i][a] + dist[a][j] == dist[i][j])
					was[dist[i][a]]++;
				else {
					int cnt = 0;
					for (int k = 0; k < neigh[a].size(); k++) {
						int b = neigh[a][k];
						if (dist[i][b] + 1 == dist[i][a] &&
							dist[j][b] + 1 == dist[j][a])
							cnt++;
					}
					ans = ll(ans) * cnt % mod;
				}
			bool ok = true;
			for (int k = 1; k < dist[i][j] && ok; k++)
				ok = was[k] == 1;
			res[i][j] = res[j][i] = ok? ans: 0;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", res[i][j], j + 1 <= n? ' ': '\n');
    return 0;
}