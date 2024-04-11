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



// range-add, range-min query
 
struct LazySegTree{
	typedef ll SEG;
	typedef ll DELAY;
	
	int size;
	vector<SEG> seg;
	vector<DELAY> delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	SEG Ident(){ //identity element
		return -inf;
	}
	SEG ope(SEG a, SEG b){ //operator
		return max(a, b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = Ident();
			delay[i] = 0; //
		}
	}
	
	void eval(int l, int r, int k) //
	{
		if(delay[k]){
			seg[k] += delay[k];  //
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, SEG val)
	{
		int l = 0, r = (1<<size)-1, k = 1;
		
		eval(l, r, k);
		for(int j = size-1; j >= 0; j--){
			k <<= 1;
			if(i & (1<<j)){
				k++;
				l = (l+r)/2+1;
			}
			else r = (l+r)/2;
			eval(l, r, k);
		}
		
		seg[i+(1<<size)] = val;
		
		l = i, r = i, k = i+(1<<size);
		for(int j = 0; j < size; j++){
			k /= 2, l &= ~(1<<j), r |= 1<<j;
			eval(l, (l+r)/2, k*2), eval((l+r)/2+1, r, k*2+1);
			seg[k] = ope(seg[k*2], seg[k*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, DELAY val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] += val; //
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = ope(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, DELAY val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	SEG query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		SEG lval = query(a, b, k*2, l, (l+r)/2);
		SEG rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	SEG query(int a, int b)
	{
		if(a > b) return Ident();
		return query(a, b, 1, 0, (1<<size)-1);
	}
};


ll n;
ll h[300005], b[300005];
LazySegTree seg(19);
ll dp[300005];
stack<P> stk;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> h[i];
	rep(i, 1, n) cin >> b[i];
	
	seg.init();
	seg.update(0, 0);
	stk.push(P(-inf, 0));
	
	rep(i, 1, n){
		while(stk.top().first > h[i]){
			ll r = stk.top().second;
			stk.pop();
			ll l = stk.top().second;
			seg.add(l, r-1, -b[r]);
		}
		ll l = stk.top().second;
		stk.push(P(h[i], i));
		ll r = stk.top().second;
		seg.add(l, r-1, b[r]);
		
		//outl(l+1, r, b[r]);
		//rep(j, 0, n) cout << seg.query(j, j) << " "; cout << endl;
		
		dp[i] = seg.query(0, i-1);
		seg.update(i, dp[i]);
	}
	//outa(dp, 0, n);
	outl(dp[n]);
	
	return 0;
}