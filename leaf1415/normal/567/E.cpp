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
		for(auto p : pvec){
			if(i*p > n || p > prime[i]) break;
			prime[i*p] = p;
		}
	}
}
void make_qrime(int n){
	qrime.resize(n+1);
	rep(i, 2, n){
		int ni = i / prime[i];
		if(prime[i] == prime[ni]) qrime[i] = qrime[ni] * prime[i];
		else qrime[i] = prime[i];
	}
}

bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}
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
template<typename T> ostream& operator << (ostream& os, deque<T>& deq){reps(i,  deq) os << deq[i] << " "; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& ope){ for(auto p : ope) os << "(" << p.first << ", " << p.second << "),";return os;}
template<typename T> ostream& operator << (ostream& os, set<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, multiset<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> void outa(T a[], ll s, ll t){rep(i, s, t){ cout << a[i]; if(i < t) cout << " ";} cout << endl;}
void dump_func(){cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail){cout << head; if(sizeof...(Tail) > 0) cout << " "; dump_func(std::move(tail)...);}


void dijkstra(vector<edge> G[], int n, int S, ll dist[])
{
	for(int i = 0; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( P(0, S) );
	
	ll v, d;
	while(Q.size()){
		d = Q.top().first, v = Q.top().second, Q.pop();
		if(dist[v] < d) continue;
		for(auto e : G[v]){
			ll u = e.to, c = e.cost;
			if(dist[u] > dist[v] + c){
				dist[u] = dist[v] + c;
				Q.push(P(dist[u], u));
			}
		}
	}
}


struct BECC{
	struct edge{
		int to, id;
		edge(){}
		edge(int a, int b){to = a, id = b;}
	};
	
	int n;
	set<P> bridgeS;
	vector<vector<edge> > G;
	vector<vector<int> > compG;
	vector<int> becc;
	vector<int> pre, low;
	int order, eid, cid, beccnum;
	
	BECC(){}
	BECC(int n){this->n = n, eid = 0, G.resize(n+1);}  //V(G) = {1, 2, ..., n}, n
	
	void add_edge(int u, int v){
		eid++;
		G[u].push_back(edge(v, eid));
		G[v].push_back(edge(u, eid));
	}
	int finddfs(int v, int eid){
		pre[v] = ++order;
		int ret = pre[v];
		for(auto e : G[v]){
			int u = e.to, id = e.id;
			if(id == eid) continue;
			if(pre[u]) ret = min(ret, pre[u]);
			else ret = min(ret, finddfs(u, id));
		}
		return low[v] = ret;
	}

	void findBridge(){ //(u, v)u < vbridgeS
		order = 0, bridgeS.clear();
		pre.resize(n+1), low.resize(n+1);
		for(int i = 1; i <= n; i++) pre[i] = low[i] = 0;
		
		for(int i = 1; i <= n; i++) if(!pre[i]) finddfs(i, -1);
		for(int i = 1; i <= n; i++){
			for(auto e : G[i]){
				int u = e.to;
				if(pre[i] < pre[u] && low[u] > pre[i]){
					if(i < u) bridgeS.insert(P(i, u));
					else bridgeS.insert(P(u, i));
				}
			}
		}
	}
	bool isBridge(int u, int v){ //findBridge()true
		if(u > v) swap(u, v);
		return bridgeS.count(P(u, v));
	}
	void beccdfs(int v, int eid, int cid){
		becc[v] = cid;
		for(auto e : G[v]){
			int u = e.to, id = e.id;
			if(id == eid) continue;
			if(becc[u] || isBridge(u, v)) continue;
			beccdfs(u, id, cid);
		}
	}
	int calcBECC(){ //findBridge()BECCBECC-ID1-indexed
		cid = 0, becc.resize(n+1);
		for(int i = 1; i <= n; i++) becc[i] = 0;
		for(int i = 1; i <= n; i++) if(!becc[i]) beccdfs(i, -1, ++cid);
		return beccnum = cid;
	}
	void compressBECC(){ //calcBECC()BECC::compG
		compG.resize(beccnum+1);
		for(auto e : bridgeS){
			int u = becc[e.first], v = becc[e.second];
			compG[u].push_back(v);
			compG[v].push_back(u);
		}
	}
};

ll n, m, s, t;
ll u[100005], v[100005], w[100005];
vector<edge> G[100005], revG[100005];
ll distS[100005], distT[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s >> t;
	rep(i, 1, m){
		cin >> u[i] >> v[i] >> w[i];
		G[u[i]].push_back(edge(v[i], w[i]));
		revG[v[i]].push_back(edge(u[i], w[i]));
	}
	dijkstra(G, n, s, distS);
	dijkstra(revG, n, t, distT);
	ll d = distS[t];
	
	BECC becc(n);
	rep(i, 1, m){
		if(distS[u[i]] + w[i] + distT[v[i]] == d) becc.add_edge(u[i], v[i]);
	}
	becc.findBridge();
	
	rep(i, 1, m){
		if(distS[u[i]] + w[i] + distT[v[i]] == d){
			if(becc.isBridge(u[i], v[i])) cout << "YES" << "\n";
			else if(w[i] == 1) cout << "NO" << "\n";
			else cout << "CAN" << " " << 1 << "\n";
		}
		else{
			ll x = d - (distS[u[i]] + distT[v[i]]) - 1;
			if(x < 1) cout << "NO" << "\n";
			else cout << "CAN" << " " << w[i] - x << "\n";
		}
	}
	
	return 0;
}