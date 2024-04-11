#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxk = 102;

int n, m, k, s;
vector <int> has[Maxk];
vector <int> neigh[Maxn];
int dist[Maxk][Maxn];
int best[Maxk];

void Solve(const vector <int> &st, int dist[])
{
	fill(dist, dist + Maxn, Maxn);
	vector <int> Q;
	for (int i = 0; i < st.size(); i++) {
		dist[st[i]] = 0; Q.push_back(st[i]);
	}
	for (int i = 0; i < Q.size(); i++) {
		int v = Q[i];
		int d = dist[v];
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (d + 1 < dist[u]) {
				dist[u] = d + 1; Q.push_back(u);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		has[a].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= k; i++)
		Solve(has[i], dist[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++)
			best[j] = dist[j][i];
		sort(best + 1, best + k + 1);
		int res = 0;
		for (int j = 1; j <= s; j++)
			res += best[j];
		printf("%d%c", res, i + 1 <= n? ' ': '\n');
	}
	return 0;
}