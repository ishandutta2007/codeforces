#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 300005;
const ll Inf = 1000000000000000000ll;

struct edge {
	int b, w, ind;
	edge(int b = 0, int w = 0, int ind = 0): b(b), w(w), ind(ind) {}
};

int n, m;
vector <edge> neigh[Maxn];
int u;
ll dist[Maxn];
ll res;
vector <int> seq;

void Dijkstra()
{
	fill(dist, dist + n + 1, Inf); dist[u] = 0;
	priority_queue <lli> Q; Q.push(lli(-dist[u], u));
	while (!Q.empty()) {
		int v = Q.top().second; ll d = -Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i].b;
			ll add = neigh[v][i].w;
			if (d + add < dist[u]) {
				dist[u] = d + add;
				Q.push(lli(-dist[u], u));
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, w; scanf("%d %d %d", &a, &b, &w);
		neigh[a].push_back(edge(b, w, i));
		neigh[b].push_back(edge(a, w, i));
	}
	scanf("%d", &u);
	Dijkstra();
	for (int i = 1; i <= n; i++) {
		ll val = Inf;
		int ind = -1;
		for (int j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j].b;
			ll add = neigh[i][j].w;
			if (dist[i] - add == dist[u] && add < val) {
				val = add; ind = neigh[i][j].ind;
			}
		}
		if (ind != -1) { res += val; seq.push_back(ind); }
	}
	printf("%I64d\n", res);
	for (int i = 0; i < seq.size(); i++)
		printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	return 0;
}