#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

struct graph
{
	int n;
	vector<vector<int> > adj, radj;

	graph(int n) : n(n), adj(n), radj(n) {}

	void add_edge(int src, int dst)
	{
		adj[src].push_back(dst);
		radj[dst].push_back(src);
	}

	vector<int> rank, semi, low, anc;

	int eval(int v)
	{
		if (anc[v] < n && anc[anc[v]] < n)
		{
			int x = eval(anc[v]);
			if (rank[semi[low[v]]] > rank[semi[x]])
				low[v] = x;
			anc[v] = anc[anc[v]];
		}
		return low[v];
	}

	vector<int> prev, ord;

	void dfs(int u)
	{
		rank[u] = ord.size();
		ord.push_back(u);
		for (int i = 0; i < (int) adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if (rank[v] < n)
				continue;
			dfs(v);
			prev[v] = u;
		}
	}

	vector<int> idom; // idom[u] is an immediate dominator of u

	void dominator_tree(int r)
	{
		idom.assign(n, n);
		prev = rank = anc = idom;
		semi.resize(n);
		for (int i = 0; i < n; ++i)
			semi[i] = i;
		low = semi;
		ord.clear();
		dfs(r);

		vector<vector<int> > dom(n);
		for (int x = (int) ord.size() - 1; x >= 1; --x)
		{
			int w = ord[x];
			for (int j = 0; j < (int) radj[w].size(); ++j)
			{
				int v = radj[w][j];
				int u = eval(v);
				if (rank[semi[w]] > rank[semi[u]])
					semi[w] = semi[u];
			}
			dom[semi[w]].push_back(w);
			anc[w] = prev[w];
			for (int i = 0; i < (int) dom[prev[w]].size(); ++i)
			{
				int v = dom[prev[w]][i];
				int u = eval(v);
				idom[v] = (rank[prev[w]] > rank[semi[u]] ? u : prev[w]);
			}
			dom[prev[w]].clear();
		}

		for (int i = 1; i < (int) ord.size(); ++i)
		{
			int w = ord[i];
			if (idom[w] != semi[w])
				idom[w] = idom[idom[w]];
		}
	}

	vector<int> dominators(int u)
	{
		vector<int> S;
		for (; u < n; u = idom[u])
			S.push_back(u);
		return S;
	}
};

vector<pii> adj[maxn];
int64 dist[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, s;
	cin >> n >> m >> s;
	s--;

	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for (int i = 0; i < n; ++i)
		dist[i] = oo;

	priority_queue<pair<int64,int>> pq;

	pq.push({0, s});
	dist[s] = 0;

	while (!pq.empty()){
		auto cur = pq.top(); pq.pop();
		
		int64 d = -cur.first;
		int u = cur.second;

		if (dist[u] < d) continue;

		for (auto e : adj[u]){
			int v = e.first;

			if (dist[v] > dist[u] + e.second){
				dist[v] = dist[u] + e.second;
				pq.push({-dist[v], v});
			}
		}
	}

	graph g(n);

	for (int i = 0; i < n; ++i){
		for (auto e : adj[i])
			if (dist[i] + e.second == dist[e.first]){
				g.add_edge(i, e.first);
			}
	}

	g.dominator_tree(s);

	vector<vi> to(n);

	for (int i = 0; i < n; ++i){
		if (g.idom[i] < n)
			to[ g.idom[i] ].push_back(i);
	}

	int answer = 0;

	function<int(int)> dfs = [&](int s){
		int t = 1;
		for (auto u : to[s])
			t += dfs(u);
		return t;
	};

	for (auto u : to[s])
		answer = max(answer, dfs(u));

	cout << answer << endl;

	return 0;
}