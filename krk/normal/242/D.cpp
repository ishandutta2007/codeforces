#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int a[Maxn], cur[Maxn];
vector <int> res;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int v, u; scanf("%d %d", &v, &u);
		neigh[v].push_back(u); neigh[u].push_back(v);
	}
	queue <int> Q;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == cur[i]) Q.push(i);
	}
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		if (a[v] != cur[v]) continue;
		res.push_back(v); cur[v]++;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (++cur[u] == a[u]) Q.push(u);
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}