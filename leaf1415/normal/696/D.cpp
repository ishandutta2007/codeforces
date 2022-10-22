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


struct AhoCorasick{
	struct TrieNode{
		int num, sum;
		int next[26], suff;
		TrieNode(){
			num = sum = 0;
			for(int i = 0; i < 26; i++) next[i] = -1;
		}
	};
	vector<TrieNode> trie;
	
	AhoCorasick(){
		init();
	}
	void init(){
		trie.clear();
		trie.push_back(TrieNode());
	}
	int seek(string &s)
	{
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'a';
			if(trie[p].next[c] == -1){
				trie.push_back(TrieNode());
				trie[p].next[c] = (int)trie.size()-1;
			}
			p = trie[p].next[c];
		}
		return p;
	}
	
	int trans(int v, int c)
	{
		if(trie[v].next[c] != -1) return trie[v].next[c];
		if(v == 0) return 0;
		return trans(trie[v].suff, c);
	}
	
	void addString(string &s, int x = 1)
	{
		int p = seek(s);
		trie[p].num += x;
	}
	
	void makeSuffixLink()
	{
		queue<int> Q;
		Q.push(0);
		trie[0].suff = 0;
		
		int v;
		while(Q.size()){
			v = Q.front();
			Q.pop();
			trie[v].sum = trie[v].num + trie[trie[v].suff].sum;
			for(int i = 0; i < 26; i++){
				int u = trie[v].next[i];
				if(u == -1) continue;
				trie[u].suff = trans(trie[v].suff, i);
				if(v == 0) trie[u].suff = 0;
				Q.push(u);
			}
		}
	}
};


struct Matrix{
	typedef llint T;
	
	int h, w;
	vector<T> mat;
	Matrix(){h = w = 0;}
	Matrix(int h, int w){
		this->h = h, this->w = w;
		mat.resize(h*w);
	}
	
	T addope(T a, T b){ return max(a, b); } //
	static T addIdent(){ return -inf;} //
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
	Matrix operator+(Matrix& ope){
		Matrix ret(h, w);
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				ret.at(i, j) = at(i, j) + ope.at(i, j);
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

ll n, l;
ll a[205];
string s[205];
AhoCorasick aho;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> l;
	
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> s[i], aho.addString(s[i], a[i]);
	aho.makeSuffixLink();
	ll S = aho.trie.size();
	
	Matrix mat(S, S);
	rep(i, 0, S-1) rep(j, 0, S-1) mat.at(i+1, j+1) = -inf;
	rep(i, 0, S-1){
		rep(j, 0, 25){
			ll ni = aho.trans(i, j);
			mat.at(ni+1, i+1) = aho.trie[ni].sum;
		}
	}
	
	Matrix pmat = mat.pow(l);
	ll ans = -inf;
	rep(i, 0, S-1) chmax(ans, pmat.at(i+1, 1));
	outl(ans);
	
	return 0;
}