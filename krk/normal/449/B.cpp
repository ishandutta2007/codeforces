#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

struct edge {
	int b, c;
	bool sp;
	edge(int b = 0, int c = 0, int sp = false): b(b), c(c), sp(sp) {}
};

int n, m, k;
vector <edge> E;
vector <int> neigh[Maxn];
ll dist[Maxn];
vector <ii> srt;

void addEdge(int a, int b, int c, bool sp)
{
	neigh[a].push_back(E.size()); E.push_back(edge(b, c, sp));
	neigh[b].push_back(E.size()); E.push_back(edge(a, c, sp));
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		addEdge(a, b, c, false);
	}
	for (int i = 0; i < k; i++) {
		int b, c; scanf("%d %d", &b, &c);
		addEdge(1, b, c, true);
	}
	fill(dist, dist + n + 1, Inf); dist[1] = 0;
	priority_queue <ii> Q; Q.push(ii(0, 1));
	while (!Q.empty()) {
		int v = Q.top().second;
		ll d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		srt.push_back(ii(d, v));
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (d + E[e].c < dist[E[e].b]) {
				dist[E[e].b] = d + E[e].c;
				Q.push(ii(-dist[E[e].b], E[e].b));
			}
		}
	}
	sort(srt.begin(), srt.end());
	for (int i = srt.size() - 1; i > 0; i--) {
		int v = srt[i].second;
		bool found = false;
		for (int j = 0; j < neigh[v].size() && !found; j++) {
			int e = neigh[v][j];
			found = !E[e].sp && dist[E[e].b] + E[e].c == dist[v];
		}
		k -= !found;
	}
	printf("%d\n", k);
	return 0;
}