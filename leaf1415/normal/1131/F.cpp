#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#define llint long long

using namespace std;
typedef pair<llint, pair<llint, llint> > E;

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

struct node{
	llint left, right, id;
	node(){
		id = left = right = -1;
	};
};

llint n;
int x[150005], y[150005];
UnionFind uf(150005);
llint rt[150005];
vector<node> tree;


void dfs(int v)
{
	if(tree[v].id != -1){
		cout << tree[v].id << " ";
		return;
	}
	dfs(tree[v].left);
	dfs(tree[v].right);
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n-1; i++) cin >> x[i] >> y[i];
	
	for(int i = 1; i <= n; i++) tree.push_back(node());
	for(int i = 1; i <= n; i++) tree[i-1].id = i;
	for(int i = 1; i <= n; i++) rt[i] = i-1;
	
	for(int i = 1; i <= n-1; i++){
		int u = x[i], v = y[i];
		tree.push_back(node());
		tree.back().left = rt[uf.root(u)];
		tree.back().right = rt[uf.root(v)];
		uf.unite(u, v);
		rt[uf.root(u)] = tree.size()-1;
	}
	
	dfs((int)tree.size()-1);
	cout << endl;
	
	return 0;
}