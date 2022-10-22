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
#define rall(x) (x).rbegin(),(x).rend()
#define outl(...) dump_func(__VA_ARGS__)
#define outf(x) cout << fixed << setprecision(16) << (x) << endl
#define pb push_back
#define fi first
#define se second
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

//const int mod = 1000000007;
const int mod = 998244353;

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
template<typename T> T comb2(ll n, ll k){ T ret = 1; rep(i, 1, k) ret *= n-k+i, ret /= i; return ret;}

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
string lltos(ll x, ll b = 10){string ret; for(;x;x/=b) ret += x % b + '0'; reverse(all(ret)); return ret;}
ll stoll(string &s, ll b = 10){ll ret = 0; for(auto c : s) ret *= b, ret += c - '0'; return ret;}
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
template<class T> T mdist(pair<T, T> s, pair<T, T> t){return abs(s.first-t.first) + abs(s.second-t.second);}
template<class T> T edist2(pair<T, T> s, pair<T, T> t){return (s.first-t.first)*(s.first-t.first) + (s.second-t.second)*(s.second-t.second);}

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


struct SqrtMod{
	static ll modpow(ll a, ll n, ll mod)
	{
		if(n == 0) return 1;
		if(n % 2) return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
		else return modpow((a*a)%mod, n/2, mod) % mod;
	}
	static bool check(ll a, ll p) //a
	{
		return (modpow(a, (p-1)/2, p) == 1);
	}
	static ll calc(ll a, ll p) //px^2 = a (mod p) x-1
	{
		a %= p;
		if(a == 0) return 0;
		if(p == 2 && a == 1) return 1;
		if(!check(a, p)) return -1;
		if(p % 4 == 3) return modpow(a, (p+1)/4, p);
		
		ll q = p-1, m = 0;
		while(q % 2 == 0) q /= 2, m++;
		
		ll z;
		for(int i = 1; i < p; i++){
			if(!check(i, p)){
				z = i;
				break;
			}
		}
		ll c = modpow(z, q, p), t = modpow(a, q, p), r = modpow(a, (q+1)/2, p);
		
		while(t != 1){
			ll M = 1, mul = t*t%p;
			while(mul != 1){
				M++;
				mul *= mul, mul %= p;
			}
			c = modpow(c, 1LL<<(m-M-1), p);
			r *= c, r %= p;
			c *= c, c %= p;
			t *= c, t %= p;
			m = M;
		}
		return r;
	}
};

struct NTT_Convolution{
	NTT_Convolution(){};
	static int rev(int x, int n){
		int ret = 0;
		for(int i = 0; i < n; i++) ret <<= 1, ret |= (x>>i) & 1;
		return ret;
	}
	static void DFT(vector<mint> &f, vector<mint> &F, int n, mint root, bool inv = false)
	{
		int N = 1<<n;
		F.resize(N);
		for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];
		if(inv) root = root.inverse();
		
		mint a, b, x, z;
		for(int i = 0; i < n; i++){
			int l = 1<<i;
			z = modpow(root, 1<<(n-(i+1)));
			for(int j = 0; j < N; j+=l*2){
				x = 1;
				for(int k = j; k < j+l; k++){
					a = F[k], b = F[k+l] * x;
					F[k] = a + b, F[k+l] = a - b, x *= z;
				}
			}
		}
		if(inv){
			mint Ninv = mint(N).inverse();
			for(int i = 0; i < N; i++) F[i] *= Ninv;
		}
	}
	static void conv(vector<mint> f, vector<mint> g, vector<mint> &dest)
	{
		ll logf = 0, logg = 0, len = f.size() + g.size();
		for(int i = f.size(); i; i /= 2) logf++;
		for(int i = g.size(); i; i /= 2) logg++;
		
		ll n = max(logf, logg)+1, N = 1<<n;
		f.resize(N), g.resize(N);
		mint root = modpow(mint(3), 119 * (1<<23-n));
		
		vector<mint> F, G;
		DFT(f, F, n, root), DFT(g, G, n, root);
		for(int i = 0; i < N; i++) F[i] *= G[i];
		DFT(F, f, n, root, true);
		
		f.resize(len-1);
		dest = f;
	}
};


