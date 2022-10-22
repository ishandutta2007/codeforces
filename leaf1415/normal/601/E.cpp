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

ll n, M, Q;
ll v[40005], w[40005];
ll dp[20005][1005];
ll qid[30005];
ll pos = 0;

struct DynamicConnectivity{
	typedef pair<P, P> R;
	typedef pair<int, P> Q;
	
	int n, T;
	vector<R> rvec;
	vector<mint> avec;
	map<P, int> mp;
	
	int b, qid;
	vector<vector<P> > seg;
	vector<vector<Q> > qvec;
	
	DynamicConnectivity(){}
	DynamicConnectivity(int n, int T){
		this->n = n, this->T = T;
		init();
	}
	void init(){
		qid = 0;
		mp.clear();
		rvec.clear();
		qvec.resize(T+1);
		rep(i, 0, M) dp[0][i] = -inf;
		dp[0][0] = 0;
	}
	
	void add(int time, int u, int v){
		if(u > v) swap(u, v);
		if(mp.count(P(u, v))) return;
		mp[P(u, v)] = time;
	}
	void erase(int time, int u, int v){
		if(mp.count(P(u, v)) == 0) return;
		rvec.push_back(R(P(mp[P(u, v)], time-1), P(u, v)));
		mp.erase(P(u, v));
	}
	void update(int time, int u, int v){
		if(u > v) swap(u, v);
		if(mp.count(P(u, v))) erase(time, u, v);
		else add(time, u, v);
	}
	int check(int time, int u, int v){
		if(qvec.size() <= time) qvec.resize(time+1);
		qvec[time].push_back(Q(qid, P(u, v)));
		return qid++;
	}
	
	void put(int a, int b, int k, int l, int r, P p)
	{
		if(b < l || r < a) return ;
		if(a <= l && r <= b){
			seg[k].push_back(p);
			return;
		}
		put(a, b, k*2, l, (l+r)/2, p);
		put(a, b, k*2+1, (l+r)/2+1, r, p);
	}
	
	void dfs(int k, int l, int r){
		for(int i = 0; i < seg[k].size(); i++){
			ll id = seg[k][i].first;
			pos++;
			rep(j, 0, M){
				dp[pos][j] = dp[pos-1][j];
				if(j-w[id] >= 0) chmax(dp[pos][j], dp[pos-1][j-w[id]] + v[id]);
			}
		}
		if(l == r){
			int t = k - (1<<b);
			if(t <= T){
				for(int i = 0; i < qvec[t].size(); i++){
					int qid = qvec[t][i].first, u = qvec[t][i].second.first, v = qvec[t][i].second.second;
					mint tmp = 0, mul = 1; ll mx = 0;
					rep(j, 1, M){
						chmax(mx, dp[pos][j]);
						tmp += mint(mx) * mul;
						mul *= 10000019;
					}
					avec[qid] = tmp;
				}
			}
		}
		else{
			int m = (l+r)/2;
			dfs(k*2, l, m), dfs(k*2+1, m+1, r);
		}
		pos -= sz(seg[k]);
	}
	
	void calc(){
		for(auto p : mp) rvec.push_back(R(P(p.second, T), p.first));
		
		b = 0;
		for(int t = T; t; t >>=1) b++;
		seg.resize(1<<(b+1));
		
		for(int i = 0; i < (int)rvec.size(); i++){
			put(rvec[i].first.first, rvec[i].first.second, 1, 0, (1<<b)-1, rvec[i].second);
		}
		avec.resize(qid);
		dfs(1, 0, (1<<b)-1);
	}
};


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> M;
	rep(i, 1, n) cin >> v[i] >> w[i];
	
	cin >> Q;
	DynamicConnectivity dc(n, Q);
	rep(i, 1, n) dc.add(0, i, i);
	
	ll t, x, id = n;
	rep(i, 1, Q) qid[i] = -1;
	rep(i, 1, Q){
		cin >> t;
		if(t == 1){
			id++;
			cin >> v[id] >> w[id];
			dc.add(i, id, id);
		}
		if(t == 2){
			cin >> x;
			dc.erase(i, x, x);
		}
		if(t == 3) qid[i] = dc.check(i, i, i);
	}
	dc.calc();
	
	rep(i, 1, Q) if(qid[i] != -1) outl(dc.avec[qid[i]]);
	
	return 0;
}