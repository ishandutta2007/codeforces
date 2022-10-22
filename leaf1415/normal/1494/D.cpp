#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef int ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

struct UnionFind{
	int size;
	vector<int> parent;
	vector<int> rank;
	vector<llint> v, e;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		rank.resize(size+1);
		v.resize(size+1);
		e.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++){
			parent[i] = i, rank[i] = 0;
			v[i] = 1, e[i] = 0;
		}
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void merge(int i, int j){ // j will become new root
		parent[i] = j;
		v[j] += v[i];
		e[j] += e[i] + 1;
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j){
			e[root_i]++;
			return;
		}
		if(rank[root_i] < rank[root_j]) merge(root_i, root_j);
		else merge(root_j, root_i);
		if(rank[root_i] == rank[root_j]) rank[root_i]++;
	}
};


struct WeightedUnionFind{
	int size;
	vector<int> parent;
	vector<llint> weight;
	
	WeightedUnionFind(){}
	WeightedUnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		weight.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i, weight[i] = 0;
	}
	int root(int i){
		if(parent[i] == i) return i;
		int r = root(parent[i]);
		weight[i] = weight[parent[i]] + weight[i];
		return parent[i] = r;
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	llint get(int i, int j){ //i->j0
		if(!same(i, j)) return 0;
		return weight[j]-weight[i];
	}
	bool unite(int i, int j, llint x){ //i->jxfalse
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j){
			return get(i, j) == x;
		}
		parent[root_i] = root_j;
		weight[root_i] = weight[j]-weight[i]-x;
		return true;
	}
};


struct TreeUnionFind{
	int size;
	vector<int> parent, top;
	vector<P> tree;
	
	UnionFindTree(){}
	UnionFindTree(int size){
		this->size = size;
		parent.resize(size+1);
		top.resize(size+1);
		tree.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++){
			parent[i] = i;
			tree[i] = P(-1, -1);
			top[i] = i;
		}
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	int unite(int i, int j){  //
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return -1;
		
		tree.push_back(P(top[root_i], top[root_j]));
		parent[root_i] = root_j;
		top[root_j] = (int)tree.size()-1;
		return top[root_j];
	}
	int gettop(int i){ //
		return top[root(i)];
	}
};


struct UndoUnionFind{
	typedef pair<pair<int, int>, int> E;
	int size;
	vector<int> parent;
	vector<int> rank;
	stack<E> stk;
	
	UndoUnionFind(){}
	UndoUnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		rank.resize(size+1);
		init();
	}
	void init(){
		while(stk.size()) stk.pop();
		for(int i = 0; i <= size; i++) parent[i] = i, rank[i] = 0;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	bool unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return false;
		
		E e = E(P(0, 0), 0);
		if(rank[root_i] < rank[root_j]){
			parent[root_i] = root_j;
			e.first = P(root_i, root_j);
		}else{
			parent[root_j] = root_i;
			e.first = P(root_j, root_i);
		}
		if(rank[root_i] == rank[root_j]){
			rank[root_i]++, e.second = 1;
		}
		stk.push(e);
		return true;
	}
	void undo(){
		E e = stk.top();
		stk.pop();
		
		int u = e.first.first, v = e.first.second;
		if(e.second) rank[v]--;
		parent[u] = u;
	}
};

ll n;
ll a[505][505];
vector<ll> G[1005];
ll ans[1005];
vector<ll> tvec[505];
UnionFind uf(505);
ll id;

void calc(vector<ll> vec, ll r)
{
	//cout << r << " "; for(auto v : vec) cout << v << " "; cout << endl;
	
	if(vec.size() == 1){
		ans[r] = a[r][r];
		return;
	}
	
	for(auto v : vec) uf.parent[v] = v;
	
	ll mx = 0;
	for(auto u : vec) for(auto v : vec) chmax(mx, a[u][v]);
	for(auto u : vec) for(auto v : vec){
		if(a[u][v] < mx) uf.unite(u, v);
	}
	
	set<ll> S;
	for(auto v : vec) S.insert(uf.root(v));
	
	ans[r] = mx;
	for(auto v : vec) tvec[v].clear();
	for(auto v : vec) tvec[uf.root(v)].push_back(v);
	for(auto v : S){
		ll nr;
		if(tvec[v].size() == 1) nr = tvec[v].front();
		else nr = id++;
		G[r].push_back(nr), calc(tvec[v], nr);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];
	
	vector<ll> vec;
	rep(i, 1, n) vec.push_back(i);
	
	id = n+1;
	calc(vec, id++);
	ll k = id-1;
	
	cout << k << endl;
	rep(i, 1, k) cout << ans[i] << " "; cout << endl;
	cout << n+1 << endl;
	rep(i, 1, k) for(auto v : G[i]) cout << v << " " << i << endl;
	
	return 0;
}