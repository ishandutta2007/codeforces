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



//hmod[]

const llint L = 6; llint hmod[L] = {950009857, 943718401, 935329793, 924844033, 469762049, 167772161};
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
};
ostream& operator <<(ostream &os, Hash &ope){
	cout << "("; for(int i = 0; i < L; i++) os << ope.h[i] << (i + 1 == L ? "" : ", "); cout << ")";
	return os;
}
ostream& operator <<(ostream &os, const Hash &ope){
	cout << "("; for(int i = 0; i < L; i++) os << ope.h[i] << (i + 1 == L ? "" : ", "); cout << ")";
	return os;
}
llint getrand(){
	llint ret = rand();
	ret = ret * RAND_MAX + rand();
	return ret;
}

typedef pair<Hash, ll> H;

int n;
vector<int> G[200005];
int Size[200005], depth[200005];
Hash h[200005];

int sizedfs(int v, int pre)
{
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		ret += sizedfs(G[v][i], v);
	}
	return Size[v] = ret;
}

int centdfs(int v, int pre, int sz)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(Size[G[v][i]] > sz/2) return centdfs(G[v][i], v, sz);
	}
	return v;
}

void depdfs(int v, int p)
{
	depth[v] = 0;
	for(auto u : G[v]){
		if(u == p) continue;
		depdfs(u, v);
		chmax(depth[v], depth[u]+1);
	}
}

H calcdfs(int v, int p)
{
	Hash mul = Hash(1); set<H> S;
	for(auto u : G[v]){
		if(u == p) continue;
		H res = calcdfs(u, v);
		mul *= h[depth[v]]+res.first;
		S.insert(res);
	}
	
	ll sum = 0;
	for(auto x : S) sum += x.second;
	if(sz(G[v]) <= 3) sum++;
	
	return H(mul, sum);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	cin >> n;
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == 1){
		outl(1);
		return 0;
	}
	
	rep(i, 0, n) h[i] = Hash(getrand() % 900000000 + 100000000);
	
	sizedfs(v, -1);
	v = centdfs(v, -1, Size[v]);
	sizedfs(v, -1);
	
	ll w = 0;
	for(auto u : G[v]){
		if(Size[u]*2 == n){
			w = u;
			break;
		}
	}
	
	
	if(w == 0){
		depdfs(v, -1);
		outl(calcdfs(v, -1).second);
	}
	else{
		depdfs(v, w);
		H res = calcdfs(v, w);
		depdfs(w, v);
		H res2 = calcdfs(w, v);
		
		if(res.first == res2.first) outl(res.second);
		else outl(res.second+res2.second);
	}
	
	return 0;
}