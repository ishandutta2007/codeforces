#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 100000000000000000LL;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool compare(pii a, pii b){
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

struct edge{
	pii u, v;
};

void print(pii a){
	cout << a.first << "::" << a.second << " ";
}

pii dfs(vector<pii> &diag, vector<edge> &edges, int &p){
//	cout << "dfs: "; print(diag[p]);
//	cout << endl;

	vector<pii> neig;
	int b, e;

	int c = p++;

	for (;p < (int)diag.size() && diag[p].first < diag[c].second;){
		b = diag[p].first, e = diag[p].second;
		neig.push_back( dfs(diag, edges, p) );
	}

	if (neig.empty())
		return {diag[c].second, diag[c].second - 1};

	pii id(diag[c].second, diag[c].second - 1);

	if (e == diag[c].second)
		id.second = b;

	for (auto nn : neig){
		edges.push_back( {id, nn} );
//		cout << "edge: "; print(nn); print(id);
//		cout << endl;
	}

	return id;
}

bool mk[maxn];
int q[maxn], p[maxn], sz[maxn], mc[maxn];
int answer[maxn];

int centroid(int c, vector<vi> &adj){
	int b = 0, e = 0;
	q[e++] = c,	p[c] = -1, sz[c] = 1, mc[c] = 0;

	while (b < e){
		int u = q[b++];
		for (auto v : adj[u]) if (v != p[u] && !mk[v])
				p[v] = u, sz[v] = 1, mc[v] = 0, q[e++] = v;
	}

	for (int i = e - 1; ~i; --i){
		int u = q[i];
		int bc = max(e - sz[u], mc[u]);
		if (2 * bc <= e) return u;
		sz[p[u]] += sz[u], mc[p[u]] = max(mc[p[u]], sz[u]);
	}

	assert(false);
	return -1;
}

void calc(int u, vector<vi> &adj, int v){
	int c = centroid(u, adj);

	mk[c] = true;
	answer[c] = v;

	for (auto neig : adj[c]){
		if (mk[neig]) continue;

		calc( neig, adj, v + 1 );
	}
}

void solve(vector<vi> &adj){
	int n = (int)adj.size();
	calc(0, adj, 1);

	for (int i = 0; i < n; ++i)
		cout << answer[i] << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	if (m == 0){
		cout << 1 << endl;
		return 0;
	}

	vector<pii> diag(m);

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);

		diag[i] = pii(u, v);
	}

	diag.push_back(pii(1, n));
	sort(diag.begin(), diag.end(), compare);

	vector<edge> edges;

	int pos = 0;
	dfs(diag, edges, pos);

	vector<pii> nodes;

	for (auto &e : edges){
		nodes.push_back(e.u);
		nodes.push_back(e.v);
	}

	sort(nodes.begin(), nodes.end());
	nodes.resize( unique(nodes.begin(), nodes.end()) - nodes.begin() );

	int total = nodes.size();

	vector<vi> adj(total);

	for (auto &e : edges){
		int pu = lower_bound( nodes.begin(), nodes.end(), e.u ) - nodes.begin();
		int pv = lower_bound( nodes.begin(), nodes.end(), e.v ) - nodes.begin();

		adj[pu].push_back(pv);
		adj[pv].push_back(pu);

//		cout << pu << " " << pv << endl;
	}

//	return 0;

	solve(adj);

	return 0;
}