struct FPS{
	static void inverse(vector<mint> f, int n, vector<mint> &dest) //required: f[0] != 0
	{
		int logn = digitnum(n, 2);
		while(f.size() < (1<<logn)) f.push_back(mint(0));
		
		vector<mint> fvec, gvec, ngvec;
		fvec.push_back(f[0]), gvec.push_back(f[0].inverse());
		
		for(int i = 1; i <= logn; i++){
			while(fvec.size() < (1<<i)) fvec.push_back(f[fvec.size()]);
			
			NTT_Convolution::conv(fvec, gvec, ngvec), ngvec.resize(1<<i);
			for(auto &x : ngvec) x = -x;
			ngvec[0] += mint(2);
			NTT_Convolution::conv(gvec, ngvec, ngvec), ngvec.resize(1<<i);
			swap(gvec, ngvec);
		}
		dest = gvec, dest.resize(n);
	}
	static void derivative(vector<mint> f, vector<mint> &dest)
	{
		dest.resize(f.size()-1);
		if(dest.size() == 0){
			dest.push_back(mint(0));
			return;
		}
		for(int i = 0; i < dest.size(); i++) dest[i] = f[i+1] * mint(i+1);
	}
	static void integral(vector<mint> f, vector<mint> &dest)
	{
		dest.resize(f.size()+1);
		dest[0] = mint(0);
		for(int i = 0; i < f.size(); i++) dest[i+1] = f[i] / mint(i+1);
	}
	static void log(vector<mint> f, int n, vector<mint> &dest) //required: f[0] == 1
	{
		vector<mint> df;
		FPS::derivative(f, df), FPS::inverse(f, n, f);
		NTT_Convolution::conv(df, f, f);
		FPS::integral(f, dest);
		dest.resize(n);
	}
	static void exp(vector<mint> f, int n, vector<mint> &dest) //required: f[0] == 0
	{
		int logn = digitnum(n, 2);
		while(f.size() < (1<<logn)) f.push_back(mint(0));
		
		vector<mint> fvec, gvec, ngvec;
		fvec.push_back(f[0]), gvec.push_back(mint(1));
		
		for(int i = 1; i <= logn; i++){
			while(fvec.size() < (1<<i)) fvec.push_back(f[fvec.size()]);
			log(gvec, (1<<i), ngvec), ngvec.resize(1<<i);
			for(int j = 0; j < (1<<i); j++) ngvec[j] = fvec[j] - ngvec[j];
			ngvec[0] += mint(1);
			NTT_Convolution::conv(gvec, ngvec, ngvec);
			ngvec.resize(1<<i);
			swap(gvec, ngvec);
		}
		dest = gvec, dest.resize(n);
	}
	static bool sqrt(vector<mint> f, int n, vector<mint> &dest)
	{
		dest.clear();
		int p = -1;
		for(int i = 0; i < (int)f.size(); i++){
			if(f[i] != mint(0)){
				p = i;
				break;
			}
		}
		if(p == -1){
			dest.resize(n);
			return true;
		}
		if(p % 2) return false;
		
		f.erase(f.begin(), f.begin()+p);
		ll r = SqrtMod::calc(f[0].x, mod);
		if(r == -1) return false;
		n -= p;
		
		int logn = digitnum(n, 2);
		while(f.size() < (1<<logn)) f.push_back(mint(0));
		
		vector<mint> fvec, gvec, ngvec;
		fvec.push_back(f[0]), gvec.push_back(mint(r));
		
		mint inv2 = mint(2).inverse();
		for(int i = 1; i <= logn; i++){
			while(fvec.size() < (1<<i)) fvec.push_back(f[fvec.size()]);
			inverse(gvec, (1<<i), ngvec);
			NTT_Convolution::conv(fvec, ngvec, ngvec), ngvec.resize(1<<i);
			for(int j = 0; j < (1<<(i-1)); j++) ngvec[j] = gvec[j] + ngvec[j];
			for(int j = 0; j < (1<<i); j++) ngvec[j] *= inv2;
			swap(gvec, ngvec);
		}
		dest = gvec, dest.resize(n);
		
		vector<mint> zvec;
		for(int i = 1; i <= p/2; i++) zvec.push_back(0);
		dest.insert(dest.begin(), zvec.begin(), zvec.end());
		dest.insert(dest.end(), zvec.begin(), zvec.end());
		
		return true;
	}
	static void shift(vector<mint> f, mint c, vector<mint> &dest) //
	{
		int n = f.size();
		dest.clear(), dest.resize(n);
		
		vector<mint> avec(n), bvec(n);
		for(int i = 0; i < n; i++){
			avec[i] = f[i] * fact[i];
			bvec[i] = modpow(c, n-1-i) * fact_inv[n-1-i];
		}
		NTT_Convolution::conv(avec, bvec, dest);
		dest.erase(dest.begin(), dest.begin()+(n-1));
		for(int i = 0; i < n; i++) dest[i] *= fact_inv[i];
	}
};

ll n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	vector<mint> vec(100005);
	vec[0] = 1;
	ll x;
	rep(i, 1, n){
		cin >> x;
		vec[x] = -4;
	}
	FPS::sqrt(vec, 100005, vec);
	vec[0] += 1;
	FPS::inverse(vec, 100005, vec);
	rep(i, 1, m) vec[i] *= 2;
	
	rep(i, 1, m) outl(vec[i]);
	
	return 0;
}