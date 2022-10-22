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

template<class S, class T> pair<S,T>& operator+=(pair<S,T> &s, const pair<S,T> &t){
	s.first += t.first, s.second += t.second;
	return s;
}
template<class S, class T> pair<S,T>& operator-=(pair<S,T> &s, const pair<S,T> &t){
	s.first -= t.first, s.second -= t.second;
	return s;
}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){
	return pair<S,T>(s.first+t.first, s.second+t.second);
}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){
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

ll n;
char c[2005][2005], d[2005][2005];
ll mx[2005][2005];
P sumx[2005][2005], sumy[2005][2005];
ll z[2005];
vector<ll> vec[2005];

void shift(vector<ll> &vec, ll x)
{
	vector<ll> tmp;
	rep(i, 1, x) tmp.push_back(0);
	vec.insert(vec.begin(), all(tmp));
}
void add(vector<ll> &avec, vector<ll> &bvec, vector<ll> &dest)
{
	dest = bvec;
	reps(i, avec) dest[i] += avec[i];
	reps(i, dest){
		if(dest[i] <= 1) continue;
		if(i == sz(dest)-1) dest.push_back(0);
		dest[i+1] += dest[i]/2;
		dest[i] %= 2;
	}
}
bool comp(vector<ll> &avec, vector<ll> &bvec)
{
	if(sz(bvec) > sz(avec)) return true;
	if(sz(bvec) < sz(avec)) return false;
	
	per(i, sz(avec)-1, 0){
		if(avec[i] < bvec[i]) return true;
		if(avec[i] > bvec[i]) return false;
	}
	return false;
}

void calc(ll n, char c[2005][2005])
{
	rep(y, 1, n) rep(x, 1, n) mx[x][y] = inf;
	rep(y, 1, n){
		ll cnt = 0;
		rep(x, 1, n){
			if(c[x][y] == '0') cnt = 0;
			else cnt++;
			chmin(mx[x][y], cnt);
		}
		cnt = 0;
		per(x, n, 1){
			if(c[x][y] == '0') cnt = 0;
			else cnt++;
			chmin(mx[x][y], cnt);
		}
	}
	rep(x, 1, n){
		ll cnt = 0;
		rep(y, 1, n){
			if(c[x][y] == '0') cnt = 0;
			else cnt++;
			chmin(mx[x][y], cnt);
		}
		cnt = 0;
		per(y, n, 1){
			if(c[x][y] == '0') cnt = 0;
			else cnt++;
			chmin(mx[x][y], cnt);
		}
	}
	
	rep(y, 1, n){
		rep(x, 1, n){
			sumx[x][y] = sumx[x-1][y];
			if(c[x][y] == '2') sumx[x][y].first++;
			if(c[x][y] == '3') sumx[x][y].second++;
		}
	}
	rep(x, 1, n){
		rep(y, 1, n){
			sumy[x][y] = sumy[x][y-1];
			if(c[x][y] == '2') sumy[x][y].first++;
			if(c[x][y] == '3') sumy[x][y].second++;
		}
	}
	rep(y, 1, n) rep(x, 1, n){
		P cnt = P(0, 0); ll d = mx[x][y]-1;
		if(d == -1) continue;
		cnt += sumx[x-1][y]-sumx[x-d-1][y];
		cnt += sumx[x+d][y]-sumx[x][y];
		cnt += sumy[x][y-1]-sumy[x][y-d-1];
		cnt += sumy[x][y+d]-sumy[x][y];
		if(c[x][y] == '2') cnt.first++;
		if(c[x][y] == '3') cnt.second++;
		chmax(z[cnt.first], cnt.second);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(y, 1, n) rep(x, 1, n) cin >> c[x][y];
	rep(i, 0, 2*n) z[i] = -inf;
	
	calc(n, c);
	
	rep(x, 1, 2*n+3) rep(y, 1, 2*n+3) d[x][y] = '0';
	rep(x, 1, n) rep(y, 1, n){
		if((x+y) % 2) continue;
		d[(x+y)/2+1][(x-y+n)/2+1] = c[x][y];
	}
	calc(2*n+3, d);
	
	rep(x, 1, 2003) rep(y, 1, 2003) d[x][y] = '0';
	rep(x, 1, n) rep(y, 1, n){
		if((x+y) % 2 == 0) continue;
		d[(x+y)/2+1][(x-y+n)/2+1] = c[x][y];
	}
	calc(2*n+3, d);
	
	
	vec[0].push_back(1);
	rep(i, 1, 2*n){
		vector<ll> tmp;
		tmp = vec[i-1];
		shift(tmp, 1);
		add(vec[i-1], tmp, vec[i]);
	}
	
	vector<ll> avec;
	rep(i, 0, 2*n){
		if(z[i] < 0) continue;
		vector<ll> tmp = vec[z[i]];
		shift(tmp, i);
		if(comp(avec, tmp)) avec = tmp;
	}
	
	mint ans = mint(0), mul = mint(1);
	for(auto x : avec){
		ans += mint(x) * mul;
		mul *= mint(2);
	}
	outl(ans);
	
	return 0;
}