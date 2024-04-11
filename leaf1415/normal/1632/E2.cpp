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
#include <array>
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
#define pb push_back
#define fst first
#define snd second
#define inf 2e18
#define eps 1e-9
const double PI = 3.1415926535897932384626433;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
	mint& operator+=(const mint &ope){x += ope.x; if(x >= mod) x -= mod; return *this;}
	mint& operator-=(const mint &ope){x += mod - ope.x; if(x >= mod) x -= mod; return *this;}
	mint& operator*=(const mint &ope){ll tmp = x; tmp *= ope.x, tmp %= mod; x = tmp; return *this;}
	mint& operator/=(const mint &ope){
		ll n = mod-2; mint mul = ope;
		while(n){if(n & 1) *this *= mul; mul *= mul; n >>= 1;}
		return *this;
	}
	mint inverse(){return mint(1) / *this;}
	bool operator ==(const mint &ope){return x == ope.x;}
	bool operator !=(const mint &ope){return x != ope.x;}
	bool operator <(const mint &ope)const{return x < ope.x;}
};
mint modpow(mint a, ll n){
	if(n == 0) return mint(1);
	if(n % 2) return a * modpow(a, n-1);
	else return modpow(a*a, n/2);
}
istream& operator >>(istream &is, mint &ope){ll t; is >> t, ope.x = t; return is;}
ostream& operator <<(ostream &os, mint &ope){return os << ope.x;}
ostream& operator <<(ostream &os, const mint &ope){return os << ope.x;}

ll modpow(ll a, ll n, ll mod){
	if(n == 0) return 1;
	if(n % 2) return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	else return modpow((a*a)%mod, n/2, mod) % mod;
}

vector<mint> fact, fact_inv;
void make_fact(int n){
	fact.resize(n+1), fact_inv.resize(n+1);
	fact[0] = mint(1); rep(i, 1, n) fact[i] = fact[i-1] * mint(i);
	fact_inv[n] = fact[n].inverse(); per(i, n-1, 0) fact_inv[i] = fact_inv[i+1] * mint(i+1);
}
mint comb(int n, int k){ if(n < 0 || k < 0 || n < k) return mint(0); return fact[n] * fact_inv[k] * fact_inv[n-k];}
mint perm(int n, int k){ return comb(n, k) * fact[k]; }

vector<int> prime, pvec, qrime;
void make_prime(int n){
	prime.resize(n+1);
	rep(i, 2, n){
		if(prime[i] == 0) pvec.push_back(i), prime[i] = i;
		for(auto p : pvec){ if(i*p > n || p > prime[i]) break; prime[i*p] = p;}
	}
}
void make_qrime(int n){
	qrime.resize(n+1);
	rep(i, 2, n){int ni = i / prime[i]; if(prime[i] == prime[ni]) qrime[i] = qrime[ni] * prime[i]; else qrime[i] = prime[i];}
}

