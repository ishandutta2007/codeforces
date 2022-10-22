#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;
typedef pair<pair<llint, llint>, llint> E;

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m, Q;
vector<edge> G[100005];
vector<E> evec;
UnionFind uf(100005);

llint dist[100005];
llint pre[100005][17];
llint depth[100005];

void dfs(int v, int prev, llint d, llint dep)
{
	pre[v][0] = prev;
	dist[v] = d;
	depth[v] = dep;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == prev) continue;
		dfs(G[v][i].to, v, d + G[v][i].cost, dep+1);
	}
}

llint getLCA(int u, int v){
	llint x = u, y = v;
	if(depth[y] > depth[x]){
		llint t = x;
		x = y, y = t;
	}
	for(int i = 16; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = pre[x][i];
	}
	if(x == y) return x;
	for(int i = 16; i >= 0; i--){
		if(pre[x][i] != pre[y][i]){
			x = pre[x][i];
			y = pre[y][i];
		}
	}
	x = pre[x][0];
	return x;
}

llint distU[25][100005], distV[25][100005];

void dijkstra(llint dist[], llint S)
{
	for(int i = 1; i <= n ; i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, S) );
	
	llint v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] > d + G[v][i].cost){
				dist[G[v][i].to] = d + G[v][i].cost;
				Q.push( make_pair(dist[G[v][i].to], G[v][i].to) );
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	llint u, v, d;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> d;
		if(!uf.same(u, v)){
			G[u].push_back(edge(v, d));
			G[v].push_back(edge(u, d));
			uf.unite(u, v);
		}
		else evec.push_back(make_pair(make_pair(u, v), d));
	}
	
	dfs(1, 0, 0, 0);
	
	/*for(int i = 1; i <= n; i++) cout << pre[i][0] << " "; cout << endl;
	for(int i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;
	for(int i = 1; i <= n; i++) cout << depth[i] << " "; cout << endl;*/
	
	for(int i = 1; i < 17; i++){
		for(int j = 1; j <= n; j++){
			pre[j][i] = pre[pre[j][i-1]][i-1];
		}
	}
	
	for(int i = 0; i < evec.size(); i++){
		llint u = evec[i].first.first, v = evec[i].first.second, d = evec[i].second;
		dijkstra(distU[i], u);
		dijkstra(distV[i], v);
		G[u].push_back(edge(v, d));
		G[v].push_back(edge(u, d));
	}
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> u >> v;
		
		llint ans = dist[u] + dist[v] - 2 * dist[getLCA(u, v)];
		//cout << getLCA(u, v) << " " << ans << endl;
		for(int i = 0; i < evec.size(); i++){
			ans = min(ans, distU[i][u] + distV[i][v] + evec[i].second);
			ans = min(ans, distV[i][u] + distU[i][v] + evec[i].second);
		}
		cout << ans << endl;
	}
	
	return 0;
}