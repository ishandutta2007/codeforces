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
#define rep(x, s, t) for(ll x = (s); (x) <= (t); (x)++)
#define per(x, s, t) for(ll x = (s); (x) >= (t); (x)--)
#define reps(x, s) for(ll x = 0; (x) < (ll)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define outf(x) cout << fixed << setprecision(16) << (x) << endl
#define inf 1e18
const double PI = 3.1415926535897932384626433;

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){ to = a, cost = b;}
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

const int mod = 1000000007;
//const int mod = 998244353;

struct mint{
	int x;
	mint(ll y = 0){if(y < 0 || y >= mod) y = (y%mod+mod)%mod; x = y;}
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
		ll tmp = x;
		tmp *= ope.x, tmp %= mod;
		x = tmp;
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
mint comb(int n, int k){ if(n < 0 || k < 0 || n < k) return mint(0); return fact[n] * fact_inv[k] * fact_inv[n-k];}
mint perm(int n, int k){ return comb(n, k) * fact[k]; }

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
void outa(T a[], ll s, ll t){rep(i, s, t){ cout << a[i]; if(i < t) cout << " ";}cout << endl;}
void dump_func(){cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
	cout << head;
	if(sizeof...(Tail) > 0) cout << " ";
	dump_func(std::move(tail)...);
}

struct LCA{
	int n, logn;
	vector<vector<int> > prev;
	vector<int> depth;
	
	LCA(){}
	void predfs(vector<ll> G[], int v, int p, int d)
	{
		depth[v] = d, prev[v][0] = p;
		for(auto u : G[v]){
			if(u == p) continue;
			predfs(G, u, v, d+1);
		}
	}
	void init(vector<ll> G[], int n, int root = 1)  //1-index
	{
		this->n = n;
		for(int i = 0; ; i++){
			if(n <= (1<<i)){
				logn = i;
				break;
			}
		}
		prev.resize(n+1);
		for(int i = 0; i < prev.size(); i++) prev[i].resize(logn);
		depth.resize(n+1);
		
		prev[0][0] = 0;
		predfs(G, root, 0, 0);
		for(int i = 1; i < logn; i++){
			for(int j = 0; j <= n; j++){
				prev[j][i] = prev[prev[j][i-1]][i-1];
			}
		}
	}
	int getLCA(int u, int v){
		int x = u, y = v;
		if(depth[y] > depth[x]) swap(x, y);
		
		for(int i = logn-1; i >= 0; i--){
			if(depth[x] - (1<<i) >= depth[y]) x = prev[x][i];
		}
		if(x == y) return x;
		for(int i = logn-1; i >= 0; i--){
			if(prev[x][i] != prev[y][i]){
				x = prev[x][i];
				y = prev[y][i];
			}
		}
		x = prev[x][0];
		return x;
	}
	int getAncestor(int v, int x){
		for(int i = logn-1; i >= 0; i--) if(x & (1<<i)) v = prev[v][i];
		return v;
	}
};


struct Rerooting{
	typedef P T;
	struct edge{
		int to;
		edge(){}
		edge(int a){to = a;}
	};
	
	int n;
	vector<vector<edge> > G;
	vector<int> parent;
	vector<T> dp, dp2, ans;
	vector<T> lsum, rsum;
	
	Rerooting(){};
	Rerooting(int n){
		this->n = n;
		init();
	}
	void init(){
		G.clear(), G.resize(n+1);
		parent.resize(n+1);
		dp.resize(n+1), dp2.resize(n+1);
		lsum.resize(n+1), rsum.resize(n+1);
		ans.resize(n+1);
	}
	void add_edge(int u, int v){
		G[u].push_back(edge(v));
		G[v].push_back(edge(u));
	}
	
	T Ident(){ //
		return P(0, 0);
	}
	T ope(T &a, T &b){ //
		return a+b;
	}
	T ope2(int v, T sum){ //
		return P(sum.first+sum.second, sum.second+1);
	}
	
	T& get(int u, int v){
		if(parent[u] == v) return dp2[u];
		else return dp[v];
	}
	
	void dfs(int v, int p)
	{
		parent[v] = p;
		for(auto e : G[v]) if(e.to != p) dfs(e.to, v);
		
		T sum = Ident();
		for(auto e : G[v]) if(e.to != p) sum = ope(sum, get(v, e.to));
		dp[v] = ope2(v, sum);
	}
	void dfs2(int v, int p)
	{
		ll m = sz(G[v]); T sum;
		
		sum = lsum[0] = Ident();
		rep(i, 0, m-1){
			sum = ope(sum, get(v, G[v][i].to));
			lsum[i+1] = sum;
		}
		sum = rsum[m+1] = Ident();
		per(i, m-1, 0){
			sum = ope(sum, get(v, G[v][i].to));
			rsum[i+1] = sum;
		}
		
		reps(i, G[v]){
			int u = G[v][i].to;
			if(u == p) continue;
			T sum = ope(lsum[i], rsum[i+2]);
			dp2[u] = ope2(v, sum);
		}
		
		for(auto e : G[v]) if(e.to != p) dfs2(e.to, v);
	}
	
	void calc(){
		dfs(1, -1), dfs2(1, -1);
		rep(i, 1, n){
			T sum = Ident();
			for(auto e : G[i]) sum = ope(sum, get(i, e.to));
			ans[i] = ope2(i, sum);
		}
	}
	void print(){
		rep(i, 1, n) for(auto e : G[i]) outl(i, "->", e.to, ":", get(i, e.to));
	}
};

ll n, m;
ll a[100005], b[100005];
vector<ll> G[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	Rerooting rt(n);
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		rt.add_edge(u, v);
	}
	rep(i, 1, m) cin >> a[i] >> b[i];
	rt.calc();
	
	LCA lca;
	lca.init(G, n);
	
	rep(i, 1, m){
		u = a[i], v = b[i];
		ll l = lca.getLCA(u, v), d = lca.depth[u] + lca.depth[v] - 2*lca.depth[l];
		
		ll U, V;
		if(abs(lca.depth[u] - lca.depth[v]) != d) U = lca.prev[u][0], V = lca.prev[v][0];
		else{
			if(lca.depth[u] > lca.depth[v]) swap(u, v);
			U = lca.getAncestor(v, lca.depth[v]-lca.depth[u]-1), V = lca.prev[v][0];
		}
		P p = rt.get(U, u), q = rt.get(V, v);
		double ans = (double)p.first/p.second + (double)q.first/q.second + d + 1;
		outf(ans);
	}
	
	return 0;
}