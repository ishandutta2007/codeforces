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
const ll dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

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
mint modpow(mint a, ll n){
	if(n <= 0) return mint(1);
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
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}

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
ostream& operator << (ostream& os, multiset<T>& set_var) {
	for(typename multiset<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
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

struct Matrix{
	int h, w;
	vector<llint> mat;
	Matrix(){
		h = w = 0;
	}
	Matrix(int h, int w){
		this->h = h, this->w = w;
		mat.resize(h*w);
	}
	llint& at(int i, int j){
		return mat[w*(i-1)+(j-1)];
	}
	static Matrix ident(int size){
		Matrix ret(size, size);
		for(int i = 1; i <= size; i++) ret.at(i, i) = 1;
		return ret;
	}
	Matrix operator*(Matrix& ope){
		Matrix ret(h, ope.w);
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= ope.w; j++){
				for(int k = 1; k <= w; k++){
					ret.at(i, j) += at(i, k) * ope.at(k, j) % mod;
					ret.at(i, j) %= mod;
				}
			}
		}
		return ret;
	}
	Matrix pow(llint n){
		if(n == 0) return ident(h);
		if(n % 2){
			return pow(n-1) * (*this);
		}
		else{
			Matrix tmp = pow(n/2);
			return tmp * tmp;
		}
	}
	void print(){
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				cout << at(i, j) << " ";
			}
			cout << endl;
		}
	}
};

ll n, m;
string s[10];
map<ll, P> mp;
map<P, ll> rmp;
P trans[45][10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> s[i];
	
	ll id = 1;
	rep(i, 1, n){
		reps(j, s[i]){
			mp[id] = P(i, j);
			rmp[P(i, j)] = id;
			id++;
		}
	}
	ll S = id-1;
	
	rep(i, 1, S){
		ll id = mp[i].first, pos = mp[i].second;
		rep(j, 1, n){
			string t = s[id].substr(pos), u = s[j];
			ll d = min(sz(t), sz(u)); bool flag = true;
			rep(k, 0, d-1){
				if(t[k] != u[k]){
					flag = false;
					break;
				}
			}
			if(!flag) continue;
			if(sz(t) == sz(u)) trans[i][j] = P(-1, d);
			if(sz(t) > sz(u)) trans[i][j] = P(rmp[P(id, pos+d)], d);
			if(sz(t) < sz(u)) trans[i][j] = P(rmp[P(j, d)], d);
		}
	}
	
	/*rep(i, 1, S){
		ll id = mp[i].first, pos = mp[i].second;
		rep(j, 1, n){
			if(trans[i][j].first == 0) continue;
			ll nid = mp[trans[i][j].first].first, npos = mp[trans[i][j].first].second;
			cout << s[id].substr(pos) << " " << s[j] << " " << s[nid].substr(npos) << " " << trans[i][j].second << endl;
		}
	}*/
	
	Matrix mat(5*S, 5*S);
	rep(j, 0, 3){
		rep(k, 1, S){
			mat.at((j+1)*S+k, j*S+k)++;
		}
	}
	rep(i, 1, S) rep(j, 1, n){
		ll to = trans[i][j].first, tm = trans[i][j].second;
		if(to == 0) continue;
		if(to == -1){
			rep(k, 1, n){
				mat.at(rmp[P(k, 0)], i+(tm-1)*S)++;
			}
			continue;
		}
		mat.at(to, i+(tm-1)*S)++;
	}
	
	Matrix pmat = mat.pow(m);
	
	ll ans = 0;
	rep(i, 1, n) ans += pmat.at(1, rmp[P(i, 0)]), ans %= mod;
	outl(ans);
	
	return 0;
}