bool exceed(ll x, ll y, ll m){return y > 0 && x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }
ll floor(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return a/b; else return -((-a+b-1)/b); }
ll ceil(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return (a+b-1)/b; else return -((-a)/b); }
ll modulo(ll a, ll b){ b = abs(b); return a - floor(a, b) * b;}
ll sgn(ll x){ if(x > 0) return 1; if(x < 0) return -1; return 0;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
ll arith(ll x){return x*(x+1)/2;}
ll arith(ll l, ll r){return arith(r) - arith(l-1);}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string lltos(ll x){string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(all(ret)); return ret;}
ll stoll(string &s){ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
template<typename T> void uniq(T &vec){sort(all(vec)); vec.erase(unique(all(vec)), vec.end());}
int popcount(ull x){
	x -= ((x>>1)&0x5555555555555555ULL), x = (x & 0x3333333333333333ULL) + ((x>>2) & 0x3333333333333333ULL);
	return (((x + (x>>4)) & 0x0F0F0F0F0F0F0F0FULL) * 0x0101010101010101ULL) >> 56;
}

template<class S, class T> pair<S, T>& operator+=(pair<S, T> &s, const pair<S, T> &t){s.first += t.first, s.second += t.second; return s;}
template<class S, class T> pair<S, T>& operator-=(pair<S, T> &s, const pair<S, T> &t){s.first -= t.first, s.second -= t.second; return s;}
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t){return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t){return pair<S,T>(s.first-t.first, s.second-t.second);}
template<class T> T dot(const pair<T, T> &s, const pair<T, T> &t){return s.first*t.first + s.second*t.second;}
template<class T> T cross(const pair<T, T> &s, const pair<T, T> &t){return s.first*t.second - s.second*t.first;}

template<typename T> ostream& operator << (ostream& os, vector<T>& vec){reps(i, vec) os << vec[i] << " "; return os;}
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec){reps(i, vec) os << vec[i] << " "; return os;}
template<typename T> ostream& operator << (ostream& os, list<T>& ls){for(auto x : ls) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, const list<T>& ls){for(auto x : ls) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, deque<T>& deq){reps(i,  deq) os << deq[i] << " "; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& ope){ for(auto p : ope) os << "(" << p.first << ", " << p.second << "),";return os;}
template<typename T> ostream& operator << (ostream& os, set<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, multiset<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> void outa(T a[], ll s, ll t){rep(i, s, t){ cout << a[i]; if(i < t) cout << " ";} cout << endl;}
template<typename T, size_t N> ostream& operator << (ostream& os, array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
template<typename T, size_t N> ostream& operator << (ostream& os, const array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
void dump_func(){cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail){cout << head; if(sizeof...(Tail) > 0) cout << " "; dump_func(std::move(tail)...);}


struct LiChaoTree{
	int size;
	vector<P> seg;
	vector<ll> x;
	
	LiChaoTree(){}
	LiChaoTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		x.resize(1<<size);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = make_pair(0, inf);
		for(int i = 0; i < (1<<size); i++) x[i] = i;  //
	}
	ll calc(P f, ll x)
	{
		return f.first * x + f.second;
	}
	ll query(int i) //x[i]
	{
		ll X = x[i], ret = inf;
		i += (1 << size);
		while(i >= 1){
			ret = min(ret, calc(seg[i], X));
			i /= 2;
		}
		return ret;
	}
	void add(int k, int l, int r, P f)
	{
		int m = (l+r)/2;
		if(calc(f, x[m]) < calc(seg[k], x[m])) swap(seg[k], f);
		bool L = (calc(f, x[l]) < calc(seg[k], x[l])), R = (calc(f, x[r]) < calc(seg[k], x[r]));
		if(L == R) return;
		if(L) add(k*2, l, m, f);
		if(R) add(k*2+1, m+1, r, f);
	}
	void addSegment(int a, int b, int k, int l, int r, P f)
	{
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			add(k, l, r, f);
			return;
		}
		addSegment(a, b, k*2, l, (l+r)/2, f);
		addSegment(a, b, k*2+1, (l+r)/2+1, r, f);
	}
	void addSegment(int a, int b, ll p, ll q) //[x[a], x[b]]px+q
	{
		if(a > b) return;
		addSegment(a, b, 1, 0, (1<<size)-1, make_pair(p, q));
	}
	void addLine(ll p, ll q) //px+q
	{
		return addSegment(0, (1<<size)-1, p, q);
	}
};

ll T;
ll n;
vector<ll> G[300005];
ll depth[300005], height[300005];
ll dp[300005], dp2[300005];
vector<ll> dvec;

void dfs(int v, int p, int d)
{
	depth[v] = d, height[v] = 0;
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v, d+1);
		chmax(height[v], height[u]+1);
	}
}
bool dfs2(int v, int p, int b)
{
	bool ret = (v == b);
	vector<ll> vec;
	dp[v] = dp2[v] = 0;
	for(auto u : G[v]){
		if(u == p) continue;
		if(dfs2(u, v, b)) ret = true;
		else chmax(dp[v], height[u]+1);
		vec.pb(height[u]+1);
		chmax(dp2[v], dp2[u]);
	}
	sort(all(vec)), reverse(all(vec));
	if(sz(vec) >= 1) chmax(dp2[v], vec[0]);
	if(sz(vec) >= 2) chmax(dp2[v], vec[0]+vec[1]);
	
	if(ret) dvec.pb(v);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) G[i].clear();
		ll u, v;
		rep(i, 1, n-1){
			cin >> u >> v;
			G[u].pb(v);
			G[v].pb(u);
		}
		dfs(1, -1, 0);
		
		ll b = 1;
		rep(i, 1, n) if(depth[b] < depth[i]) b = i;
		
		dvec.clear();
		dfs2(1, -1, b);
		reverse(all(dvec));
		
		LiChaoTree lct(digitnum(n+5, 2));
		lct.init();
		lct.addSegment(1, n, 0, height[1]);
		
		ll d = 0;
		rep(i, 0, sz(dvec)-2){
			chmax(d, depth[dvec[i]] + dp[dvec[i]]);
			ll D = ceil(dp2[dvec[i+1]], 2), x = d - D;
			chmax(x, 0LL), chmin(x, n+1);
			lct.addSegment(1, x-1, 0, d);
			lct.addSegment(x, n, 1, D);
		}
		rep(i, 1, n) cout << lct.query(i) << " "; cout << endl;
	}
	
	return 0;
}