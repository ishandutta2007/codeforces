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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

struct SegTree{
	int size;
	vector<P> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = P(0, -inf);
	}
	
	void update(int i, P val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = max(seg[i*2], seg[i*2+1]);
		}
	}

	P query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return P(0, -inf);
		if(a <= l && r <= b) return seg[k];
		P lval = query(a, b, k*2, l, (l+r)/2);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	P query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

struct UnionFindTree{
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


int n, m, Q;
int u[300005], v[300005];
int p[200005];
int t[500005], x[500005];
bool used[300005];
int l[1000005], r[1000005];
SegTree seg(20);

UnionFindTree uf(200005);
int pos[500005];

llint id = 0;
void dfs(int v)
{
	l[v] = id+1;
	if(uf.tree[v].first == -1){
		id++;
		seg.update(id, P(p[v], id));
	}
	else{
		dfs(uf.tree[v].first);
		dfs(uf.tree[v].second);
	}
	r[v] = id;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i];
	}
	for(int i = 1; i <= Q; i++) cin >> t[i] >> x[i];
	
	for(int i = 1; i <= Q; i++) if(t[i] == 2) used[x[i]] = true;
	for(int i = 1; i <= m; i++){
		if(used[i]) continue;
		uf.unite(u[i], v[i]);
	}
	
	for(int i = Q; i >= 1; i--){
		if(t[i] == 2) uf.unite(u[x[i]], v[x[i]]);
		else pos[i] = uf.gettop(x[i]);
	}
	
	set<int> rset;
	for(int i = 1; i <= n; i++) rset.insert(uf.gettop(i));
	for(auto it = rset.begin(); it != rset.end(); it++) dfs(*it);
	
	for(int i = 1; i <= Q; i++){
		if(t[i] == 1){
			int v = pos[i];
			P res = seg.query(l[v], r[v]);
			cout << res.first << "\n";
			if(res.first > 0) seg.update(res.second, P(0, res.second));
		}
	}
	flush(cout);
	
	return 0;
}