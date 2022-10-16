#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n=0) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int add_node()
	{
		adj.push_back({});
		return n++;
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> biconnected_components(graph &adj)
{
	int n = adj.n;

	vector<int> num(n), low(n), art(n), stk;
	vector<vector<int>> comps;

	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		for (int v : adj[u]) if (v != p)
		{
			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);

				if (low[v] >= num[u])
				{
					art[u] = (num[u] > 1 || num[v] > 2);

					comps.push_back({u});
					while (comps.back().back() != v)
						comps.back().push_back(stk.back()), stk.pop_back();
				}
			}
			else low[u] = min(low[u], num[v]);
		}
	};

	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);

	return comps;
}


map<pii,int> col;

bool mk[maxn];
graph g;
vi cycles[maxn];

template<typename flow_type>
struct dinic
{
	struct edge
	{
		size_t src, dst, rev;
		flow_type flow, cap;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n), level(n), q(n), it(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, flow_type rcap = 0)
	{
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap});
		if (src == dst) adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, rcap});
	}

	vector<int> level, q, it;

	bool bfs(int source, int sink)
	{
		fill(level.begin(), level.end(), -1);
		for (int qf = level[q[0] = sink] = 0, qb = 1; qf < qb; ++qf)
		{
			sink = q[qf];
			for (edge &e : adj[sink])
			{
				edge &r = adj[e.dst][e.rev];
				if (r.flow < r.cap && level[e.dst] == -1)
					level[q[qb++] = e.dst] = 1 + level[sink];
			}
		}
		return level[source] != -1;
	}

	flow_type augment(int source, int sink, flow_type flow)
	{
		if (source == sink) return flow;
		for (; it[source] != adj[source].size(); ++it[source])
		{
			edge &e = adj[source][it[source]];
			if (e.flow < e.cap && level[e.dst] + 1 == level[source])
			{
				flow_type delta = augment(e.dst, sink, min(flow, e.cap - e.flow));
				if (delta > 0)
				{
					e.flow += delta;
					adj[e.dst][e.rev].flow -= delta;
					return delta;
				}
			}
		}
		return 0;
	}

	flow_type max_flow(int source, int sink)
	{
		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;
		flow_type flow = 0;
		while (bfs(source, sink))
		{
			fill(it.begin(), it.end(), 0);
			for (flow_type f; (f = augment(source, sink, numeric_limits<flow_type>::max())) > 0;)
				flow += f;

		} // level[u] = -1 => source side of min cut
		return flow;
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	g = graph(n);
	
	for (int i = 0; i < m; ++i){
		int u, v, c; cin >> u >> v >> c;
		u--; v--; c--;
		
		g.add_edge(u, v);
		col[pii(u,v)] = col[pii(v, u)] = c;
	}
	
	auto comps = biconnected_components(g);
		
	int tot_cyc = comps.size();
	
	dinic<int> flow(tot_cyc + m + 2);
	int cur_cyc = 2;

	for (int i = 0; i < m; ++i)
		flow.add_edge(2 + tot_cyc + i, 1, 1);
	
	for (auto comp : comps){
		if (comp.size() == 2)
			flow.add_edge(0, col[pii(comp[0], comp[1])] + 2 + tot_cyc, 1);
		else{
			int tot = (int)comp.size();
			
			for (int i = 0; i < tot; ++i){
				int u = comp[i], v = comp[(i + 1) % tot];
				assert(col.count(pii(u, v)));
				flow.add_edge(cur_cyc, tot_cyc + col[ pii(u, v) ] + 2, 1);
			}
			
			flow.add_edge(0, cur_cyc++, tot - 1);
		}
	}
	
	int answer = flow.max_flow(0, 1);
	
	cout << answer << endl;
	
	return 0;
}