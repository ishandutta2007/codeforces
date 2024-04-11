#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 605;

int n, m;
vector <ii> neigh[Maxn];
int bas[Maxn];
int dist[Maxn];
int B[Maxn][Maxn];
int len[Maxn];
int res[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(c, b));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[j] = n;
			len[j] = 0;
		}
		sort(neigh[i].begin(), neigh[i].end());
		bas[i] = neigh[i][0].first;
		for (int j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j].second;
			int cand = neigh[i][j].first - bas[i];
			if (cand < dist[u]) {
				dist[u] = cand;
				B[dist[u]][len[dist[u]]++] = u;
			}
		}
		for (int j = 0; j < n; j++)
			for (int l = 0; l < len[j]; l++) {
				int v = B[j][l];
				if (dist[v] != j) continue;
				int u = (v + 1) % n;
				if (dist[v] + 1 < dist[u]) {
					dist[u] = dist[v] + 1;
					B[dist[u]][len[dist[u]]++] = u;
				}
				for (int k = 0; k < neigh[v].size(); k++) {
					int u = (neigh[v][k].second + bas[i] + dist[v]) % n;
					int cand = dist[v] + neigh[v][k].first;
					if (cand < dist[u]) {
						dist[u] = cand;
						B[dist[u]][len[dist[u]]++] = u;
					}
				}
			}
		for (int j = 0; j < n; j++)
			res[i][j] = i == j? 0: bas[i] + dist[j];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", res[i][j], j + 1 < n? ' ': '\n');
    return 0;
}