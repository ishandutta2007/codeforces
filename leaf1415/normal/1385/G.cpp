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
llint n;
llint a[2][200005];
vector<P> vec[200005];
vector<llint> G[400005];
bool used[400005];

vector<llint> pvec, nvec;
void dfs(int v)
{
	if(v > n){
		used[v-n] = true;
		nvec.push_back(v);
	}
	else{
		used[v] = true;
		pvec.push_back(v);
	}
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		if(u > n && used[u-n]) continue;
		if(u <= n && used[u]) continue;
		dfs(u);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n;
		for(int i = 1; i <= n; i++) vec[i].clear();
		for(int i = 0; i < 2; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
				vec[a[i][j]].push_back(P(i, j));
			}
		}
		bool flag = true;
		for(int i = 1; i <= n; i++){
			if(vec[i].size() != 2) flag = false;
		}
		if(!flag){
			cout << -1 << endl;
			continue;
		}
		
		UnionFind uf(2*n+5);
		for(int i = 1; i <= 2*n; i++) G[i].clear();
		
		for(int i = 1; i <= n; i++){
			P p = vec[i][0], q = vec[i][1];
			if(p.second == q.second) continue;
			for(int j = 0; j < 2; j++){
				llint x = abs(p.first-j), y = abs(q.first-(1-j));
				llint u = x*n+p.second, v = y*n+q.second;
				G[u].push_back(v);
				G[v].push_back(u);
				uf.unite(u, v);
				//cout << p.second << " " << x << " <-> " << q.second << " " << y << endl;
			}
		}
		
		flag = true;
		for(int i = 1; i <= n; i++){
			if(uf.same(i, n+i)) flag = false;
		}
		if(!flag){
			cout << -1 << endl;
			continue;
		}
		
		vector<llint> ans;
		for(int i = 1; i <= n; i++) used[i] = false;
		for(int i = 1; i <= n; i++){
			if(a[0][i] == a[1][i]) continue;
			if(used[i]) continue;
			pvec.clear(), nvec.clear();
			dfs(i);
			//cout << i << " " << pvec.size() << " " << nvec.size() << endl;
			if(pvec.size() > nvec.size()) swap(pvec, nvec);
			for(int i = 0; i < pvec.size(); i++){
				if(pvec[i] > n) pvec[i] -= n;
			}
			ans.insert(ans.end(), pvec.begin(), pvec.end());
		}
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}