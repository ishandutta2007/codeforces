#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef vector<bool> vb;

const int MX = 4005;
int n, vis[MX], deg[MX];
string adj[MX];

vi a;
int g;
void dfs (int u) {
	vis[u] = 1;
	a.pb(u);
	
	forr (v, 1, n)
		if (!vis[v] && adj[u][v] == ((g == u || g == v) ? '0' : '1'))
			dfs(v);
}

int inf = 1 << 30;

struct edge{
	int source, dest, cost;

	edge(): source(0), dest(0), cost(0){}

	edge(int dest, int cost): dest(dest), cost(cost){}

	edge(int source, int dest, int cost): source(source), dest(dest), cost(cost){}

	bool operator==(const edge & b) const{
		return source == b.source && dest == b.dest && cost == b.cost;
	}
	bool operator<(const edge & b) const{
		return cost < b.cost;
	}
	bool operator>(const edge & b) const{
		return cost > b.cost;
	}
};

struct graph{
	vector<vector<edge>> adjList;
	vector<vb> adjMatrix;
	vector<vi> costMatrix;
	vector<edge> edges;
	int V = 0;
	bool dir = false;

	graph(int n, bool dir): V(n), dir(dir), adjList(n), edges(n), adjMatrix(n, vb(n)), costMatrix(n, vi(n)){
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				costMatrix[i][j] = (i == j ? 0 : inf);
	}

	void add(int source, int dest, int cost){
		adjList[source].emplace_back(source, dest, cost);
		edges.emplace_back(source, dest, cost);
		adjMatrix[source][dest] = true;
		costMatrix[source][dest] = cost;
		if(!dir){
			adjList[dest].emplace_back(dest, source, cost);
			adjMatrix[dest][source] = true;
			costMatrix[dest][source] = cost;
		}
	}
	
	vb articulationBridges(){
		vi low(V), label(V);
		vb points(V);
		int time = 0;
		function<int(int, int)> dfs = [&](int u, int p){
			label[u] = low[u] = ++time;
			int hijos = 0, ret = 0;
			for(edge & current : adjList[u]){
				int v = current.dest;
				if(v == p && !ret++) continue;
				if(!label[v]){
					++hijos;
					dfs(v, u);
					if(label[u] <= low[v])
						points[u] = true;
					low[u] = min(low[u], low[v]);
				}
				low[u] = min(low[u], label[v]);
			}
			return hijos;
		};
		for(int u = 0; u < V; ++u)
			if(!label[u])
				points[u] = dfs(u, -1) > 1;
		return points;
	}
}*k;

void main_() {
	// 0 -> Grafo actualmente conexo
	// 1 -> Hay un nodo aislado
	// 1 -> Probar cambiar todos los nodos
	// A partir de aqu todas las componentes son cliques
	// 2 -> Hay tres o ms componentes conexas
	// mn(sz(c1), sz(c2)) -> Hay dos componentes c1 y c2
	
	cin >> n;
	forr (i, 1, n) {
		cin >> adj[i];
		adj[i] = "*" + adj[i];
		
		deg[i] = 0;
		forr (j, 1, n)
			deg[i] += adj[i][j] == '1';
	}
	
	vvi v;
	memset(vis, 0, sizeof(vis));
	forr (i, 1, n) {
		if (!vis[i]) {
			a.clear();
			g = 0;
			dfs(i);
			
			if (a.size() == n) {
				cout << 0 << endl;
				return;
			}
			
			if (a.size() == 1) {
				cout << 1 << endl;
				cout << i << endl;
				return;
			}
			
			v.pb(a);
		}
	}
	
	k = new graph(n + 5, 0);
	forr (i, 1, n)
	forr (j, i, n)
		if (adj[i][j] == '1')
			k->add(i, j, 0);
	
	auto p = k->articulationBridges();
	
	for (vi &b : v) {
		for (int u : b)
			if (!p[u] && deg[u] + 1 < b.size()) {
				cout << 1 << endl;
				cout << u << endl;
				return;
			}
	}
	
	if (v.size() >= 3) {
		cout << 2 << endl;
		cout << v[0][0] << " " << v[1][0] << endl;
		return;
	}
	
	if (v[0].size() > v[1].size())
		swap(v[0], v[1]);
		
	cout << v[0].size() << endl;
	for (int u : v[0])
		cout << u << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}