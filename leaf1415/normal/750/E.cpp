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
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string tostr(ll x){ string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(ret.begin(), ret.end()); return ret;}
ll toint(string &s){ ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
template<typename T>
void uniq(T &vec){ sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

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


struct Matrix{
	typedef llint T;
	
	int h, w;
	vector<T> mat;
	Matrix(){h = w = 0;}
	Matrix(int h, int w){
		this->h = h, this->w = w;
		mat.resize(h*w);
	}
	
	T addope(T a, T b){ return min(a, b); } //
	static T addIdent(){ return inf;} //
	T mulope(T a, T b){ return a+b; } //
	static T mulIdent(){ return 0; } //
	
	T& at(int i, int j){ return mat[w*(i-1)+(j-1)];}
	static Matrix Ident(int size){
		Matrix ret(size, size);
		for(int i = 1; i <= size; i++){
			for(int j = 1; j <= size; j++){
				if(i == j) ret.at(i, j) = mulIdent();
				else ret.at(i, j) = addIdent();
			}
		}
		return ret;
	}
	Matrix operator*(Matrix& ope){
		Matrix ret(h, ope.w);
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= ope.w; j++){
				ret.at(i, j) = addIdent();
				for(int k = 1; k <= w; k++){
					ret.at(i, j) = addope(ret.at(i, j), mulope(at(i, k), ope.at(k, j)));
				}
			}
		}
		return ret;
	}
	Matrix pow(llint n){
		if(n == 0) return Ident(h);
		if(n % 2) return pow(n-1) * (*this);
		else{
			Matrix tmp = pow(n/2);
			return tmp * tmp;
		}
	}
};
ostream& operator << (ostream& os, Matrix& mat) {
	for(int i = 1; i <= mat.h; i++){
		for(int j = 1; j <= mat.w; j++) os << mat.mat[mat.w*(i-1)+(j-1)] << " "; cout << endl;
	}
	return os;
}
ostream& operator << (ostream& os, const Matrix& mat) {
	for(int i = 1; i <= mat.h; i++){
		for(int j = 1; j <= mat.w; j++) os << mat.mat[mat.w*(i-1)+(j-1)] << " "; cout << endl;
	}
	return os;
}

struct SegTree{
	typedef Matrix SEG;
	
	int size;
	vector<SEG> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	SEG Ident(){  //identity element
		return Matrix::Ident(5);
	}
	SEG ope(SEG a, SEG b){ //operator
		return b * a;
	}
	
	void init(){
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	
	void update(int i, SEG val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}

	SEG query(int a, int b, int k, int l, int r)
	{
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

ll n, Q;
string s;
SegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	cin >> s, s = "#" + s;
	
	ll N = 1<<18;
	rep(i, 0, N-1) seg.seg[N+i] = Matrix::Ident(5);
	rep(i, 1, n){
		if(s[i] == '0') seg.seg[N+i].at(2, 2) = 1, seg.seg[N+i].at(3, 2) = 0;
		if(s[i] == '1') seg.seg[N+i].at(3, 3) = 1, seg.seg[N+i].at(4, 3) = 0;
		if(s[i] == '2') seg.seg[N+i].at(1, 1) = 1, seg.seg[N+i].at(2, 1) = 0;
		if(s[i] == '7') seg.seg[N+i].at(4, 4) = inf, seg.seg[N+i].at(5, 4) = 0;
		if(s[i] == '6') seg.seg[N+i].at(4, 4) = 1, seg.seg[N+i].at(5, 5) = 1;
	}
	per(i, N-1, 1) seg.seg[i] = seg.seg[2*i+1] * seg.seg[2*i];
	
	ll l, r;
	rep(i, 1, Q){
		cin >> l >> r;
		Matrix res = seg.query(l, r);
		if(res.at(5, 1) > inf/2) cout << -1 << "\n";
		else cout << res.at(5, 1) << "\n";
	}
	
	return 0;
}