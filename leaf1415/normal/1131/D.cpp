#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

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

int w, h;
char c[1005][1005];
UnionFind uf(2005);
vector<int> G[2005], revG[2005];
bool act[2005];

vector<int> topo;
bool used[2005];
int scc[2005];
int dist[2005], ans[2005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}
void sccdfs(int v, int id)
{
	used[v] = true;
	scc[v] = id;
	for(int i = 0; i < revG[v].size(); i++){
		if(!used[revG[v][i]]) sccdfs(revG[v][i], id);
	}
}

int main(void)
{
	cin >> h >> w;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> c[i][j];
		}
	}
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(c[i][j] == '=') uf.unite(i, h+j);
		}
	}
	
	for(int i = 1; i <= h+w; i++) if(uf.root(i) == i) act[i] = true;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(c[i][j] == '=') continue;
			int u = uf.root(i), v = uf.root(h+j);
			if(u == v){
				cout << "No" << endl;
				return 0;
			}
			if(c[i][j] == '<') G[u].push_back(v), revG[v].push_back(u);
			if(c[i][j] == '>') G[v].push_back(u), revG[u].push_back(v);
		}
	}
	
	for(int i = 1; i <= h+w; i++) if(act[i] && !used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	int id = 0;
	for(int i = 1; i <= h+w; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], id++);
	
	set<int> S;
	for(int i = 1; i <= h+w; i++){
		if(!act[i]) continue;
		if(S.count(scc[i])){
			cout << "No" << endl;
			return 0;
		}
		S.insert(scc[i]);
	}
	
	for(int i = 1; i <= h+w; i++) dist[i] = 1;
	for(int i = 0; i < topo.size(); i++){
		int v = topo[i];
		for(int j = 0; j < G[v].size(); j++){
			dist[G[v][j]] = max(dist[G[v][j]], dist[v] + 1);
		}
	}
	
	cout << "Yes" << endl;
	for(int i = 1; i <= h+w; i++) ans[i] = dist[uf.root(i)];
	for(int i = 1; i <= h; i++) cout << ans[i] << " "; cout << endl;
	for(int i = 1; i <= w; i++) cout << ans[h+i] << " "; cout << endl;
	
	return 0;
}