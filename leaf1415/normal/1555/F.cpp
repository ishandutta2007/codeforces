#include <iostream>
#include <iomanip>
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
#include <unordered_set>
#include <unordered_map>
#define rep(x, s, t) for(llint x = (s); (x) <= (t); (x)++)
#define per(x, s, t) for(llint x = (s); (x) >= (t); (x)--)
#define reps(x, s) for(llint x = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define outf(x) cout << fixed << setprecision(16) << (x) << endl
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){ to = a, cost = b;}
};
const ll dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

const ll mod = 1000000007;
//const ll mod = 998244353;

struct mint{
	ll x = 0;
	mint(ll y = 0){x = y; if(x < 0 || x >= mod) x = (x%mod+mod)%mod;}
	mint(const mint &ope) {x = ope.x;}
	
	mint operator-(){return mint(-x);}
	mint operator+(const mint &ope){return mint(x) += ope;}
	mint operator-(const mint &ope){return mint(x) -= ope;}
	mint operator*(const mint &ope){return mint(x) *= ope;}
	mint operator/(const mint &ope){return mint(x) /= ope;}
	mint& operator+=(const mint &ope){
		x += ope.x;
		if(x >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint &ope){
		x += mod - ope.x;
		if(x >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint &ope){
		x *= ope.x, x %= mod;
		return *this;
	}
	mint& operator/=(const mint &ope){
		ll n = mod-2; mint mul = ope;
		while(n){
			if(n & 1) *this *= mul;
			mul *= mul;
			n >>= 1;
		}
		return *this;
	}
	mint inverse(){return mint(1) / *this;}
	bool operator ==(const mint &ope){return x == ope.x;}
	bool operator !=(const mint &ope){return x != ope.x;}
	bool operator <(const mint &ope){return x < ope.x;}
};
mint modpow(mint a, ll n){
	if(n == 0) return mint(1);
	if(n % 2) return a * modpow(a, n-1);
	else return modpow(a*a, n/2);
}
istream& operator >>(istream &is, mint &ope){
	ll t; is >> t, ope.x = t;
	return is;
}
ostream& operator <<(ostream &os, mint &ope){return os << ope.x;}
ostream& operator <<(ostream &os, const mint &ope){return os << ope.x;}

vector<mint> fact, fact_inv;
void make_fact(int n){
	fact.resize(n+1), fact_inv.resize(n+1);
	fact[0] = mint(1); rep(i, 1, n) fact[i] = fact[i-1] * mint(i);
	fact_inv[n] = fact[n].inverse(); per(i, n-1, 0) fact_inv[i] = fact_inv[i+1] * mint(i+1);
}
mint comb(ll n, ll k){ if(n < 0 || k < 0 || n < k) return mint(0); return fact[n] * fact_inv[k] * fact_inv[n-k];}
mint perm(ll n, ll k){ return comb(n, k) * fact[k]; }

vector<int> prime, pvec;
void make_prime(int n){
	prime.resize(n+1);
	rep(i, 2, n){
		if(prime[i]) continue;
		for(int j = i; j <= n; j+=i) prime[j] = i;
	}
	rep(i, 2, n) if(prime[i] == i) pvec.push_back(i);
}

bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }
ll sgn(ll x){ if(x > 0) return 1; if(x < 0) return -1; return 0;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string lltos(ll x){string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(ret.begin(), ret.end()); return ret;}
ll stoll(string &s){ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
template<typename T>
void uniq(T &vec){ sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

template<class S, class T> pair<S, T>& operator+=(pair<S,T> &s, const pair<S,T> &t){
	s.first += t.first, s.second += t.second;
	return s;
}
template<class S, class T> pair<S, T>& operator-=(pair<S,T> &s, const pair<S,T> &t){
	s.first -= t.first, s.second -= t.second;
	return s;
}
template<class S, class T> pair<S, T> operator+(const pair<S,T> &s, const pair<S,T> &t){
	return pair<S,T>(s.first+t.first, s.second+t.second);
}
template<class S, class T> pair<S, T> operator-(const pair<S,T> &s, const pair<S,T> &t){
	return pair<S,T>(s.first-t.first, s.second-t.second);
}
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
template<typename T>
ostream& operator << (ostream& os, deque<T>& deq) {
	for(int i = 0; i < deq.size(); i++) os << deq[i] << (i + 1 == deq.size() ? "" : " ");
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	for(typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
		os << "(" << itr->first << ", " << itr->second << ")";
		itr++; if(itr != map_var.end()) os << ","; itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr; ++itr; if(itr != set_var.end()) os << " "; itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, multiset<T>& set_var) {
	for(typename multiset<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr; ++itr; if(itr != set_var.end()) os << " "; itr--;
	}
	return os;
}
template<typename T>
void outa(T a[], ll s, ll t){for(ll i = s; i <= t; i++){ cout << a[i]; if(i < t) cout << " ";}cout << endl;}
void dump_func(){cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
	cout << head;
	if(sizeof...(Tail) > 0) cout << " ";
	dump_func(std::move(tail)...);
}

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

struct HLD{
	int V, logV;
	vector<P> mp;
	map<P, int> mp2;
	vector<P> parent;
	
	//subtree of v is [pre_order[v], back_order[v]]
	vector<int> pre_order;
	vector<int> back_order;
	
	int order;
	int global_id, local_id;
	vector<int> size, depth;
	vector<vector<int> > prev;
	
	HLD(){}
	
	void predfs(vector<int> G[], int v, int p, int d)
	{
		size[v] = 1, depth[v] = d, prev[v][0] = p;
		for(int i = 0; i < G[v].size(); i++){
			if(G[v][i] == p) continue;
			predfs(G, G[v][i], v, d+1);
			size[v] += size[G[v][i]];
		}
	}
	void maindfs(vector<int> G[], int v, int p)
	{
		mp[v] = make_pair(global_id, local_id);
		mp2[make_pair(global_id, local_id)] = v;
		pre_order[v] = ++order;
		
		if(G[v].size() == 1 && G[v][0] == p){
			back_order[v] = order;
			return;
		}
		
		vector<P> vec;
		for(int i = 0; i < G[v].size(); i++){
			if(G[v][i] == p) continue;
			vec.push_back(make_pair(size[G[v][i]], G[v][i]));
		}
		sort(vec.rbegin(), vec.rend());
		
		local_id++;
		if(vec.size() >= 1) maindfs(G, vec[0].second, v);
			
		for(int i = 1; i < vec.size(); i++){
			parent.push_back(mp[v]);
			global_id++, local_id = 0;
			maindfs(G, vec[i].second, v);
		}
		back_order[v] = order;
	}
	int getLCA(int u, int v){
		int x = u, y = v;
		if(depth[y] > depth[x]) swap(x, y);
		
		for(int i = logV-1; i >= 0; i--){
			if(depth[x] - (1<<i) >= depth[y]) x = prev[x][i];
		}
		if(x == y) return x;
		for(int i = logV-1; i >= 0; i--){
			if(prev[x][i] != prev[y][i]){
				x = prev[x][i];
				y = prev[y][i];
			}
		}
		x = prev[x][0];
		return x;
	}
	void pathcalc(int v, int lca, vector<pair<int, P> > &dest)
	{
		int gid = mp[v].first, lid = mp[v].second;
		int Gid = mp[lca].first, Lid = mp[lca].second;
		
		while(Gid != gid){
			dest.push_back(make_pair(gid, make_pair(0, lid)));
			int ngid = parent[gid].first, nlid = parent[gid].second;
			gid = ngid, lid = nlid;
		}
		dest.push_back(make_pair(gid, make_pair(Lid, lid)));
	}
	
	void init(vector<int> G[], int V) // The tree must be undirected and 1-indexed.
	{
		this->V = V, logV = 0;
		for(int t = V; t; t/=2) logV++;
		prev.resize(V+1);
		for(int i = 0; i <= V; i++) prev[i].resize(logV);
		
		size.resize(V+1), depth.resize(V+1);
		predfs(G, 1, 0, 0);
		
		prev[0][0] = 0;
		for(int i = 1; i < logV; i++){
			for(int j = 1; j <= V; j++){
				prev[j][i] = prev[prev[j][i-1]][i-1];
			}
		}
		
		mp.resize(V+1), mp2.clear();
		parent.clear(), parent.push_back(make_pair(-1, -1));
		pre_order.resize(V+1), back_order.resize(V+1);
		global_id = local_id = 0, order = 0;
		
		maindfs(G, 1, 0);
	}
	
	void path(int u, int v, vector<pair<int, P> > &dest)
	{
		dest.clear();
		int lca = getLCA(u, v);
		pathcalc(u, lca, dest);
		pathcalc(v, lca, dest);
		
		pair<int, P> p = make_pair(mp[lca].first, make_pair(mp[lca].second, mp[lca].second));
		for(int i = 0; i < dest.size(); i++){
			if(dest[i] == p){
				dest.erase(dest.begin()+i);
				return ;
			}
		}
	}
	
	void getPath(int u, int v, vector<P> &dest) //transform an u-v path into intervals[l, r] on segtree.
	{
		vector<pair<int, P> > src;
		path(u, v, src);
		
		dest.clear();
		for(int i = 0; i < src.size(); i++){
			int u = mp2[make_pair(src[i].first, src[i].second.first)], v = mp2[make_pair(src[i].first, src[i].second.second)];
			dest.push_back(make_pair(pre_order[u], pre_order[v]));
		}
	}
};


struct LazySegTree{
	typedef ll SEG;
	typedef ll DELAY;
	
	int size;
	vector<SEG> seg;
	vector<DELAY> delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	SEG Ident(){ //identity element
		return 0;
	}
	SEG ope(SEG a, SEG b){ //operator
		return a+b;
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = Ident();
			delay[i] = 0; //
		}
	}
	
	void eval(int l, int r, int k) //
	{
		if(delay[k]){
			seg[k] += delay[k] * (r-l+1);  //
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, SEG val)
	{
		int l = 0, r = (1<<size)-1, k = 1;
		
		eval(l, r, k);
		for(int j = size-1; j >= 0; j--){
			k <<= 1;
			if(i & (1<<j)){
				k++;
				l = (l+r)/2+1;
			}
			else r = (l+r)/2;
			eval(l, r, k);
		}
		
		seg[i+(1<<size)] = val;
		
		l = i, r = i, k = i+(1<<size);
		for(int j = 0; j < size; j++){
			k /= 2, l &= ~(1<<j), r |= 1<<j;
			eval(l, (l+r)/2, k*2), eval((l+r)/2+1, r, k*2+1);
			seg[k] = ope(seg[k*2], seg[k*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, DELAY val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] += val; //
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = ope(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, DELAY val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	SEG query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		SEG lval = query(a, b, k*2, l, (l+r)/2);
		SEG rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	SEG query(int a, int b)
	{
		if(a > b) return Ident();
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n, Q;
ll u[500005], v[500005], w[500005];
vector<int> G[300005];
vector<edge> G2[300005];
ll sum[300005];
UnionFind uf(300005);
HLD hld;
ll ans[500005];
LazySegTree seg(19);

void dfs(int v, int p, ll x)
{
	sum[v] = x;
	for(auto e : G2[v]){
		ll u = e.to;
		if(u == p) continue;
		dfs(u, v, x^e.cost);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	
	vector<ll> vec;
	rep(i, 1, Q){
		cin >> u[i] >> v[i] >> w[i];
		if(!uf.same(u[i], v[i])){
			G[u[i]].push_back(v[i]);
			G[v[i]].push_back(u[i]);
			G2[u[i]].push_back(edge(v[i], w[i]));
			G2[v[i]].push_back(edge(u[i], w[i]));
			uf.unite(u[i], v[i]);
			ans[i] = 1;
		}
		else vec.push_back(i);
	}
	
	set<ll> S;
	rep(i, 1, n) S.insert(uf.root(i));
	for(auto x : S){
		G[n+1].push_back(x), G[x].push_back(n+1);
		G2[n+1].push_back(edge(x, 0)), G2[x].push_back(edge(n+1, 0));
	}
	n++;
	dfs(1, -1, 0);
	
	hld.init(G, n);
	seg.init();
	
	//outl(vec);
	
	for(auto e : vec){
		ll s = u[e], t = v[e];
		if((sum[s] ^ sum[t] ^ w[e]) == 0) continue;
		ll lca = hld.pre_order[hld.getLCA(s, t)];
		
		vector<P> res;
		hld.getPath(s, t, res);
		
		ll tmp = 0;
		for(auto p : res) tmp += seg.query(p.first, p.second);
		tmp -= seg.query(lca, lca);
		if(tmp) continue;
		
		ans[e] = 1;
		for(auto p : res) seg.add(p.first, p.second, 1);
		seg.add(lca, lca, -1);
	}
	
	rep(i, 1, Q){
		if(ans[i]) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
	return 0;
}