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

struct UnionFind{
	int size;
	vector<int> parent;
	vector<int> v, e;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		v.resize(size+1);
		e.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i, v[i] = 1, e[i] = 0;
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
		if(root_i == root_j){
			e[root_i]++;
			return;
		}
		parent[root_i] = root_j;
		v[root_j] += v[root_i];
		e[root_j] += e[root_i] + 1;
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

ll n;
ll x[100005], y[100005];
vector<ll> compX, compY;
UnionFind uf(200005);

void make(ll x[], vector<ll> &comp)
{
	rep(i, 1, n) comp.push_back(x[i]);
	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	rep(i, 1, n) x[i] = lower_bound(all(comp), x[i]) - comp.begin() + 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> x[i] >> y[i];
	make(x, compX), make(y, compY);
	
	rep(i, 1, n) uf.unite(x[i], n+y[i]);
	
	ll ans = 1;
	rep(i, 1, 2*n){
		if(uf.parent[i] != i) continue;
		if(uf.v[i] <= uf.e[i]) ans *= modpow(2, uf.v[i]), ans %= mod;
		else ans *= modpow(2, uf.v[i]) + mod - 1, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}