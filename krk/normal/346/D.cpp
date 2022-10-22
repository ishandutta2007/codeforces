#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

const int Maxn = 1000005;

int n, m;
vector <int> bef[Maxn];
int out[Maxn];
int s, t;
int dist[Maxn];
bool was[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		out[a]++; bef[b].push_back(a);
	}
	scanf("%d %d", &s, &t);
	fill(dist, dist + n + 1, Maxn); dist[t] = 0;
	deque <int> Q; Q.push_back(t);
	while (!Q.empty()) {
		int v = Q.front(), d = dist[v]; Q.pop_front();
		if (was[v]) continue;
		was[v] = true;
		for (int i = 0; i < bef[v].size(); i++) {
			int u = bef[v][i];
			if (--out[u] == 0) {
				if (d < dist[u]) { dist[u] = d; Q.push_front(u); }
			} else if (d + 1 < dist[u]) { dist[u] = d + 1; Q.push_back(u); }
		}
	}
	printf("%d\n", dist[s] < Maxn? dist[s]: -1);
	return 0;
}