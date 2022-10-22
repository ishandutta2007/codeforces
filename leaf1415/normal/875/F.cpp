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

struct UnionFind{
	int size;
	vector<int> parent;
	vector<int> rank;
	vector<int> v, e;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		rank.resize(size+1);
		v.resize(size+1), e.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i, rank[i] = 0, v[i] = 1, e[i] = 0;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	bool unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j){
			if(e[root_i] < v[root_i]){
				e[root_i]++;
				return true;
			}
			return false;
		}
		if(v[root_i] + v[root_j] >= e[root_i] + e[root_j] + 1){
			parent[root_i] = root_j;
			v[root_j] += v[root_i], e[root_j] += e[root_i] + 1;
			return true;
		}
		return false;
	}
};

ll n, m;
vector<E> vec;
UnionFind uf(200005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v, w;
	rep(i, 1, m){
		cin >> u >> v >> w;
		vec.push_back(E(w, P(u, v)));
	}
	sort(all(vec));
	reverse(all(vec));
	
	ll ans = 0;
	for(auto e : vec)
	{
		ll w = e.first, u = e.second.first, v = e.second.second;
		if(uf.unite(u, v)) ans += w;
	}
	cout << ans << endl;
	
	return 0;
}