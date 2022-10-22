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

int T;
llint n;
llint p[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		reverse(p+1, p+n+1);
		
		UnionFind uf(n); map<llint, llint> mp;
		set<llint> S;
		for(int i = 1; i <= n; i++){
			if(S.size() == 0 || *S.begin() > p[i]){
				S.insert(p[i]);
				continue;
			}
			auto it = S.lower_bound(p[i]); it--;
			for(;;){
				uf.unite(p[i], *it);
				if(it == S.begin()) break;
				auto tmp = it;
				it--;
				S.erase(tmp);
			}
		}
		for(int i = 1; i <= n; i++) mp[uf.root(i)]++;
		cout << mp.size() << endl;
	}
	
	return 0;
}