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


struct FFT_Convolution{
	typedef complex<double> C;
	
	FFT_Convolution(){};
	static int rev(int x, int n){
		int ret = 0;
		for(int i = 0; i < n; i++) ret <<= 1, ret |= (x>>i) & 1;
		return ret;
	}
	
	static void DFT(vector<C> &f, vector<C> &F, int n)
	{
		int N = 1<<n;
		F.resize(N);
		for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];
		
		C a, b, x, z;
		for(int i = 1; i <= n; i++){
			int l = 1<<i;
			z = C(cos(2*PI/l), sin(2*PI/l));
			for(int j = 0; j < N/l; j++){
				x = C(1, 0);
				for(int k = 0; k < l/2; k++){
					a = F[j*l+k], b = F[j*l+k+l/2];
					F[j*l+k] = a + x * b;
					F[j*l+k+l/2] = a - x * b;
					x *= z;
				}
			}
		}
	}
	static void IDFT(vector<C> &F, vector<C> &f, int n)
	{
		int N = 1<<n;
		for(int i = 0; i < N; i++) f[rev(i, n)] = F[i];
		
		C a, b, x, z;
		for(int i = 1; i <= n; i++){
			int l = 1<<i;
			z = C(cos(2*PI/l), -sin(2*PI/l));
			for(int j = 0; j < N/l; j++){
				x = C(1, 0);
				for(int k = 0; k < l/2; k++){
					a = f[j*l+k], b = f[j*l+k+l/2];
					f[j*l+k] = a + x * b;
					f[j*l+k+l/2] = a - x * b;
					x *= z;
				}
			}
		}
		for(int i = 0; i < N; i++) f[i] /= N;
	}
	static ll round(C c){return (ll)(c.real()+0.5);}
	
	static void conv(vector<ll> f, vector<ll> g, vector<ll> &dest)
	{
		ll logf = 0, logg = 0, len = f.size() + g.size();
		for(int i = f.size(); i; i /= 2) logf++;
		for(int i = g.size(); i; i /= 2) logg++;
		
		ll n = max(logf, logg)+1, N = 1<<n;
		vector<C> f2(N), g2(N);
		for(int i = 0; i < N; i++){
			if(i < f.size()) f2[i] = C(f[i], 0);
			else f2[i] = C(0, 0);
		}
		for(int i = 0; i < N; i++){
			if(i < g.size()) g2[i] = C(g[i], 0);
			else g2[i] = C(0, 0);
		}
		
		vector<C> F, G;
		DFT(f2, F, n), DFT(g2, G, n);
		for(int i = 0; i < N; i++) F[i] *= G[i];
		IDFT(F, f2, n);
		
		dest.resize(len-1);
		for(int i = 0; i < dest.size(); i++) dest[i] = round(f2[i]);
	}
};

ll S, T, k;
string s, t;
ll a[4][200005];
vector<ll> svec[4], tvec[4], uvec[4];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> S >> T >> k;
	cin >> s >> t;
	reverse(all(t));
	
	ll c;
	rep(i, 0, S-1){
		if(s[i] == 'A') c = 0;
		if(s[i] == 'C') c = 1;
		if(s[i] == 'G') c = 2;
		if(s[i] == 'T') c = 3;
		ll l = max(0LL, i-k), r = min(S-1, i+k);
		a[c][l]++, a[c][r+1]--;
	}
	rep(i, 0, 3) rep(j, 1, S-1) a[i][j] += a[i][j-1];
	
	rep(i, 0, 3){
		rep(j, 0, S-1){
			if(a[i][j]) svec[i].pb(1);
			else svec[i].pb(0);
		}
	}
	
	rep(i, 0, 3) tvec[i].resize(T);
	rep(i, 0, T-1){
		if(t[i] == 'A') c = 0;
		if(t[i] == 'C') c = 1;
		if(t[i] == 'G') c = 2;
		if(t[i] == 'T') c = 3;
		tvec[c][i] = 1;
	}
	
	rep(i, 0, 3) FFT_Convolution::conv(svec[i], tvec[i], uvec[i]);

	ll ans = 0;
	rep(i, 0, S+T-2){
		ll sum = 0;
		rep(j, 0, 3) sum += uvec[j][i];
		if(sum == T) ans++;
	}
	outl(ans);
	
	return 0;
}