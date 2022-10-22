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

//const ll mod = 1000000007;
const ll mod = 998244353;

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
ll modpow(ll a, ll n){
	if(n == 0) return 1;
	if(n % 2) return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	else return modpow((a*a)%mod, n/2) % mod;
}


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

struct SegTree{
	typedef ll SEG;
	
	int size;
	vector<SEG> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	SEG Ident(){  //identity element
		return 0;
	}
	SEG ope(SEG a, SEG b){ //operator
		return a+b;
	}
	
	void init(){
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	void update(int i, SEG val){
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}
	SEG query(int a, int b, int k, int l, int r){
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		SEG lval = query(a, b, k*2, l, (l+r)/2);
		SEG rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	SEG query(int a, int b){
		if(a > b) return Ident();
		return query(a, b, 1, 0, (1<<size)-1);
	}
	ll get(ll x){
		ll l = 0, r = (1<<size)-1, k = 1;
		while(l < r){
			if(seg[k*2] >= x) r = (l+r)/2, k = k*2;
			else x -= seg[k*2], l = (l+r)/2+1, k = k*2+1;
		}
		return l;
	}
};

ll T;
ll n, Q;
ll a[1000005];
vector<ll> G[1000005];
ll l[1000005], k[1000005];
vector<ll> qvec[1000005];
ll ans[1000005];

ll cnt[1000005], num[1000005];
vector<ll> vec[1000005];
set<ll> S[1000005];
SegTree seg(20);

void dfs(int v)
{
	num[cnt[a[v]]]--;
	seg.update(cnt[a[v]], num[cnt[a[v]]]);
	cnt[a[v]]++;
	num[cnt[a[v]]]++;
	seg.update(cnt[a[v]], num[cnt[a[v]]]);
	vec[cnt[a[v]]].push_back(a[v]);
	
	/*outl("v= ", v);
	rep(i, 0, 3) outl(S[i]);
	rep(i, 0, 3) cout << seg.query(i, i) <<" "; cout<< endl;*/
	
	for(auto id : qvec[v]){
		ll res = seg.get(seg.query(0, l[id]-1) + k[id]);
		if(res > n) ans[id] = -1;
		else{
			while(cnt[vec[res].back()] != res) vec[res].pop_back();
			ans[id] = vec[res].back();
		}
	}
	
	for(auto u : G[v]) dfs(u);
	
	num[cnt[a[v]]]--;
	seg.update(cnt[a[v]], num[cnt[a[v]]]);
	cnt[a[v]]--;
	num[cnt[a[v]]]++;
	seg.update(cnt[a[v]], num[cnt[a[v]]]);
	vec[cnt[a[v]]].push_back(a[v]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	seg.init();
	
	cin >> T;
	while(T--){
		cin >> n >> Q;
		rep(i, 1, n) cin >> a[i];
		
		ll p;
		rep(i, 1, n) G[i].clear();
		rep(i, 2, n){
			cin >> p;
			G[p].push_back(i);
		}
		
		ll v;
		rep(i, 1, n) qvec[i].clear();
		rep(i, 1, Q){
			cin >> v >> l[i] >> k[i];
			qvec[v].push_back(i);
		}
		
		seg.update(0, n), num[0] = n;
		rep(i, 1, n) vec[i].clear();
		dfs(1);
		
		rep(i, 1, Q) cout << ans[i] << " "; cout << "\n";
	}
	
	return 0;
}