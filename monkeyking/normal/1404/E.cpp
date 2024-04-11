//copyright Um_nik
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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const ll INF = (ll)1e18;
const ll C = (ll)1e9;

struct Dinic {
	struct Edge {
		int v, to;
		ll cap;

		Edge() : v(), to(), cap() {}
		Edge (int _v, int _to, ll _cap) : v(_v), to(_to), cap(_cap) {}
	};
	vector<Edge> ed;
	vector<vector<int>> g;
	int S, T;
	int n;
	vector<int> dist;
	vector<int> idx;

	Dinic() : ed(), g(), S(), T() {}
	Dinic(int _n, int _S, int _T) {
		n = _n;
		S = _S;
		T = _T;
		g.resize(n);
		for (int i = 0; i < n; i++)
			g[i].clear();
		ed = vector<Edge>();
	}

	void addEdge(int v, int to, ll cap) {
		//eprintf("addEdge %d %d %lld\n", v, to, cap);
		g[v].push_back((int)ed.size());
		ed.push_back(Edge(v, to, cap));
		g[to].push_back((int)ed.size());
		ed.push_back(Edge(to, v, 0));
	}

	bool BFS() {
		dist.resize(n);
		vector<int> q;
		for (int i = 0; i < n; i++)
			dist[i] = n;
		q.push_back(S);
		dist[S] = 0;
		for (int i = 0; i < (int)q.size(); i++) {
			int v = q[i];
			for (int id : g[v]) {
				Edge e = ed[id];
				if (e.cap <= 0) continue;
				int u = e.to;
				if (dist[u] <= dist[v] + 1) continue;
				dist[u] = dist[v] + 1;
				q.push_back(u);
			}
		}
		return dist[T] < n;
	}

	ll dfs(int v, ll flow) {
		if (v == T || flow == 0) return flow;
		ll res = 0;
		for (int &i = idx[v]; i < (int)g[v].size(); i++) {
			int id = g[v][i];
			Edge e = ed[id];
			int to = e.to;
			if (dist[to] != dist[v] + 1) continue;
			ll df = dfs(to, min(flow, e.cap));
			flow -= df;
			res += df;
			ed[id].cap -= df;
			ed[id ^ 1].cap += df;
			if (flow == 0) return res;
		}
		return res;
	}

	ll Flow() {
		idx.resize(n);
		ll res = 0;
		while(BFS()) {
			for (int i = 0; i < n; i++)
				idx[i] = 0;
			res += dfs(S, INF);
		}
		return res;
	}
} G;

const int N = 202;
char s[N][N];
int id[N][N];
int n, m;
int S, T;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') {
				id[i][j] = -1;
			} else {
				id[i][j] = S++;
			}
		}
	}
	T = S + 1;
	G = Dinic(S + 2, S, T);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			if (id[x][y] == -1) continue;
			if (x == 0 || id[x - 1][y] == -1)
				G.addEdge(S, id[x][y], 1);
			else
				G.addEdge(id[x - 1][y], id[x][y], 1);
		 	if (y == 0 || id[x][y - 1] == -1)
				G.addEdge(id[x][y], T, 1);
			else
				G.addEdge(id[x][y], id[x][y - 1], 1);
		}
	for (int i = 0; i < S; i++) {
		G.addEdge(S, i, C);
		G.addEdge(i, T, C);
	}
	printf("%lld\n", G.Flow() - S * C);

	return 0;
}