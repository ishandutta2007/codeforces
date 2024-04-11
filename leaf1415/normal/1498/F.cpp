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
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}


template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i < vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, deque<T>& deq) {
	for(int i = 0; i < deq.size(); i++) {
		os << deq[i] << (i + 1 == deq.size() ? "" : " ");
	}
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
		itr++;
		if(itr != map_var.end()) os << ",";
		itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr;
		++itr;
		if(itr != set_var.end()) os << " ";
		itr--;
	}
	return os;
}
template<typename T>
void outa(T a[], ll s, ll t)
{
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

typedef pair<ll, P> T;

ll n, k;
vector<ll> G[100005];
ll a[100005];
int parent[100005];
llint dp[100005][45], dp2[100005][45];

const llint e = 0; //
llint ope(llint a, llint b)
{
	return max(a, b); //
}

llint* get(int u, int v)
{
	if(parent[u] == v) return dp2[u];
	else return dp[v];
}

void dfs(int v, int p)
{
	parent[v] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
	}
	
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		if(u == p) continue;
		rep(j, 0, 2*k-1) dp[v][(j+1)%(2*k)] ^= get(v, u)[j];
	}
	dp[v][0] ^= a[v];
}

void dfs2(int v, int p)
{
	llint m = G[v].size();
	ll sum[45] = {};
	
	for(int i = 0; i < m; i++){
		int u = G[v][i];
		rep(j, 0, 2*k-1) sum[(j+1)%(2*k)] ^= get(v, u)[j];
	}
	
	for(int i = 0; i < m; i++){
		int u = G[v][i];
		if(u == p) continue;
		rep(j, 0, 2*k-1) dp2[u][j] = sum[j];
		rep(j, 0, 2*k-1) dp2[u][(j+1)%(2*k)] ^= get(v, u)[j];
		dp2[u][0] ^= a[v];
	}
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs2(G[v][i], v);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep(i, 1, n) cin >> a[i];
	
	dfs(1, 0), dfs2(1, 0);
	
	/*rep(i, 1, n) for(auto u : G[i]){
		cout << i << " " << u << " "; outa(get(i, u), 0, 2*k-1);
	}*/
	
	rep(i, 1, n){
		ll sum[45] = {};
		for(auto u : G[i]){
			rep(j, 0, 2*k-1) sum[(j+1)%(2*k)] ^= get(i, u)[j];
		}
		ll ans = 0;
		rep(j, k, 2*k-1) ans ^= sum[j];
		if(ans) cout << 1 << " ";
		else cout << 0 << " ";
	}
	cout << endl;
	
	return 0;
}