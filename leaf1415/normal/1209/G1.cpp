#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#define llint long long
#define inf 1e9

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

llint n, Q;
llint a[200005], cnt[200005];
llint l[200005], r[200005];
UnionFind uf(200005);
vector<pair<P, llint> > vec;
set<int> S;
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= 200000; i++){
		l[i] = inf, r[i] = -inf;
	}
	for(llint i = 1; i<= n; i++){
		l[a[i]] = min(l[a[i]], i);
		r[a[i]] = max(r[a[i]], i);
		cnt[a[i]]++;
	}
	for(int i = 1; i <= 200000; i++){
		if(cnt[i] == 0) continue;
		vec.push_back(make_pair(make_pair(l[i], 1), i));
		vec.push_back(make_pair(make_pair(r[i], 2), i));
	}
	sort(vec.begin(), vec.end());
	
	uf.init();
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first.second == 2){
			S.erase(vec[i].second);
		}
		else{
			if(S.size()) uf.unite(*S.begin(), vec[i].second);
			S.insert(vec[i].second);
		}
	}
	
	for(int i = 1; i <= n; i++){
		mp[uf.root(i)] = max(mp[uf.root(i)], cnt[i]);
	}
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++) ans += it->second;
	ans = n - ans;
	
	cout << ans << endl;
	
	return 0;
}