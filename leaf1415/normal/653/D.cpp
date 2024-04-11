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

vector<int> prime;
void make_prime(int n){
	prime.resize(n+1);
	rep(i, 2, n){
		if(prime[i]) continue;
		for(int j = i; j <= n; j+=i) prime[j] = i;
	}
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



struct Dinic{
	typedef llint CAP;
	struct edge{
		llint to, rev;
		CAP cap;
		edge(llint a, CAP b, llint c){
			to = a, cap = b, rev = c;
		}
	};
	
	int n;
	vector<vector<edge> > G;
	vector<llint> level, iter;
	Dinic(){}
	Dinic(int n){
		this->n = n;
		G.resize(n+1);
		level.resize(n+1);
		iter.resize(n+1);
	}
	void init(){
		for(int i = 0; i <= n; i++) G[i].clear();
	}
	void add_edge(int s, int t, CAP cap)
	{
		G[s].push_back(edge(t, cap, G[t].size()));
		G[t].push_back(edge(s, 0, G[s].size()-1));
	}
	void bfs(int s)
	{
		for(int i = 0; i <= n; i++) level[i] = inf;
		level[s] = 0;
		
		queue<int> Q;
		Q.push(s);
		while(Q.size()){
			int v = Q.front();
			Q.pop();
			for(int i = 0; i < G[v].size(); i++){
				int u = G[v][i].to;
				if(G[v][i].cap <= 0 || level[u] < inf) continue;
				level[u] = level[v] + 1;
				Q.push(u);
			}
		}
	}
	CAP dfs(int v, CAP f, int t)
	{
		if(v == t) return f;
		
		CAP ret;
		for(llint &i = iter[v]; i < G[v].size(); i++){
			if(level[v] >= level[G[v][i].to] || G[v][i].cap <= 0) continue;
			ret = dfs(G[v][i].to, min(f, G[v][i].cap), t);
			if(ret > 0){
				G[v][i].cap -= ret;
				G[G[v][i].to][G[v][i].rev].cap += ret;
				return ret;
			}
		}
		return 0;
	}
	CAP calc(int s, int t)
	{
		CAP ret = 0, flow;
		while(1){
			bfs(s);
			if(level[t] >= inf) break;
			for(int i = 0; i <= n; i++) iter[i] = 0;
			while(1){
				flow = dfs(s, inf, t);
				if(flow <= 0) break;
				ret += flow;
			}
		}
		return ret;
	}
};

ll n, m, x;
ll u[505], v[505], w[505];

bool check(double d)
{
	Dinic dc(55);
	rep(i, 1, m) dc.add_edge(u[i], v[i], floor(w[i]/d));
	return dc.calc(1, n) >= x;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> x;
	rep(i, 1, m) cin >> u[i] >> v[i] >> w[i];
	
	double ub = 1e9, lb = 0, mid;
	rep(i, 1, 100){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	outf(lb*x);
	
	return 0;
}