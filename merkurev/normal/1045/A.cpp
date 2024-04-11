#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 100100;
const int LEN = 1 << 13;
const int V = 30000;
const int E = 1000000;

struct Edge {
	int v, to, cap, flow;

	Edge() : v(), to(), cap(), flow() {}
	Edge(int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap), flow(0) {}
};
Edge ed[E];
int edSz;
vector<int> g[V];
int dist[V];
int q[V];
int topQ;
int idx[V];
int S, T;
int n, m;
int weaponType[V];
vector<int> weaponTargets[V];
int omgType[V];
int omgLeft[V];
int ans[V][2];
int ansSz;

bool used[V];
int par[V];
int path[E];
int pathSz;

void dfs(int v) {
	used[v] = 1;
	for (int id : g[v]) {
		if (ed[id].flow <= 0) continue;
		int u = ed[id].to;
		if (used[u]) continue;
		par[u] = id;
		dfs(u);
	}
}

bool restorePath() {
	for (int i = 0; i <= T; i++) {
		par[i] = -1;
		used[i] = false;
	}
	dfs(S);
	if (par[T] == -1) return false;
	pathSz = 0;
	int v = T;
	while(v != S) {
		int id = par[v];
		path[pathSz++] = id;
		v = ed[id].v;
		ed[id].flow--;
		ed[id ^ 1].flow++;
	}
	reverse(path, path + pathSz);
	return true;
}

void addToAns(int v, int u) {
	ans[ansSz][0] = v + 1;
	ans[ansSz][1] = u + 1;
	omgType[u] = -1;
	ansSz++;
}

void addEdge(int v, int to, int cap) {
	g[v].push_back(edSz);
	ed[edSz++] = Edge(v, to, cap);
	g[to].push_back(edSz);
	ed[edSz++] = Edge(to, v, 0);
}
void edgesOnSegm(int v, int L, int R, int l, int r, int id) {
	if (l <= L && R <= r) {
		if (v < LEN)
			addEdge(id, n + m + v, 1);
		else
			addEdge(id, n + L, 1);
		return;
	}
	if (l >= R || L >= r) return;
	edgesOnSegm(2 * v, L, (L + R) / 2, l, r, id);
	edgesOnSegm(2 * v + 1, (L + R) / 2, R, l, r, id);
}

bool BFS() {
	for (int i = 0; i <= T; i++)
		dist[i] = INF;
	dist[S] = 0;
	topQ = 0;
	q[topQ++] = S;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int id : g[v]) {
			Edge e = ed[id];
			if (e.flow == e.cap) continue;
			int to = e.to;
			if (dist[to] <= dist[v] + 1) continue;
			dist[to] = dist[v] + 1;
			q[topQ++] = to;
		}
	}
	return dist[T] < INF;
}
int dfs(int v, int flow) {
	if (v == T || flow == 0) return flow;
	int res = 0;
	for (int &i = idx[v]; i < (int)g[v].size(); i++) {
		int id = g[v][i];
		int to = ed[id].to;
		if (dist[to] != dist[v] + 1) continue;
		int df = dfs(to, min(flow, ed[id].cap - ed[id].flow));
		ed[id].flow += df;
		ed[id ^ 1].flow -= df;
		res += df;
		flow -= df;
		if (flow == 0) return res;
	}
	return res;
}

int Flow() {
	int res = 0;
	while(BFS()) {
		for (int i = 0; i <= T; i++)
			idx[i] = 0;
		res += dfs(S, INF);
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	S = n + m + LEN;
	T = S + 1;
	for (int i = 0; i < m; i++)
		omgType[i] = -1;
	for (int i = 2; i < LEN; i++) {
		int v = n + m + i / 2;
		int u = n + m + i;
		addEdge(v, u, INF);
	}
	for (int i = 0; i < m; i++) {
		int v = n + m + (LEN + i) / 2;
		int u = n + i;
		addEdge(v, u, INF);
	}
	int addAns = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &weaponType[i]);
		if (weaponType[i] == 0) {
			addEdge(S, i, 1);
			int k;
			scanf("%d", &k);
			while(k--) {
				int v;
				scanf("%d", &v);
				v--;
				weaponTargets[i].push_back(v);
				addEdge(i, n + v, 1);
			}
		} else if (weaponType[i] == 1) {
			addEdge(S, i, 1);
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			weaponTargets[i].push_back(l);
			weaponTargets[i].push_back(r);
			if (l & 1) {
				addEdge(i, n + l, 1);
				l++;
			}
			if (r & 1) {
				r--;
				addEdge(i, n + r, 1);
			}
			edgesOnSegm(1, 0, LEN, l, r, i);
		} else {
			addAns += 2;
			omgLeft[i] = 2;
			weaponTargets[i].resize(3);
			addEdge(i, T, 1);
			for (int j = 0; j < 3; j++) {
				scanf("%d", &weaponTargets[i][j]);
				weaponTargets[i][j]--;
				omgType[weaponTargets[i][j]] = i;
				addEdge(n + weaponTargets[i][j], i, 1);
			}
		}
	}
	for (int i = 0; i < m; i++)
		if (omgType[i] == -1)
			addEdge(n + i, T, 1);

	int fl = Flow();
	int realAns = addAns + fl;
	while(fl--) {
		if (!restorePath()) throw;
		int v = ed[path[0]].to;
		int u = ed[path[pathSz - 1]].v;
		//printf("!! %d %d\n", v, u);
		if (u < n)
			u = ed[path[pathSz - 2]].v;
		addToAns(v, u - n);
	}
	for (int i = 0; i < m; i++)
		if (omgType[i] != -1 && omgLeft[omgType[i]] > 0) {
			omgLeft[omgType[i]]--;
			addToAns(omgType[i], i);
		}
	if (ansSz != realAns) throw;
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);

	return 0;
}