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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 998244353

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

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


llint n, m, k;
llint c[500005];
map<P, vector<P> > mp;
bool invalid[500005];
UndoUnionFind uf(1000005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	rep(i, 1, n) cin >> c[i];
	llint u, v;
	rep(i, 1, m){
		cin >> u >> v;
		if(c[u] == c[v]) uf.unite(u, v+n), uf.unite(u+n, v);
		else{
			llint x = c[u], y = c[v];
			if(x > y) swap(x, y);
			mp[P(x, y)].push_back(P(u, v));
		}
	}
	rep(i, 1, n) if(uf.same(i, i+n)) invalid[c[i]] = true;
	
	int cnt = 0;
	rep(i, 1, k) if(invalid[i]) cnt++;
	k -= cnt;
	
	llint ans = k*(k-1)/2;
	for(auto &x: mp){
		int u = x.first.first, v = x.first.second;
		if(invalid[u] || invalid[v]) continue;
		
		vector<P> &vec = x.second;
		int cnt = 0;
		for(auto e : vec){
			int u = e.first, v = e.second;
			if(uf.unite(u, v+n)) cnt++;
			if(uf.unite(u+n, v)) cnt++;
		}
		bool flag = true;
		for(auto e : vec){
			int u = e.first, v = e.second;
			if(uf.same(u, u+n) || uf.same(v, v+n)) flag = false;
		}
		if(!flag) ans--;
		rep(i, 1, cnt) uf.undo();
	}
	cout << ans << endl;
	
	return 0;
}