#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 1005;

struct edge {
	int b, l, r;
	edge(int b = 0, int l = 0, int r = 0): b(b), l(l), r(r) { }
};

int n, m;
vector <edge> neigh[Maxn];
vector <int> un;
int dist[Maxn];
int res;

int Get(int x)
{
	fill(dist, dist + n + 1, 0); dist[1] = Inf;
	priority_queue <ii> Q; Q.push(ii(dist[1], 1));
	while (!Q.empty()) {
		int v = Q.top().second, d = Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			edge u = neigh[v][i];
			if (u.l <= x && x <= u.r && min(d, u.r) > dist[u.b]) {
				dist[u.b] = min(d, u.r); Q.push(ii(dist[u.b], u.b));
			}
		}
	}
	return dist[n];
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, l, r; scanf("%d %d %d %d", &a, &b, &l, &r);
		neigh[a].push_back(edge(b, l, r)); neigh[b].push_back(edge(a, l, r));
		un.push_back(l);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < un.size(); i++) {
		int got = Get(un[i]);
		res = max(res, got - un[i] + 1);
	}
	if (res) printf("%d\n", res);
	else printf("Nice work, Dima!\n");
	return 0;
}