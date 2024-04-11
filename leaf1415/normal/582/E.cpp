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

vector<int> prime, pvec;
void make_prime(int n){
	prime.resize(n+1);
	rep(i, 2, n){
		if(prime[i]) continue;
		for(int j = i; j <= n; j += i) prime[j] = i;
	}
	rep(i, 2, n) if(prime[i] == i) pvec.push_back(i);
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

struct node{
	char c;
	ll left, right;
	node(){}
	node(char c){
		this->c = c;
		left = right = -1;
	}
};

ll n;
string s;
ll a[16];
ll pos[4], neg[4];
vector<node> tree;

mint dp[305][1<<16];
mint tmp[1<<16], tmp2[1<<16];

char parseChar(int &pos)
{
	char c = s[pos];
	pos++;
	return c;
}
ll parseExp(int &pos)
{
	if(s[pos] != '('){
		tree.push_back(node(parseChar(pos)));
		return sz(tree)-1;
	}
	
	pos++;
	ll l = parseExp(pos);
	pos++;
	char c = parseChar(pos);
	pos++;
	ll r = parseExp(pos);
	pos++;
	
	tree.push_back(node(c));
	tree.back().left = l, tree.back().right = r;
	
	return sz(tree)-1;
}

template<typename T>
void zeta_transform(T a[], int n){
	rep(i, 0, n-1) rep(j, 0, (1<<n)-1) if(!(j&(1<<i))) a[j] += a[j^(1<<i)];
}
template<typename T>
void moebius_transform(T a[], int n){
	rep(i, 0, n-1) rep(j, 0, (1<<n)-1) if(!(j&(1<<i))) a[j] -= a[j^(1<<i)];
}

template<typename T>
void zeta_transform2(T a[], int n){
	rep(i, 0, n-1) rep(j, 0, (1<<n)-1) if((j&(1<<i))) a[j] += a[j^(1<<i)];
}
template<typename T>
void moebius_transform2(T a[], int n){
	rep(i, 0, n-1) rep(j, 0, (1<<n)-1) if((j&(1<<i))) a[j] -= a[j^(1<<i)];
}

void dfs(int v)
{
	if(tree[v].left == -1){
		if(tree[v].c == '?'){
			rep(i, 0, 3){
				dp[v][pos[i]] += 1;
				dp[v][neg[i]] += 1;
			}
		}
		else{
			if(tree[v].c >= 'A' && tree[v].c <= 'D') dp[v][pos[tree[v].c-'A']] += 1;
			else dp[v][neg[tree[v].c-'a']] += 1;
		}
		return;
	}
	
	dfs(tree[v].left);
	dfs(tree[v].right);
	
	if(tree[v].c != '|'){
		rep(i, 0, (1<<16)-1){
			tmp[i] = dp[tree[v].left][i];
			tmp2[i] = dp[tree[v].right][i];
		}
		zeta_transform(tmp, 16);
		zeta_transform(tmp2, 16);
		rep(i, 0, (1<<16)-1) tmp[i] *= tmp2[i];
		moebius_transform(tmp, 16);
		rep(i, 0, (1<<16)-1) dp[v][i] += tmp[i];
	}
	if(tree[v].c != '&'){
		rep(i, 0, (1<<16)-1){
			tmp[i] = dp[tree[v].left][i];
			tmp2[i] = dp[tree[v].right][i];
		}
		zeta_transform2(tmp, 16);
		zeta_transform2(tmp2, 16);
		rep(i, 0, (1<<16)-1) tmp[i] *= tmp2[i];
		moebius_transform2(tmp, 16);
		rep(i, 0, (1<<16)-1) dp[v][i] += tmp[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	s += "#";
	
	rep(i, 0, 15) a[i] = -1;
	cin >> n;
	rep(i, 1, n){
		ll mask = 0, x;
		rep(j, 0, 3){
			cin >> x;
			mask |= x << j;
		}
		cin >> x;
		a[mask] = x;
	}
	
	int p = 0;
	ll root = parseExp(p);
	//reps(i, tree) outl(tree[i].c, tree[i].left, tree[i].right);
	
	rep(i, 0, 3){
		rep(j, 0, 15){
			if(j & (1<<i)) pos[i] |= 1<<j;
			else neg[i] |= 1<<j;
		}
	}
	
	dfs(root);
	
	mint ans = 0;
	rep(i, 0, (1<<16)-1){
		bool flag = true;
		rep(j, 0, 15){
			if(a[j] == -1) continue;
			flag &= (((i>>j)&1) == a[j]);
		}
		if(flag) ans += dp[root][i];
	}
	outl(ans);
	
	return 0;
}