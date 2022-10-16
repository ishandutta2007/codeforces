#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> bridge_blocks(graph &adj)
{
	int n = adj.n;

	vector<int> num(n), low(n), stk;
	vector<vector<int>> comps;
	vector<pair<int, int>> bridges;

	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		// remove if there isn't parallel edges
		sort(adj[u].begin(), adj[u].end());

		for (int i = 0, sz = adj[u].size(); i < sz; ++i)
		{
			int v = adj[u][i];

			if (v == p)
			{
				if (i + 1 < sz && adj[u][i + 1] == v)
					low[u] = min(low[u], num[v]);
				continue;
			}

			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);

				if (low[v] == num[v])
					bridges.push_back({u, v});
			}
			else low[u] = min(low[u], num[v]);
		}

		if (num[u] == low[u])
		{
			comps.push_back({});
			for (int v = -1; v != u; stk.pop_back())
				comps.back().push_back(v = stk.back());
		}
	};

	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);

	// this is for build the bridge-block tree
	function<graph()> build_tree = [&]()
	{
		vector<int> id(n);

		for (int i = 0; i < (int) comps.size(); ++i)
			for (int u : comps[i]) id[u] = i;

		graph tree(comps.size());

		for (auto &e : bridges)
			tree.add_edge(id[e.first], id[e.second]);

		return tree;
	};

	return comps;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    graph g(n);

    vector<int> value(n);

    for (int i = 0; i < n; ++i)
        cin >> value[i];

    int64 answer = 0;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
    }

    auto bridges = bridge_blocks(g);

    vector<int> ix(n);
    vector<int> size(n);

    for (int i = 0; i < (int)bridges.size(); ++i){
        size[i] = bridges[i].size();

        for (auto u : bridges[i]) {
            ix[u] = i;
        }
    }

    int s; cin >> s; s--;

    vector<int> vis(n);

    function<pii(int)> dfs = [&](int u){
        vis[u] = true;

        bool bic = false;
        int64 best = 0;

        for (auto v : g.adj[u]){
            if (vis[v])
                continue;

            pii cur = dfs(v);

            best = max(best, cur.first);
            bic |= cur.second;
        }

        if (size[ix[u]] == 1){
            if (bic){
                answer += value[u];
            } else {
                best += value[u];
            }
        } else {
            bic = true;
            answer += value[u];
        }

        return pii(best, bic);
    };

    pii cur = dfs(s);
    answer += cur.first;

    cout << answer << endl;

    return 0;
}