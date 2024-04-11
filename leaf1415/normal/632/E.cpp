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

//const ll mod = 1000000007;
//const ll mod = 998244353;

/*struct mint{
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
mint comb(ll n, ll k){ if(n < 0 || k < 0 || n < k) return mint(0); return fact[n] * fact_inv[k] * fact_inv[n-k];}
mint perm(ll n, ll k){ return comb(n, k) * fact[k]; }*/

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



/*
{1224736769, 3}, // 2^24 * 73 + 1,
{1053818881, 7}, // 2^20 * 3 * 5 * 67 + 1
{1051721729, 6}, // 2^20 * 17 * 59 + 1
{1045430273, 3}, // 2^20 * 997 + 1
{1012924417, 5}, // 2^21 * 3 * 7 * 23 + 1
{1007681537, 3}, // 2^20 * 31^2 + 1
{1004535809, 3}, // 2^21 * 479 + 1
{998244353, 3},  // 2^23 * 7 * 17 + 1
{985661441, 3},  // 2^22 * 5 * 47 + 1
{976224257, 3},  // 2^20 * 7^2 * 19 + 1
{975175681, 17}, // 2^21 * 3 * 5 * 31 + 1
{962592769, 7},  // 2^21 * 3^3 * 17 + 1
{950009857, 7},  // 2^21 * 4 * 151 + 1
{943718401, 7},  // 2^22 * 3^2 * 5^2 + 1
{935329793, 3},  // 2^22 * 223 + 1
{924844033, 5},  // 2^21 * 3^2 * 7^2 + 1
{469762049, 3},  // 2^26 * 7 + 1
{167772161, 3},  // 2^25 * 5 + 1
*/

llint modpow(llint a, llint n, llint mod)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2, mod) % mod;
	}
}

int rev(int x, int n)
{
	int ret = 0;
	for(int i = 0; i < n; i++){
		ret <<= 1;
		ret |= (x>>i) & 1;
	}
	return ret;
}

//f[]F[]root12^n
void DFT(llint f[], llint F[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		const int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = F[j*l+k], b = F[j*l+k+l/2];
				F[j*l+k] = a + x * b % mod;
				F[j*l+k+l/2] = a - x * b % mod + mod;
				if(F[j*l+k] >= mod) F[j*l+k] -= mod;
				if(F[j*l+k+l/2] >= mod) F[j*l+k+l/2] -= mod;
				x *= z, x %= mod;
			}
		}
	}
}

//f[]F[]root12^n
void IDFT(llint F[], llint f[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) f[rev(i, n)] = F[i];
	root = modpow(root, mod-2, mod);
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		const int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = f[j*l+k], b = f[j*l+k+l/2];
				f[j*l+k] = a + x * b % mod;
				f[j*l+k+l/2] = a - x * b % mod + mod;
				if(f[j*l+k] >= mod) f[j*l+k] -= mod;
				if(f[j*l+k+l/2] >= mod) f[j*l+k+l/2] -= mod;
				x *= z, x %= mod;
			}
		}
	}
	llint Ninv = modpow(N, mod-2, mod);
	for(int i = 0; i < N; i++) f[i] *= Ninv, f[i] %= mod;
}


ll n, k;
ll a[1005];
bool b[1005];
llint f[1<<20], F[1<<20];
ll cnt[1<<20];
ll N = 1<<20;

void calc(ll mod, ll root)
{
	rep(i, 0, N-1) f[i] = 0;
	rep(i, 0, 1000) if(b[i]) f[i] = 1;
	
	DFT(f, F, 20, mod, root);
	rep(i, 0, N-1) F[i] = modpow(F[i], k, mod);
	IDFT(F, f, 20, mod, root);
	
	rep(i, 0, N-1) if(f[i]) cnt[i]++;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], b[a[i]] = true;
	
	calc(998244353, modpow(3, 7*17*(1<<3), 998244353));
	calc(1004535809, modpow(3, 479*(1<<1), 1004535809));
	calc(985661441, modpow(3, 5*47*(1<<2), 985661441));
	
	vector<ll> ans;
	rep(i, 0, N-1) if(cnt[i]) ans.push_back(i);
	outl(ans);
	
	return 0;
}