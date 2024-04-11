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

llint n, m;
UnionFind uf(200005);
map<llint, llint> mp;
llint lcnt[200005], rcnt[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		uf.unite(u, v);
	}
	
	for(llint i = 1; i <= n; i++) chmax(mp[uf.root(i)], i);
	
	for(int i = 1; i <= n; i++){
		llint l = i, r = mp[uf.root(l)];
		lcnt[l]++;
		rcnt[r]++;
	}
	
	llint ans = 0, cnt = 0;
	for(int i = 1; i <= n-1; i++){
		cnt += lcnt[i];
		cnt -= rcnt[i];
		if(cnt > 0){
			if(!uf.same(i, i+1)){
				uf.unite(i, i+1);
				ans++;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}