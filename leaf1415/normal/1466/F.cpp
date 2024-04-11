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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

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


llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

ll n, m;
vector<E> evec;
vector<P> pvec;
bool used[500005];
UnionFind uf(500005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll k, u, v;
	rep(i, 1, n){
		cin >> k;
		if(k == 1){
			cin >> v;
			evec.push_back(E(i, P(0, v)));
		}
		else{
			cin >> u >> v;
			evec.push_back(E(i, P(u, v)));
		}
	}
	
	vector<ll> avec; ll ans = 1;
	for(auto e : evec){
		ll id = e.first, u = e.second.first, v = e.second.second;
		if(uf.same(u, v)) continue;
		avec.push_back(id);
		uf.unite(u, v);
		ans *= 2, ans %= mod;
	}
	/*cout<< ans << endl;
	
	for(auto p : pvec)
	{
		ll id = p.first, v = p.second;
		if(used[uf.root(v)]) continue;
		used[uf.root(v)] = true;
		ans *= 2, ans %= mod;
		avec.push_back(id);
	}
	sort(all(avec));*/
	
	cout << ans << " " << avec.size() << endl;
	for(auto x : avec) cout << x << " "; cout << endl;
	
	return 0;
}