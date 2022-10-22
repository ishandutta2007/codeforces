#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Inf = 1000000000;

typedef pair <int, int> ii;

int n, m;
vector <ii> neigh[Maxn];
int zdist[Maxn], bfsdist[Maxn];
int zpar[Maxn], bfspar[Maxn];
ii par[Maxn];
set <int> S, nS;

void BFS(int v, int dist[], int par[], bool zer)
{
	bool ok[10] = {}; ok[0] = true;
	if (!zer) fill(ok + 1, ok + 10, true);
	fill(dist, dist + n, Inf); dist[v] = 0;
	queue <int> Q; Q.push(v);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (ok[u.second] && dist[v] + 1 < dist[u.first]) {
				dist[u.first] = dist[v] + 1; par[u.first] = v;
				Q.push(u.first);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, len; scanf("%d %d %d", &a, &b, &len);
		neigh[a].push_back(ii(b, len));
		neigh[b].push_back(ii(a, len));
	}
	BFS(n - 1, zdist, zpar, true);
	BFS(0, bfsdist, bfspar, false);
	int rlen = Inf;
	for (int i = 0; i < n; i++)
		if (i == n - 1 || zdist[i] < Inf)
			if (bfsdist[i] < rlen) rlen = bfsdist[i];
	fill(par, par + n, ii(Inf, 0));
	for (int i = 0; i < n; i++)
		if (i == n - 1 || zdist[i] < Inf)
			if (bfsdist[i] == rlen) {
				par[i] = ii(zdist[i], i); S.insert(i);
			}
	for (int i = 0; i < rlen; i++) {
		nS.clear();
		int best = 10;
		for (set <int>::iterator it = S.begin(); it != S.end(); it++)
			for (int j = 0; j < neigh[*it].size(); j++) {
				ii u = neigh[*it][j];
				if (bfsdist[*it] - 1 != bfsdist[u.first]) continue;
				if (u.second < best) { best = u.second; nS.clear(); }
				if (u.second == best) 
					if (nS.find(u.first) != nS.end()) par[u.first] = min(par[u.first], ii(par[*it].first, *it));
					else { nS.insert(u.first); par[u.first] = ii(par[*it].first, *it); }
			}
		printf("%d", best);
		S = nS;
	}
	if (rlen == 0) printf("0");
	printf("\n");
	int tlen = rlen + par[0].first;
	printf("%d\n", tlen + 1);
	int v = 0;
	for (int i = 0; i < rlen; i++) {
		printf("%d ", v); v = par[v].second;
	}
	for (int i = 0; i < tlen - rlen; i++) {
		printf("%d ", v); v = zpar[v];
	}
	printf("%d\n", v);
	return 0;
}