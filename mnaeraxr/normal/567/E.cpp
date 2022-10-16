#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<pii> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100100;

int n, m, s, t;

struct edge{
	int to, idx;
	int64 w;
};

vector<edge> g1[maxn], g2[maxn];
vi ady[maxn];

vector<int64> dijkstra(int s, vector<edge> g[maxn]){
	vector<int64> dist(n + 1, oo);
	dist[s] = 0;

	priority_queue<pair<int64,int>> pq;
	pq.push({0, s});

	while (!pq.empty()){
		auto cur = pq.top(); pq.pop();
		int64 t = -cur.first;
		int c = cur.second;

		if (dist[c] < t)
			continue;

		for (auto e : g[c]){
			int64 d = dist[c] + e.w;
			int nx = e.to;

			if (dist[nx] > d){
				dist[nx] = d;
				pq.push({-dist[nx], nx});
			}
		}
	}

	return dist;
}

int64 ans[maxn];

// Bridges

int pi[maxn], h[maxn], low[maxn];
bool mk[maxn];

bool bridges[maxn];
bool not_bridges[maxn];

void dfs(int s)
{
	mk[s] = true;
	low[s] = h[s];
	for(int i = 0; i < (int)ady[s].size(); i++)
	{
		int v = ady[s][i].first;
		if(!mk[v])
		{
			pi[v] = s;
			h[v] = h[s]+1;
			dfs(v);

			if(low[v] > h[s])
				bridges[ady[s][i].second] = true;

			low[s] = min(low[s], low[v]);
		}
		if(v != pi[s])
			low[s] = min(low[s],h[v]);
	}
}

map<pii, int> edges;

void my_push(int u, int v, int idx){	
	if (u > v) swap(u, v);
	pii cur = {u, v};

	if (edges.count(cur)){
		not_bridges[edges[cur]] = true;
		return;
	}

	edges[cur] = idx;

	ady[u].push_back({v, idx});
	ady[v].push_back({u, idx});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s >> t;

	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g1[u].push_back({v, i, 1LL * w});
		g2[v].push_back({u, i, 1LL * w});
	}

	vector<int64> d1 = dijkstra(s, g1);
	vector<int64> d2 = dijkstra(t, g2);

	int64 short_dist = d1[t];

	for (int i = 1; i <= n; ++i){
		int u = i;
		for (auto e : g1[u]){
			int v = e.to;

			if (d1[u] + e.w + d2[v] == short_dist){
				my_push(u, v, e.idx);

				if (e.w > 1) ans[e.idx] = 1;
				else ans[e.idx] = -1;
			}
			else{
				int64 tor = d1[u] + e.w + d2[v] - short_dist + 1;

				if (tor >= e.w) ans[e.idx] = -1;
				else ans[e.idx] = tor;
			}
		}
	}

	h[s] = 0;
	dfs(s);

	for (int i = 0; i < m; ++i){
		if (!not_bridges[i] && bridges[i]) cout << "YES" << endl;
		else if (ans[i] > 0) cout << "CAN " << ans[i] << endl;
		else cout << "NO" << endl;
	}

	return 0;
}