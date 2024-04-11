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

ll n, m;
ll c[100005];
UnionFind uf(100005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> c[i];
	
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		uf.unite(u, v);
	}
	
	map<ll, ll> mp;
	rep(i, 1, n){
		ll r = uf.root(i);
		if(mp.count(r) == 0) mp[r] = inf;
		chmin(mp[r], c[i]);
	}
	
	ll ans = 0;
	for(auto x : mp) ans += x.second;
	cout << ans << endl;
	
	return 0;
}