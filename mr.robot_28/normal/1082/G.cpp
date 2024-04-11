#include <bits/stdc++.h>

using namespace std;

typedef long long li;

const int N = 2009;
const int INF = int(1e9) + 777;

struct edge{
	int to, f, c;
	edge () {}
	edge (int to, int f, int c) : to(to), f(f), c(c) {}
};

int n, m;
int s, t;
vector<edge> edges;
vector <int> g[N];
int u[N], cu;

void addEdge(int v, int to, int cap){

	g[v].push_back(edges.size());
	edges.push_back(edge(to, 0, cap));

	g[to].push_back(edges.size());
	edges.push_back(edge(v, 0, 0));
}

int dfs(int v, int need){
	if(v == t) return need;
	u[v] = cu;
	for(auto to : g[v]){
		edge &e = edges[to];
		if(u[e.to] != cu && e.c - e.f >= need){
			int add = dfs(e.to, need);
			if(add > 0){
				edges[to].f += add;
				edges[to ^ 1].f -= add;
				return add;
			}
		}
	}
	return 0;
}

li enlarge(int k){
	li res = 0;
	while(true){
		++cu;
		int add = dfs(s, k);
		res += add;
		if(add == 0) break;
	}
	return res;
}

li maxFlow(){
	li flow = 0;
	for(int k = (1 << 29); k > 0; k >>= 1){
		flow += enlarge(k);
	}
	return flow;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int nn, mm;
	cin >> nn >> mm;
	n = nn + mm + 5;
	m = nn + mm + mm + mm + 5;
	s = n - 1, t = n - 2;
	
	for(int i = 0; i < nn; ++i){
		int a;
		cin >> a;
		addEdge(i + mm, t, a);
	}

	li sum = 0;
	for(int i = 0; i < mm; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		sum += w;
		
		addEdge(s, i, w);
		addEdge(i, u + mm, INF);
		addEdge(i, v + mm, INF);
	}
	
	li fl = maxFlow();
	cout << sum - fl << endl;
	
	return 0;
}