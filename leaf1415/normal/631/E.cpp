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

struct LiChaoTree{
	int size;
	vector<P> seg;
	vector<llint> x;
	
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
	llint calc(P f, llint x)
	{
		return f.first * x + f.second;
	}
	llint query(int i) //x[i]
	{
		llint X = x[i], ret = inf;
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
	void addSegment(int a, int b, llint p, llint q) //[x[a], x[b]]px+q
	{
		addSegment(a, b, 1, 0, (1<<size)-1, make_pair(p, q));
	}
	void addLine(llint p, llint q) //px+q
	{
		return addSegment(0, (1<<size)-1, p, q);
	}
};

ll n;
ll a[200005], sum[200005];
vector<ll> comp;
LiChaoTree lct(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) sum[i] = sum[i-1] + a[i];
	
	ll c = 0;
	rep(i, 1, n) c += a[i] * i;
	
	rep(i, 1, n) comp.push_back(a[i]);
	uniq(comp);
	
	ll ans = 0;
	
	lct.init();
	rep(i, 0, (1<<18)-1){
		if(i < sz(comp)) lct.x[i] = comp[i];
		else lct.x[i] = 1e9;
	}
	per(i, n, 1){
		chmin(ans, lct.query(lower_bound(all(comp), a[i])-comp.begin()) - (sum[i]-i*a[i]));
		lct.addLine(-i, sum[i]);
	}
	
	lct.init();
	rep(i, 0, (1<<18)-1){
		if(i < sz(comp)) lct.x[i] = comp[i];
		else lct.x[i] = 1e9;
	}
	rep(i, 1, n){
		chmin(ans, lct.query(lower_bound(all(comp), a[i])-comp.begin()) - (sum[i-1]-i*a[i]));
		lct.addLine(-i, sum[i-1]);
	}
	
	ans = -ans + c;
	outl(ans);
	
	return 0;
}