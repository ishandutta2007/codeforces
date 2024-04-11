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

llint T;
llint n, k;
string s;
map<char, llint> mp[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> s;
		
		UnionFind uf(n);
		for(int i = k; i < n; i++) uf.unite(i-k, i);
		for(int i = 0; i < k; i++) uf.unite(i, k-i-1);
		
		for(int i = 0; i < n; i++) mp[i].clear();
		for(int i = 0; i < n; i++) mp[uf.root(i)][s[i]]++;
		
		llint ans = n;
		for(int i = 0; i < n; i++){
			llint mx = 0;
			for(auto it = mp[i].begin(); it != mp[i].end(); it++){
				mx = max(mx, it->second);
			}
			ans -= mx;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}