#include <cstdio>
#include <vector>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 100005;

int n, m, k;
vector <int> neigh[Maxn];
bool spec[Maxn];
int s, t;
int dist[Maxn], par[Maxn];
int p[Maxn], siz[Maxn];
int res = -1;

int getPar(int x) { return p[x] == x? x: p[x] = getPar(p[x]); }

void unionSet(int a, int b)
{
	int para = getPar(a), parb = getPar(b);
	if (para == parb) return;
	if (siz[para] >= siz[parb]) { siz[para] += siz[parb]; p[parb] = para; }
	else { siz[parb] += siz[para]; p[para] = parb; }
}

bool Enough(int x)
{
	vector <int> Q;
	for (int i = 1; i <= n; i++) {
		if (spec[i]) { dist[i] = 0; par[i] = i; Q.push_back(i); }
		else { dist[i] = Inf; par[i] = 0; }
		p[i] = i; siz[i] = 1;
	}
	for (int i = 0; i < Q.size(); i++) {
		int v = Q[i];
		if (dist[v] == x) continue;
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (dist[v] + 1 < dist[u]) { dist[u] = dist[v] + 1; par[u] = par[v]; Q.push_back(u); }
			else if (dist[v] + 1 + dist[u] <= x) unionSet(par[v], par[u]);
		}
	}
	return getPar(s) == getPar(t);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while (k--) { int s; scanf("%d", &s); spec[s] = true; }
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	scanf("%d %d", &s, &t); spec[s] = spec[t] = true;
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Enough(mid)) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}