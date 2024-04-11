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

struct UnionFind{
	int size;
	vector<int> parent;
	vector<int> rank;
	vector<llint> v, e;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		rank.resize(size+1);
		v.resize(size+1);
		e.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++){
			parent[i] = i, rank[i] = 0;
			v[i] = 1, e[i] = 0;
		}
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void merge(int i, int j){ // j will become new root
		parent[i] = j;
		v[j] += v[i];
		e[j] += e[i] + 1;
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j){
			e[root_i]++;
			return;
		}
		if(rank[root_i] < rank[root_j]) merge(root_i, root_j);
		else merge(root_j, root_i);
		if(rank[root_i] == rank[root_j]) rank[root_i]++;
	}
};

ll n, k;
char c[505][505];
UnionFind uf(300005);
ll sum[505][505], sum2[505][505];
ll l[300005], r[300005], u[300005], d[300005];
bool used[300005];
vector<ll> vec;

void insert(ll x)
{
	if(!used[x]){
		vec.push_back(x);
		used[x] = true;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(y, 1, n) rep(x, 1, n) cin >> c[x][y];
	
	rep(y, 1, n) rep(x, 1, n){
		if(c[x][y] == 'X') continue;
		rep(i, 0, 3){
			ll nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if(c[nx][ny] == 'X') continue;
			uf.unite(y*n+x, ny*n+nx);
		}
	}
	
	rep(y, 1, n) rep(x, 1, n){
		sum[x][y] = sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1];
		if(c[x][y] == 'X') sum[x][y]++;
	}
	
	rep(i, 1, 300000) l[i] = u[i] = inf, r[i] = d[i] = -inf;
	rep(y, 1, n) rep(x, 1, n){
		if(c[x][y] == 'X') continue;
		ll root = uf.root(y*n+x);
		chmin(l[root], x);
		chmax(r[root], x);
		chmin(u[root], y);
		chmax(d[root], y);
	}
	
	rep(y, 1, n) rep(x, 1, n){
		ll root = uf.root(y*n+x);
		if(c[x][y] == 'X' || root != y*n+x) continue;
		
		ll L = max(1LL, r[root]-k+2), R = min(n, l[root]-1);
		ll U = max(1LL, d[root]-k+2), D = min(n, u[root]-1);
		if(L > R || U > D) continue;
		//outl(L, R, U, D, uf.v[root]);
		sum2[L][U] += uf.v[root];
		sum2[R+1][U] -= uf.v[root];
		sum2[L][D+1] -= uf.v[root];
		sum2[R+1][D+1] += uf.v[root];
	}
	rep(y, 1, n) rep(x, 1, n) sum2[x][y] += sum2[x-1][y] + sum2[x][y-1] - sum2[x-1][y-1];
	
	ll ans = 0;
	rep(y, 1, n-k+1) rep(x, 1, n-k+1){
		
		vec.clear();
		rep(i, 0, k-1) if(c[x][y+i] == '.') insert(uf.root((y+i)*n+x));
		rep(i, 0, k-1) if(c[x+i][y] == '.') insert(uf.root(y*n+(x+i)));
		rep(i, 0, k-1) if(c[x+k-1][y+i] == '.') insert(uf.root((y+i)*n+(x+k-1)));
		rep(i, 0, k-1) if(c[x+i][y+k-1] == '.') insert(uf.root((y+k-1)*n+(x+i)));
		
		if(x-1 >= 1) rep(i, 0, k-1) if(c[x-1][y+i] == '.') insert(uf.root((y+i)*n+(x-1)));
		if(y-1 >= 1) rep(i, 0, k-1) if(c[x+i][y-1] == '.') insert(uf.root((y-1)*n+(x+i)));
		if(x+k <= n) rep(i, 0, k-1) if(c[x+k][y+i] == '.') insert(uf.root((y+i)*n+(x+k)));
		if(y+k <= n) rep(i, 0, k-1) if(c[x+i][y+k] == '.') insert(uf.root((y+k)*n+(x+i)));
		
		ll tmp = 0;
		for(auto x : vec) tmp += uf.v[x], used[x] = false;
		
		//outl(y, x, tmp, sum[x+k-1][y+k-1] - sum[x-1][y+k-1] - sum[x+k-1][y-1] + sum[x-1][y-1], sum2[x][y]);
		
		tmp += sum[x+k-1][y+k-1] - sum[x-1][y+k-1] - sum[x+k-1][y-1] + sum[x-1][y-1];
		tmp += sum2[x][y];
		chmax(ans, tmp);
	}
	outl(ans);
	
	return 0;
}