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

typedef int llint;
typedef int ll;
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

int h, w;
int pa[1<<14], a[1<<14];
bool b[1<<14], used[40005];
UnionFind uf(40005);

void makeline()
{
	char c; int C;
	rep(x, 0, w-1) b[x] = false;
	rep(x, 0, w/4-1){
		cin >> c;
		if(c >= '0' && c <= '9') C = c - '0';
		else C = c - 'A' + 10;
		int p = x*4;
		if(C&8) b[p] = true;
		if(C&4) b[p+1] = true;
		if(C&2) b[p+2] = true;
		if(C&1) b[p+3] = true;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	ll ans = 0, W = 40000;
	rep(y, 0, h-1){
		makeline();
		
		rep(i, 1, W) used[i] = false;
		rep(x, 0, w-1) if(pa[x]) used[pa[x]] = true;
		
		ll id = 1;
		rep(x, 0, w-1) a[x] = 0;
		rep(x, 0, w-1){
			if(!b[x]) continue;
			if(x == 0 || b[x-1] == false) while(used[id]) id++;
			used[id] = true, a[x] = id;
		}
		
		if(y >= 1){
			uf.init();
			rep(x, 0, w-1) if(pa[x] && a[x]) uf.unite(pa[x], a[x]);
			rep(x, 0, w-1){
				pa[x] = uf.root(pa[x]);
				a[x] = uf.root(a[x]);
			}
			
			rep(i, 1, W) used[i] = false;
			rep(x, 0, w-1) used[pa[x]] = pa[x];
			rep(x, 0, w-1) used[a[x]] &= !a[x];
			rep(i, 1, W) if(used[i]) ans++;
		}
		rep(x, 0, w-1) pa[x] = a[x];
	}
	rep(i, 1, W) used[i] = false;
	rep(x, 0, w-1) if(pa[x]) used[pa[x]] = true;
	rep(i, 1, W) if(used[i]) ans++;
		
	cout << ans << endl;
	
	return 0;
}