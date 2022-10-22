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
	ll to, id;
	edge(){}
	edge(ll a, ll b){ to = a, id = b;}
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

ll n, m, s, t;
ll u[30005], v[30005], w[30005];
set<P> G[1005];
ll dist[1005], vpre[1005], epre[1005];


void bfs()
{
	queue<int> Q;
	Q.push(s);
	
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[s] = 0;
	
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(auto e : G[v]){
			ll u = e.first, id = e.second;
			if(dist[u] < inf/2) continue;
			Q.push(u);
			dist[u] = dist[v] + 1;
			vpre[u] = v, epre[u] = id;
		}
	}
}

set<ll> S;
int pre[100005], low[100005];

int id;
int bridge_dfs(int v, int eid)
{
	pre[v] = id++;
	int ret = pre[v];
	for(auto e : G[v]){
		ll u = e.first, id = e.second;
		if(id == eid) continue;
		if(pre[u]) ret = min(ret, pre[u]);
		else ret = min(ret, bridge_dfs(u, id));
	}
	return low[v] = ret;
}

//find the unordered pairs{start, end} of all bridges.
void findBridge(int v = 1)
{
	id = 1, S.clear();
	rep(i, 1, n) pre[i] = low[i] = 0;
	bridge_dfs(v, 0);
	for(int i = 1; i <= n; i++){
		for(auto e : G[i]){
			ll u = e.first;
			if(pre[i] < pre[u] && low[u] > pre[i]) S.insert(e.second);
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s >> t;
	rep(i, 1, m) cin >> u[i] >> v[i] >> w[i];
	
	rep(i, 1, m){
		G[u[i]].insert(P(v[i], i));
		G[v[i]].insert(P(u[i], i));
	}
	bfs();
	if(dist[t] > inf/2){
		outl(0);
		outl(0);
		return 0;
	}
	
	vector<ll> vec;
	ll p = t;
	while(p != s){
		vec.push_back(epre[p]);
		p = vpre[p];
	}
	
	ll ans = inf; vector<ll> avec;
	for(auto i : vec){
		
		G[u[i]].erase(P(v[i], i));
		G[v[i]].erase(P(u[i], i));
		bfs();
		
		if(dist[t] > inf/2){
			if(ans > w[i]){
				ans = w[i];
				avec.clear();
				avec.push_back(i);
			}
		}
		else{
			findBridge(s);
			ll v = t;
			while(v != s){
				ll eid = epre[v];
				if(S.count(eid)){
					if(ans > w[i] + w[eid]){
						ans = w[i] + w[eid];
						avec.clear();
						avec.push_back(i);
						avec.push_back(eid);
					}
				}
				v = vpre[v];
			}
		}
		
		G[u[i]].insert(P(v[i], i));
		G[v[i]].insert(P(u[i], i));
	}
	if(ans > inf/2){
		outl(-1);
		return 0;
	}
	
	outl(ans);
	outl(sz(avec));
	outl(avec);
	
	return 0;
}