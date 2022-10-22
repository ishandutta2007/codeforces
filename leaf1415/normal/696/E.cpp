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
#define per(x, s, t) for(llint (x) = (s); (x) >= (t); (x)--)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
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
void outa(T a[], ll s, ll t){
	for(ll i = s; i <= t; i++){ cout << a[i]; if(i < t) cout << " ";}
	cout << endl;
}
void dump_func() {cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
	cout << head;
	if(sizeof...(Tail) > 0) cout << " ";
	dump_func(std::move(tail)...);
}

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


typedef pair<P, P> T;
struct LazySegTree{
	typedef T SEG;
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
		return T(P(inf, inf), P(inf, inf));
	}
	SEG ope(SEG a, SEG b){ //operator
		return min(a, b);
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
			seg[k].first.first += delay[k];  //
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

ll n, m, Q;
vector<int> G[100005];
vector<T> vec[100005];
HLD hld;
LazySegTree seg(17);

ll get(ll s, ll t)
{
	vector<P> dest;
	hld.getPath(s, t, dest);
	
	T ret = T(P(inf, inf), P(inf, inf));
	for(auto p : dest){
		chmin(ret, seg.query(p.first, p.second));
	}
	if(ret.second.second > inf/2) return inf;
	
	//outl(ret);
	ll w = ret.first.first, v = ret.first.second, id = ret.second.first, p = ret.second.second;
	if(sz(vec[v]) == 0) seg.update(p, T(P(inf, inf), P(inf, inf)));
	else{
		ll dif = w - id;
		vec[v].back().first.first += dif;
		//outl(dif, vec[v].back());
		seg.update(p, vec[v].back()), vec[v].pop_back();
	}
	return id;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	hld.init(G, n);
	
	ll c;
	rep(i, 1, m){
		cin >> c;
		ll p = hld.pre_order[c];
		vec[c].push_back(T(P(i, c), P(i, p)));
	}
	
	seg.init();
	rep(i, 1, n){
		sort(all(vec[i])), reverse(all(vec[i]));
		if(sz(vec[i])){
			ll p = hld.pre_order[i];
			seg.update(p, vec[i].back());
			vec[i].pop_back();
		}
	}
	
	ll t, k;
	rep(q, 1, Q){
		cin >> t;
		if(t == 1){
			cin >> u >> v >> k;
			vector<ll> ans;
			rep(i, 1, k){
				ll id = get(u, v);
				if(id > inf/2) break;
				ans.push_back(id);
			}
			cout << sz(ans) << " ";
			for(auto x : ans) cout << x << " ";
			cout << "\n";
		}
		if(t == 2){
			cin >> v >> k;
			ll l = hld.pre_order[v], r = hld.back_order[v];
			seg.add(l, r, k);
		}
	}
	
	return 0;
}