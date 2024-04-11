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
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string tostr(ll x){string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(ret.begin(), ret.end()); return ret;}
ll toint(string &s){ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
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


ll n, m, s;
ll u[200005], v[200005], w[200005], c[200005];
vector<edge> G[200005];
UnionFind uf(200005);

const int VNUM = 200005, LOG_VNUM = 18;
int Prev[VNUM][LOG_VNUM];
P Max[VNUM][LOG_VNUM];
int depth[VNUM];

void predfs(int v, int p, int d, ll eid)
{
	depth[v] = d;
	Prev[v][0] = p, Max[v][0] = P(w[eid], eid);
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		predfs(G[v][i].to, v, d+1, G[v][i].cost);
	}
}

int getLCA(int u, int v){
	int x = u, y = v;
	if(depth[y] > depth[x]) swap(x, y);

	for(int i = LOG_VNUM-1; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = LOG_VNUM-1; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, m) cin >> c[i];
	rep(i, 1, m) cin >> u[i] >> v[i];
	cin >> s;

	w[0] = -inf;

	vector<P> vec;
	rep(i, 1, m) vec.push_back(P(w[i], i));
	sort(all(vec));

	ll sum = 0, cmin = inf; set<ll> S;
	for(auto p : vec){
		ll id = p.second;
		if(uf.same(u[id], v[id])) continue;
		G[u[id]].push_back(edge(v[id], id));
		G[v[id]].push_back(edge(u[id], id));
		S.insert(id);
		sum += w[id];
		chmin(cmin, c[id]);
		uf.unite(u[id], v[id]);
	}
	ll ans = sum - s/cmin, ans_i = 0, ans_j;

	predfs(1, 0, 0, 0);
	for(int i = 1; i < LOG_VNUM; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	rep(i, 0, LOG_VNUM-1) Max[0][i] = P(-inf, 0);
	for(int i = 1; i < LOG_VNUM; i++){
		for(int j = 1; j <= n; j++){
			Max[j][i] = max(Max[j][i-1], Max[Prev[j][i-1]][i-1]);
		}
	}

	rep(i, 1, m){
		if(S.count(i)) continue;
		ll lca = getLCA(u[i], v[i]);
		ll d = depth[u[i]] - depth[lca];
		P p = P(-inf, -inf);

		ll pos = u[i];
		rep(i, 0, 17) if(d & (1<<i)){
			chmax(p, Max[pos][i]), pos = Prev[pos][i];
		}
		d = depth[v[i]] - depth[lca], pos = v[i];
		rep(i, 0, 17) if(d & (1<<i)){
			chmax(p, Max[pos][i]), pos = Prev[pos][i];
		}

		ll tmp = sum - p.first + w[i];
		tmp -= s/c[i];

		if(ans > tmp) ans = tmp, ans_i = i, ans_j = p.second;
	}

	if(ans_i){
		S.insert(ans_i);
		S.erase(ans_j);
	}

	outl(ans);
	cmin = inf;

	for(auto x : S){
		if(cmin > c[x]) cmin = c[x], ans_i = x;
	}
	w[ans_i] -= s / c[ans_i];

	for(auto x : S) cout << x << " " << w[x] << "\n";

	return 0;
}