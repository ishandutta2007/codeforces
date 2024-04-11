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
llint a[200005];
llint lb[200005], ub[200005], mid[200005];
llint u[200005], v[200005];
UnionFind uf(200005);
vector<llint> vec[200005];
llint dif[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m-1; i++) cin >> u[i] >> v[i];
	
	for(int i = 1; i <= n-1; i++) ub[i] = m-1, lb[i] = -1;
	for(int i = 0; i < 20; i++){
		for(int j = 1; j <= m-1; j++) vec[j].clear();
		for(int j = 1; j <= n-1; j++){
			if(ub[j]-lb[j] > 1){
				mid[j] = (ub[j]+lb[j])/2;
				vec[mid[j]].push_back(j);
			}
		}
		uf.init();
		for(int j = 0; j <= m-1; j++){
			uf.unite(u[j], v[j]);
			for(int k = 0; k < vec[j].size(); k++){
				llint qid = vec[j][k];
				if(uf.same(a[qid], a[qid+1])) ub[qid] = mid[qid];
				else lb[qid] = mid[qid];
			}
		}
	}
	for(int i = 1; i <= n-1; i++) dif[0]++, dif[ub[i]]--;
	for(int i = 1; i <= m; i++) dif[i] += dif[i-1];
	
	for(int i = 0; i <= m-1; i++) cout << dif[i] << "\n";
	flush(cout);
	
	
	return 0;
}