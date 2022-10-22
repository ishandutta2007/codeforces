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
typedef pair<llint, P> E;

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

llint m, n;
llint a[100005], b[100005];
vector<E> vec;
UnionFind uf(500005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	llint ans = 0, s, x;
	for(int i = 1; i <= m; i++){
		cin >> s;
		for(int j = 0; j < s; j++){
			cin >> x;
			ans += a[i]+b[x];
			vec.push_back(E(a[i]+b[x], P(i, m+x)));
			
		}
	}
	sort(vec.rbegin(), vec.rend());
	
	for(int i = 0; i < vec.size(); i++){
		llint w = vec[i].first, u = vec[i].second.first, v = vec[i].second.second;
		if(uf.same(u, v)) continue;
		ans -= w;
		uf.unite(u, v);
	}
	cout << ans << endl;
	
	return 0;
}