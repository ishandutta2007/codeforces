#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 2000000005;

int n, m;
vector <ii> neigh[Maxn];
vector <int> t[Maxn];
int dist[Maxn];

int getTim(int v, int d)
{
	for (int i = 0; i < t[v].size(); i++)
		if (d < t[v][i]) return d;
		else if (d == t[v][i]) d++;
	return d;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c)); neigh[b].push_back(ii(a, c));
	}
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		t[i].resize(k);
		for (int j = 0; j < k; j++)
			scanf("%d", &t[i][j]);
	}
	fill(dist, dist + Maxn, Inf); dist[1] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[1], 1));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		if (v == n) break;
		d = getTim(v, d);
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (d + u.second < dist[u.first])
				dist[u.first] = d + u.second, Q.push(ii(-dist[u.first], u.first));
		}
	}
	printf("%d\n", dist[n] == Inf? -1: dist[n]);
	return 0; 
}