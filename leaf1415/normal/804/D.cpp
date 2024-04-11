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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct UnionFind{
	int size;
	vector<int> parent;
	vector<int> rank;
	vector<llint> v, e;
	
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

llint dtmp[100005];
void distdfs(vector<llint> G[], int v, int p, llint d)
{
	dtmp[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i], c = 1; //
		if(u == p) continue;
		distdfs(G, u, v, d+c);
	}
}

llint getDiameter(vector<ll> G[], vector<ll> &cvec, llint &u, llint &v)
{
	distdfs(G, cvec[0], -1, 0);
	llint max_val = -1, max_v;
	for(auto x : cvec){
		if(max_val < dtmp[x]){
			max_val = dtmp[x];
			max_v = x;
		}
	}
	u = max_v;
	
	distdfs(G, u, -1, 0);
	max_val = -1;
	for(auto x : cvec){
		if(max_val < dtmp[x]){
			max_val = dtmp[x];
			max_v = x;
		}
	}
	v = max_v;
	
	return max_val;
}

llint getTreeDepth(vector<llint> G[], vector<ll> &cvec, llint depth[])
{
	llint u, v;
	llint d = getDiameter(G, cvec, u, v);
	
	distdfs(G, u, -1, 0);
	for(auto v : cvec) depth[v] = dtmp[v];
	distdfs(G, v, -1, 0);
	for(auto v : cvec) depth[v] = max(depth[v], dtmp[v]);
	
	return d;
}


int n, m, Q;
vector<ll> G[100005];
vector<ll> cvec[100005], dvec[100005], svec[100005];
UnionFind uf(100005);
ll diam[100005], depth[100005];
map<P, double> mp;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	scanf("%d %d %d", &n, &m, &Q);
	int u, v;
	rep(i, 1, m){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		uf.unite(u, v);
	}
	
	rep(i, 1, n) cvec[uf.root(i)].push_back(i);
	rep(i, 1, n){
		if(cvec[i].size() == 0) continue;
		diam[i] = getTreeDepth(G, cvec[i], depth);
		
		for(auto v : cvec[i]) dvec[i].push_back(depth[v]);
		sort(all(dvec[i]));
		
		ll sum = 0;
		for(int j = (int)dvec[i].size()-1; j >= 0; j--){
			sum += dvec[i][j];
			svec[i].push_back(sum);
		}
		reverse(all(svec[i]));
	}
	
	//rep(i, 1, n) cout << diam[i] << " " << depth[i] << endl;
	
	while(Q--){
		cin >> u >> v;
		if(uf.same(u, v)){
			cout << -1 << "\n";
			continue;
		}
		
		u = uf.root(u), v = uf.root(v);
		if(u > v) swap(u, v);
		if(mp.count(P(u, v))){
			printf("%.11f\n", mp[P(u, v)]);
			continue;
		}
		
		ll d = max(diam[u], diam[v]);
		if(dvec[u].size() > dvec[v].size()) swap(u, v);
		
		ll pos = dvec[v].size(), sum = 0, ans = 0;
		reps(i, dvec[u]){
			ll x = dvec[u][i];
			while(pos > 0 && dvec[v][pos-1] >= d - x - 1) pos--, sum += dvec[v][pos]+1;
			
			if(pos == 0){
				ans += svec[u][i] * (ll)dvec[v].size();
				ans += sum * ((ll)dvec[u].size() - i);
				break;
			}
			
			ans += pos * d;
			ans += ((ll)dvec[v].size()-pos) * x + sum;
		}
		
		double ret = (double)ans / (double)(uf.v[u]*uf.v[v]);
		printf("%.11f\n", ret);
		
		if(u > v) swap(u, v);
		mp[P(u, v)] = ret;
	}
	flush(cout);
	
	return 0;
}