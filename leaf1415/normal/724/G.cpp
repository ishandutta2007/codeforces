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


struct GaussianElimination{
	vector<llint> vec;
	int dim;
	
	GaussianElimination(){
		init();
	}
	void init(){
		dim = 0;
		vec.clear();
	}
	void add(llint x) //
	{
		vec.push_back(x);
		int n = vec.size();
		
		int r = 0, p = -1;
		for(int i = 59; i >= 0 && r < n-1; i--){ //
			if((vec[r]&(1LL<<i)) == 0){
				if((vec[n-1]&(1LL<<i)) == 0 || p != -1) goto end;
				if(p == -1) p = r;
			}
			else if(vec[n-1]&(1LL<<i)) vec[n-1] ^= vec[r];
			r++;
			end:;
		}
		if(p != -1){
			llint tmp = vec[n-1];
			for(int i = n-1; i >= p+1; i--) vec[i] = vec[i-1];
			vec[p] = tmp;
		}
		if(vec[dim]) dim++;
	}
	
	bool check(llint x) //
	{
		int n = vec.size();
		
		int r = 0;
		for(int i = 59; i >= 0 && r < n; i--){
			if((x & (1LL<<i)) == 0){
				if(vec[r] & (1LL<<i)) r++;
				continue;
			}
 			if((vec[r]&(1LL<<i)) == 0) return false;
			x ^= vec[r];
			r++;
		}
		return x == 0;
	}
};

ll n, m;
vector<edge> G[100005];
bool used[100005];
ll sum[100005];
GaussianElimination ge;

vector<ll> vec;
ll cnt0[60], cnt1[60];
ll dfs(int v, int p, ll x)
{
	used[v] = true, sum[v] = x;
	rep(i, 0, 59){
		if(x & (1LL<<i)) cnt1[i]++;
		else cnt0[i]++;
	}
	
	ll ret = 1;
	for(auto e : G[v]){
		ll u = e.to;
		if(u == p) continue;
		if(used[u]){
			vec.push_back(sum[u]^sum[v]^e.cost);
			continue;
		}
		ret += dfs(u, v, x^e.cost);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v, w;
	rep(i, 1, m){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	
	mint ans = mint(0);
	rep(i, 1, n){
		if(used[i]) continue;
		
		vec.clear();
		rep(j, 0, 59) cnt0[j] = cnt1[j] = 0;
		ll res = dfs(i, -1, 0);
		
		ge.init();
		for(auto x : vec) ge.add(x);
		ll acc = 0;
		for(auto x : ge.vec) acc |= x;
		
		rep(j, 0, 59){
			if(acc & (1LL<<j)) ans += mint(res*(res-1)/2) * modpow(mint(2), ge.dim) / mint(2) * mint(1LL<<j);
			else ans += mint(cnt0[j]*cnt1[j]) * modpow(mint(2), ge.dim) * mint(1LL<<j);
		}
	}
	outl(ans);
	
	return 0;
}