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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

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

ll n, m, Q;
ll u[500005], v[500005], w[500005];
vector<P> vec[500005];
vector<E> qvec[500005];
UndoUnionFind uf(500005);
bool ng[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, m){
		cin >> u[i] >> v[i] >> w[i];
		vec[w[i]].push_back(P(u[i], v[i]));
	}
	
	cin >> Q;
	ll x, y;
	rep(q, 1, Q){
		cin >> x;
		rep(i, 1, x){
			cin >> y;
			qvec[w[y]].push_back(E(q, P(u[y], v[y])));
		}
	}
	
	rep(i, 1, 500000){
		ll cnt = 0, pre = 0;
		for(auto e : qvec[i]){
			ll id = e.first, u = e.second.first, v = e.second.second;
			if(pre != id){
				rep(j, 1, cnt) uf.undo();
				cnt = 0;
			}
			if(uf.same(u, v)) ng[id] = true;
			if(uf.unite(u, v)) cnt++;
			pre = id;
		}
		rep(j, 1, cnt) uf.undo();
		for(auto e : vec[i]) uf.unite(e.first, e.second);
	}
	
	rep(i, 1, Q){
		if(ng[i]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	flush(cout);
	
	return 0;
}