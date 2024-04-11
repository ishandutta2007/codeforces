#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct trie{
    vector<vector<int>> tree;
    vector<vector<int>> go;
    vector<vector<int>> ENDS;

    trie(){
        new_node();
    }

    int new_node(){
        int id = tree.size();
        tree.push_back(vector<int>(26));
        go.push_back(vector<int>(26));
        ENDS.push_back(vi());

        return id;
    }

    void push(string s, int idx){
        int cur = 0;
        for (auto x : s){
            int v = x - 'a';
            if (!tree[cur][v]){
                int id = new_node();
                tree[cur][v] = id;
            }
            cur = tree[cur][v];

        }
        ENDS[cur].push_back(idx);
    }

    void build(){
        queue<pii> q;
        q.push({0, 0});

        while (!q.empty()){
            pii c = q.front(); q.pop();
            int u = c.first;
            int f = c.second;

            for (auto i : ENDS[f])
                ENDS[u].push_back(i);

            for (int i = 0; i < 26; ++i){
                if (tree[u][i]){
                    q.push({tree[u][i], go[f][i]});
                    go[u][i] = tree[u][i];
                }
                else
                    go[u][i] = go[f][i];
            }
        }
    }
};

template<typename flow_type, typename cost_type>
struct min_cost_max_flow
{
	struct edge
	{
		size_t src, dst, rev;
		flow_type flow, cap;
		cost_type cost;
	};

	int n;
	vector<vector<edge>> adj;

	min_cost_max_flow(int n) : n(n), adj(n), potential(n), dist(n), back(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, cost_type cost)
	{
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap, cost});
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, 0, -cost});
	}

	vector<cost_type> potential;

	inline cost_type rcost(const edge &e)
	{
		return e.cost + potential[e.src] - potential[e.dst];
	}

	void bellman_ford(int source)
	{
		for (int k = 0; k < n; ++k)
			for (int u = 0; u < n; ++u)
				for (edge &e : adj[u])
					if (e.cap > 0 && rcost(e) < 0) potential[e.dst] += rcost(e);
	}

	const cost_type oo = numeric_limits<cost_type>::max();

	vector<cost_type> dist;
	vector<edge*> back;

	cost_type dijkstra(int source, int sink)
	{
		fill(dist.begin(), dist.end(), oo);

		typedef pair<cost_type, int> node;
		priority_queue<node, vector<node>, greater<node>> pq;

		for (pq.push({dist[source] = 0, source}); !pq.empty();)
		{
			node p = pq.top(); pq.pop();

			if (dist[p.second] < p.first) continue;
			if (p.second == sink) break;

			for (edge &e : adj[p.second])
				if (e.flow < e.cap && dist[e.dst] > dist[e.src] + rcost(e))
				{
					back[e.dst] = &e;
					pq.push({dist[e.dst] = dist[e.src] + rcost(e), e.dst});
				}
		}

		return dist[sink];
	}

	pair<flow_type, cost_type> max_flow(int source, int sink)
	{
		flow_type flow = 0;
		cost_type cost = 0;

		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;

		potential.assign(n, 0);
		dist.assign(n, 0);
		back.assign(n, nullptr);

		bellman_ford(source); // remove negative costs

		while (dijkstra(source, sink) < oo)
		{
			for (int u = 0; u < n; ++u)
				if (dist[u] < dist[sink])
					potential[u] += dist[u] - dist[sink];

			flow_type f = numeric_limits<flow_type>::max();

			for (edge *e = back[sink]; e; e = back[e->src])
				f = min(f, e->cap - e->flow);
			for (edge *e = back[sink]; e; e = back[e->src])
				e->flow += f, adj[e->dst][e->rev].flow -= f;

			flow += f;
			cost += f * (potential[sink] - potential[source]);

		}
		return {flow, cost};
	}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	
	min_cost_max_flow<int,int> mcf(n + 4);
	
	for (int i = 1; i <= n; ++i){
		int v; cin >> v;
		mcf.add_edge(0, i, 1, 0);
		
		mcf.add_edge(i, n + 1, 1, -v);
	}
	
	for (int i = 1; i <= n; ++i){
		int v; cin >> v;
		mcf.add_edge(i, n + 2, 1, -v);
	}
	
	mcf.add_edge(n + 1, n + 3, a, 0);
	mcf.add_edge(n + 2, n + 3, b, 0);
	
	auto ans = mcf.max_flow(0, n + 3);
	
	cout << -ans.second << endl;
	
	vector<vi> G(2);
	
	for (int i = 1; i <= n; ++i){
		for (auto e : mcf.adj[i])
			if (e.flow == 1) G[ e.dst - (n + 1) ].push_back(i);
	}
	
	for (int i = 0; i < 2; ++i){
		for (auto ch : G[i]) cout << ch << " ";
		cout << endl;
	}
	
    return 0;
}