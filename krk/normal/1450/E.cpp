#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;

int n, m;
vector <ii> neigh[Maxn];
int dist[Maxn];
int best = -1;
int res[Maxn];

bool Solve(int v, int d)
{
	if (dist[v] <= d) return true;
	if (d < 0) return false;
	dist[v] = d;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.second == 0) {
			if (!Solve(u.first, d + 1)) return false;
		} else if (!Solve(u.first, d + u.second)) return false;
	}
	return true;
}

bool Check()
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < neigh[i].size(); j++) {
			ii u = neigh[i][j];
			if (u.second == 0) {
				if (abs(dist[i] - dist[u.first]) != 1) return false;
			} else if (dist[u.first] - dist[i] != u.second) return false;
		}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, -c));
	}
	for (int i = 1; i <= n; i++) {
		fill(dist, dist + n + 1, Maxn);
		if (Solve(i, 0))
			if (Check()) {
				int cand = 0;
				for (int j = 1; j <= n; j++)
					cand = max(cand, dist[j]);
				if (cand > best) {
					best = cand;
					for (int j = 1; j <= n; j++)
						res[j] = dist[j];
				}
			}
	}
	if (best == -1) printf("NO\n");
	else {
		printf("YES\n");
		printf("%d\n", best);
		for (int i = 1; i <= n; i++)
			printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	}
    return 0;
}