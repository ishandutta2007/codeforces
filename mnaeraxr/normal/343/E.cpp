#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;


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


template<typename flow_type>
struct edge
{
	int src, dst;
	flow_type cap;
};

template<typename flow_type>
vector<edge<flow_type>> gomory_hu(dinic<flow_type> &adj)
{
	int n = adj.n;

	vector<edge<flow_type>> tree;
	vector<int> parent(n);

	for (int u = 1; u < n; ++u)
	{
		tree.push_back({ u, parent[u], adj.max_flow(u, parent[u]) });
		for (int v = u + 1; v < n; ++v)
			if (adj.level[v] == -1 && parent[v] == parent[u])
				parent[v] = u;
	}

	return tree;
}

vector<pii> adj[300];
bool mk[300][300];

edge<int> find(int s, int p){
	edge<int> ans = {-1, -1, oo};
	
	for (auto e : adj[s]){
		int u = e.first, c = e.second;
		if (mk[s][u] || u == p) continue;
		
		if (c < ans.cap) ans = {s, u, c};
		
		auto cur = find(u, s);
		if (cur.cap < ans.cap) ans = cur;
	}

	return ans;
}

void solve(int s){
	auto best = find(s, -1);
	
	if (best.cap == oo){
		cout << s + 1 << " ";
		return;
	}
	
	mk[best.dst][best.src] = mk[best.src][best.dst] = true;
	
	solve(best.dst);
	solve(best.src);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	dinic<int> flow(n);
	
	for (int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		
		flow.add_edge(u, v, c, c);
	}
	
	auto tree = gomory_hu(flow);
	
	int sum = 0;
	
	for (auto e : tree){
		sum += e.cap;
		adj[e.src].push_back({e.dst, e.cap});
		adj[e.dst].push_back({e.src, e.cap});
	}
	
	cout << sum << endl;
	
	solve(0);
	cout << endl;
	
	return 0;
}