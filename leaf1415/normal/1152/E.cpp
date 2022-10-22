#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;
typedef pair<int, int> edge;

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

int n;
int a[100005], b[100005];
vector<int> comp, G[200005];



multiset<int> g[200005];
bool used[200005];
stack<int> stk;

void connectdfs(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		connectdfs(G[v][i]);
	}
}
void pathdfs(int v, int t, bool flag)
{	
	//cout << v << " " << t << endl;
	stk.push(v);
	if(flag && v == t) return;
	int u = *g[v].begin();
	//cout << "->" << u << endl;
	g[v].erase(g[v].begin()), g[u].erase(g[u].lower_bound(v));
	pathdfs(u, t, true);
}


bool EulerianTrail(vector<int> G[], int V, vector<int> &dest)
{
	for(int i = 1; i <= V; i++) used[i] = false;  //check connectivity
	connectdfs(1);
	for(int i = 1; i <= V; i++) if(!used[i]) return false;
	
	for(int i = 1; i <= V; i++){
		g[i].clear();
		for(int j = 0; j < G[i].size(); j++) g[i].insert(G[i][j]);
	}
	
	vector<int> odd;  //check whether the number of vertices with odd degree is not greater than 2
	for(int i = 1; i <= V; i++){
		if(g[i].size()%2) odd.push_back(i);
	}
	if(odd.size() > 2) return false;
	
	if(odd.size() > 0) pathdfs(odd[0], odd[1], true);  //find a path initially
	else pathdfs(1, 1, false);
	
	dest.clear();  //extend the path to cover all edges
	while(stk.size()){
		int v = stk.top();
		stk.pop();
		if(g[v].size() == 0) dest.push_back(v);
		else pathdfs(v, v, false);
	}
	return true;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n-1; i++) cin >> a[i];
	for(int i = 1; i <= n-1; i++) cin >> b[i];
	for(int i = 1; i <= n-1; i++){
		if(a[i] > b[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n-1; i++) comp.push_back(a[i]);
	for(int i = 1; i <= n-1; i++) comp.push_back(b[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n-1; i++) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
	for(int i = 1; i <= n-1; i++) b[i] = lower_bound(comp.begin(), comp.end(), b[i]) - comp.begin() + 1;
	int V = comp.size();
	
	for(int i = 1; i <= n-1; i++){
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	
	vector<int> ans;
	if(!EulerianTrail(G, V, ans)){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 0; i < ans.size(); i++) cout << comp[ans[i]-1] << " "; cout<< endl;
	return 0;
}