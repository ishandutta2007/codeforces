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
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		rank.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i, rank[i] = 0;
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
		
		if(rank[root_i] < rank[root_j]) parent[root_i] = root_j;
		else parent[root_j] = root_i;
		if(rank[root_i] == rank[root_j]) rank[root_i]++;
	}
};


ll T;
ll n, m;
ll p[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n) p[i] = 0;
		
		UnionFind uf(n);
		ll x, y, ans = 0;
		rep(i, 1, m){
			cin >> x >> y;
			if(x == y) continue;
			ans++;
			if(uf.same(x, y)) ans++;
			uf.unite(x, y);
		}
		cout << ans << endl;
	}
	
	return 0;
}