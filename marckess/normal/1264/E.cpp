#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int inf = 1e9;

struct FlowGraph {

	struct Edge {
		int to;
		int flow, cap, cost;
		Edge *res;

		Edge () : to(0), flow(0), cap(0), cost(0), res(0) {}
		Edge (int to, int flow, int cap, int cost) : to(to), flow(flow), cap(cap), cost(cost), res(0) {}
    
		void addFlow (int f) {
			flow += f;
			res->flow -= f;
		}
	};

	vector<vector<Edge*>> adj;
	vector<int> dis, pos;
	int n;

	FlowGraph (int n) : n(n), adj(n), dis(n), pos(n) {} 

	void add (int u, int v, int cap, int cost) {
		Edge *x = new Edge(v, 0, cap, cost);
		Edge *y = new Edge(u, cap, cap, -cost);
		x->res = y;
		y->res = x;
		adj[u].pb(x);
		adj[v].pb(y);
	}

	ii maxFlowMinCost (int s, int t) {
		vector<bool> inQueue(n);
		vector<int> dis(n), cap(n);
		vector<Edge*> par(n);
		int maxFlow = 0, minCost = 0;

		while (1) {
			fill(all(dis), inf);
			fill(all(par), nullptr);
			fill(all(cap), 0);
			dis[s] = 0;
			cap[s] = inf;
			queue<int> q;
			q.push(s);

			while (q.size()) {
				int u = q.front();
				q.pop();
				inQueue[u] = 0;

				for (Edge *v : adj[u]) {
					if (v->cap > v->flow && dis[v->to] > dis[u] + v->cost) {
						dis[v->to] = dis[u] + v->cost;
						par[v->to] = v;
						cap[v->to] = min(cap[u], v->cap - v->flow);
                        
						if (!inQueue[v->to]) {
							q.push(v->to);
							inQueue[v->to] = 1;
						}
					}
				}
			}

			if (!par[t]) break;

			maxFlow += cap[t];
			minCost += cap[t] * dis[t];
			for (int u = t; u != s; u = par[u]->res->to)
				par[u]->addFlow(cap[t]);
		}

		return {maxFlow, minCost};
	}
};

int n, m, adj[55][55], d[55];
FlowGraph g(55 * 56 / 2 + 5);

int f (int n) {
	return n * (n - 1) / 2; 
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(adj, -1, sizeof(adj));

	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 0;
		d[u]++;
	}
	m = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = d[i] + 1; j <= n; j++)
			g.add(0, i, 1, f(j) - f(j - 1));
	
		for (int j = i + 1; j <= n; j++) 
			if (adj[i][j] == -1) {
				m++;
				g.add(i, n + m, 1, 0);
				g.add(j, n + m, 1, 0);
				g.add(n + m, g.n - 1, 1, 0);
			}

		adj[i][i] = 0;
	}

	g.maxFlowMinCost(0, g.n - 1);

	for (int i = 1; i <= m; i++) {
		int from, to;
		
		for (auto *e : g.adj[n + i])
			if (1 <= e->to && e->to <= n)
				if (e->flow == e->cap) {
					to = e->to;
				} else {
					from = e->to;
				}

		adj[from][to] = 1;
		adj[to][from] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << adj[i][j];
		cout << endl;
	}

	return 0;
}