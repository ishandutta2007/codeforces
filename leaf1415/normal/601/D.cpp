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
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define outf(x) cout << fixed << setprecision(16) << (x) << endl
#define inf 2e18
#define eps 1e-9
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

int mod = 1000000007;
//int mod = 998244353;

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
ll floor(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return a/b; else return -((-a+b-1)/b); }
ll ceil(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return (a+b-1)/b; else return -((-a)/b); }
ll modulo(ll a, ll b){ b = abs(b); return a - floor(a, b) * b; }
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
	reps(i, vec) os << vec[i] << (i + 1 == vec.size() ? "" : " "); return os;
}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	reps(i, vec) os << vec[i] << (i + 1 == vec.size() ? "" : " "); return os;
}
template<typename T>
ostream& operator << (ostream& os, deque<T>& deq) {
	reps(i,  deq) os << deq[i] << (i + 1 == deq.size() ? "" : " "); return os;
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


ll modpow(ll a, ll n, ll mod)
{
	if(n == 0) return 1;
	if(n % 2) return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	else return modpow((a*a)%mod, n/2, mod) % mod;
}

//hmod[]

const llint L = 3;
ll hmod[] = {950009857, 943718401, 935329793, 924844033, 469762049, 167772161};
struct Hash{
	ll h[L];
	Hash(){ for(int i = 0; i < L; i++) h[i] = 0;}
	Hash(llint x){ for(int i = 0; i < L; i++) h[i] = x % hmod[i];}
	
	Hash operator+(const Hash &ope){Hash h = *this; return h += ope;}
	Hash operator-(const Hash &ope){Hash h = *this; return h -= ope;}
	Hash operator*(const Hash &ope){Hash h = *this; return h *= ope;}
	Hash& operator+=(const Hash &ope){
		for(int i = 0; i < L; i++){
			h[i] += ope.h[i];
			if(h[i] >= hmod[i]) h[i] -= hmod[i];
		}
		return *this;
	}
	Hash& operator-=(const Hash &ope){
		for(int i = 0; i < L; i++){
			h[i] += hmod[i] - ope.h[i];
			if(h[i] >= hmod[i]) h[i] -= hmod[i];
		}
		return *this;
	}
	Hash& operator*=(const Hash &ope){
		for(int i = 0; i < L; i++) h[i] *= ope.h[i], h[i] %= hmod[i];
		return *this;
	}
	bool operator<(const Hash &ope) const{
		for(int i = 0; i < L; i++) if(h[i] != ope.h[i]) return h[i] < ope.h[i];
		return false;
	}
	bool operator ==(const Hash &ope){
		for(int i = 0; i < L; i++) if(h[i] != ope.h[i]) return false;
		return true;
	}
	bool operator !=(const Hash &ope){return !(*this == ope);}
	
	Hash inverse(){
		Hash ret;
		for(int i = 0; i < L; i++) ret.h[i] = modpow(h[i], hmod[i]-2, hmod[i]);
		return ret;
	}
};
ostream& operator <<(ostream &os, Hash &ope){
	cout << "("; for(int i = 0; i < L; i++) os << ope.h[i] << (i + 1 == L ? "" : ", "); cout << ")";
	return os;
}
ostream& operator <<(ostream &os, const Hash &ope){
	cout << "("; for(int i = 0; i < L; i++) os << ope.h[i] << (i + 1 == L ? "" : ", "); cout << ")";
	return os;
}


ll n;
ll a[300005];
vector<ll> G[300005];
string s;
Hash A[300005], B[300005];
set<Hash> S[300005];
ll ans[300005];
Hash H;

P dfs(int v, int p)
{
	vector<P> vec;
	for(auto u : G[v]){
		if(u == p) continue;
		vec.push_back(dfs(u, v));
	}
	vec.push_back(P(1, v));
	sort(all(vec)), reverse(all(vec));
	
	ll nid = vec[0].second;
	Hash Ainv = A[nid].inverse();
	rep(i, 1, sz(vec)-1){
		ll id = vec[i].second;
		for(auto h : S[id]){
			h = A[id] * h + B[id];
			S[nid].insert(Ainv * (h - B[nid]));
		}
	}
	A[nid] *= H, B[nid] = B[nid] * H + Hash(s[v]);
	ans[v] = sz(S[nid]);
	return P(sz(S[nid]), nid);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cin >> s; s = "#" + s;
	
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	rep(i, 0, L-1) H.h[i] = 998244353;
	rep(i, 1, n) S[i].insert(Hash(0)), A[i] = Hash(1), B[i] = Hash(0);
	
	dfs(1, -1);
	
	ll mx = -inf, mx_cnt;
	rep(i, 1, n){
		if(mx < ans[i] + a[i]) mx = ans[i]+a[i], mx_cnt = 1;
		else if(mx == ans[i]+a[i]) mx_cnt++;
	}
	outl(mx), outl(mx_cnt);
	
	return 0;
}