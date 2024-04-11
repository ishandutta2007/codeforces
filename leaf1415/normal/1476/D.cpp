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
	vector<int> rank;
	vector<int> v, e;
	
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


ll T;
ll n;
string s;
map<ll, ll> mp;
ll ans[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> s;
		s = "#" + s;
		
		UnionFind uf(n+5);
		rep(i, 1, n){
			if(i%2 && s[i] == 'R') uf.unite(i-1, i);
			if(i%2==0 && s[i] == 'L') uf.unite(i-1, i);
		}
		mp.clear();
		rep(i, 0, n) mp[uf.root(i)]++;
		rep(i, 0, n) if(i % 2 == 0) ans[i] = mp[uf.root(i)];
		
		uf.init();
		rep(i, 1, n){
			if(i%2==0 && s[i] == 'R') uf.unite(i-1, i);
			if(i%2 && s[i] == 'L') uf.unite(i-1, i);
		}
		mp.clear();
		rep(i, 0, n) mp[uf.root(i)]++;
		rep(i, 0, n) if(i % 2) ans[i] = mp[uf.root(i)];
		
		rep(i, 0, n) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}