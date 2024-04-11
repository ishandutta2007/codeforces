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
#define inf 1e9
#define eps 1e-9
const double PI = 3.1415926535897932384626433;

using namespace std;

typedef int ll;
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


struct DisjointSparseTable{
	typedef ll T;
	
	int size;
	vector<vector<T> > vec;
	vector<int> msb;
	
	T Ident(){return inf;}  //
	T ope(T a, T b){return min(a, b);} //
	
	DisjointSparseTable(){}
	DisjointSparseTable(int size){
		this->size = size;
		vec.resize(size);
		for(int i = 0; i < size; i++) vec[i].resize(1<<size);
		for(int i = 0; i < (1<<size); i++) vec[0][i] = Ident();
		msb.resize((1<<size));
		for(int i = 2; i < (1<<size); i++) msb[i] = msb[i>>1]+1;
	}
	void set(int i, T val){
		vec[0][i] = val;
	}
	void calc(){
		for(int i = 1; i < size; i++){
			int b = 1<<i;
			for(int j = 0; j < (1<<size); j++){
				if(j & b){
					if(j % b) vec[i][j] = ope(vec[i][j-1], vec[0][j]);
					else vec[i][j] = vec[0][j];
				}
			}
			for(int j = (1<<size)-1; j >= 0; j--){
				if((j & b) == 0){
					if((j+1) % b) vec[i][j] = ope(vec[0][j], vec[i][j+1]);
					else vec[i][j] = vec[0][j];
				}
			}
		}
	}
	T query(int l, int r)
	{
		if(l > r) return Ident();
		if(l == r) return vec[0][l];
		int k = msb[l^r];
		return ope(vec[k][l], vec[k][r]);
	}
};

struct BIT{
	typedef ll T;
	T Ident(){ return 0; }//
	T ope(T a, T b){ return a+b; } //
	
	int size;
	vector<T> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+2);
		init();
	}
	void init(){
		for(int i = 1; i <= size+1; i++) bit[i] = Ident();
	}
	T query(int i){
		i++;
		T ret = 0;
		while(i > 0){
			ret = ope(ret, bit[i]);
			i -= i&(-i);
		}
		return ret;
	}
	T query(int l, int r){
		if(l > r) return Ident();
		return query(r) - query(l-1);
	}
	void add(int i, T x){
		i++;
		while(i <= size+1){
			bit[i] = ope(bit[i], x);
			i += i&(-i);
		}
	}
};

struct StaticRectangleSum{
	typedef pair<P, P> Query;
	typedef pair<P, ll> Point;
	
	vector<Point> pvec;
	vector<Query> qvec;
	vector<ll> avec;
	int qid;
	
	StaticRectangleSum(){
		init();
	}
	void init(){
		pvec.clear();
		qvec.clear();
		avec.clear();
		qid = 0;
	}
	void addPoint(ll x, ll y, ll w){
		pvec.push_back(Point(P(x, y), w));
	}
	int addQuery(ll sx, ll sy, ll tx, ll ty)
	{
		qvec.push_back(Query(P(tx, ty), P(qid, 1)));
		qvec.push_back(Query(P(sx-1, sy-1), P(qid, 1)));
		qvec.push_back(Query(P(tx, sy-1), P(qid, -1)));
		qvec.push_back(Query(P(sx-1, ty), P(qid, -1)));
		return qid++;
	}
	void calc()
	{
		vector<ll> xcomp, ycomp;
		for(auto p : pvec){
			xcomp.push_back(p.first.first);
			ycomp.push_back(p.first.second);
		}
		for(auto q : qvec){
			xcomp.push_back(q.first.first);
			ycomp.push_back(q.first.second);
		}
		sort(xcomp.begin(), xcomp.end());
		xcomp.erase(unique(xcomp.begin(), xcomp.end()), xcomp.end());
		sort(ycomp.begin(), ycomp.end());
		ycomp.erase(unique(ycomp.begin(), ycomp.end()), ycomp.end());
		
		ll w = xcomp.size(), h = ycomp.size();
		
		vector<vector<P>> Pvec(w);
		vector<vector<Query>> Qvec(w);
		for(auto p : pvec){
			ll x = lower_bound(xcomp.begin(), xcomp.end(), p.first.first) - xcomp.begin();
			ll y = lower_bound(ycomp.begin(), ycomp.end(), p.first.second) - ycomp.begin();
			Pvec[x].push_back(P(y, p.second));
		}
		for(auto q : qvec){
			ll x = lower_bound(xcomp.begin(), xcomp.end(), q.first.first) - xcomp.begin();
			ll y = lower_bound(ycomp.begin(), ycomp.end(), q.first.second) - ycomp.begin();
			Qvec[x].push_back(Query(P(x, y), q.second));
		}
		
		BIT bit(h);
		
		avec.resize(qid);
		for(auto &x: avec) x = 0;
		for(int i = 0; i < w; i++){
			for(auto p : Pvec[i]) bit.add(p.first, p.second);
			for(auto q : Qvec[i]) avec[q.second.first] += q.second.second * bit.query(q.first.second);
		}
	}
	ll getAnswer(int qid)
	{
		return avec[qid];
	}
};

//init(vector<ll> s)sa[0..|s|]lcp[0..|s|-1]sa[0]=|s|

struct SuffixArray{
	vector<ll> sa, lcp, rank;
	
	SuffixArray(){}
	SuffixArray(vector<ll> s){init(s);}
	
	void init(vector<ll> s){
		sa.clear(), lcp.clear();
		sa_is(s, sa);
		makeLCP(s, sa, lcp);
	}
	
	void induced_sort(vector<ll> &s, vector<ll> &type, vector<ll> &seed, vector<ll> &sa)
	{
		int n = s.size();
		for(int i = 0; i < n; i++) sa[i] = -1;
		
		ll A = 0; //A
		for(int i = 0; i < n-1; i++) chmax(A, s[i]);
		
		vector<ll> num(A+1), lpos(A+1), rpos(A+1), rpos2(A+1); //
		for(int i = 0; i < n-1; i++) num[s[i]]++;
		int sum = 0;
		for(int i = 0; i <= A; i++) lpos[i] = sum+1, sum += num[i], rpos[i] = rpos2[i] = sum;
		
		for(int i = (int)seed.size()-1; i >= 0; i--){  //seedLMS
			ll p = seed[i];
			if(s[p] == -1) sa[0] = p;
			else sa[rpos[s[p]]--] = p;
		}
		for(int i = 0; i < n; i++) if(sa[i] != -1 && sa[i] > 0 && type[sa[i]-1] == 1) sa[lpos[s[sa[i]-1]]++] = sa[i]-1; //L
		for(int i = n-1; i >= 0; i--) if(sa[i] > 0 && type[sa[i]-1] == 0) sa[rpos2[s[sa[i]-1]]--] = sa[i]-1; //S
	}

	void sa_is(vector<ll> s, vector<ll> &sa) 
	{
		s.push_back(-1);
		int n = s.size();
		sa.resize(n);
		
		if(n <= 2){
			for(int i = 0; i < n; i++) sa[i] = (n-1)-i;
			return;
		}
		
		vector<ll> type(n), lms;
		vector<vector<ll> > str(n);
		
		type[n-1] = 0; //LS
		for(int i = n-2; i >= 0; i--){
			if(s[i] < s[i+1]) type[i] = 0;
			else if(s[i] > s[i+1]) type[i] = 1;
			else type[i] = type[i+1];
		}
		for(int i = 1; i < n; i++) if(type[i] == 0 && type[i-1] == 1) lms.push_back(i); //LMS
		
		for(int i = 0; i < (int)lms.size()-1; i++){ //LMS
			ll l = lms[i], r = lms[i+1];
			for(int j = l; j <= r; j++) str[l].push_back(s[j]);
		}
		str[n-1].push_back(s[n-1]);
		
		induced_sort(s, type, lms, sa); //seedinduced sort
		
		ll id = 0; vector<ll> tmp, order(n);  //SALMS
		for(int i = 0; i < n; i++) if(str[sa[i]].size()) tmp.push_back(sa[i]);
		order[tmp[0]] = id;
		for(int i = 1; i < tmp.size(); i++){ 
			if(str[tmp[i-1]] != str[tmp[i]]) id++;
			order[tmp[i]] = id;
		}
		
		vector<ll> s2, sa2;
		for(int i = 0; i < lms.size(); i++) s2.push_back(order[lms[i]]); //LMSSAseed
		sa_is(s2, sa2);
		vector<ll> seed;
		for(int i = 1; i < sa2.size(); i++) seed.push_back(lms[sa2[i]]);
		
		induced_sort(s, type, seed, sa); //seedinduced sort
	}

	//lcp[i] = LCP(s.substr(sa[i]), s.substr(sa[i+1]))
	void makeLCP(vector<ll> s, vector<ll> sa, vector<ll> &lcp)
	{
		int n = s.size();
		rank.resize(n+1);
		for(int i = 0; i <= n; i++) rank[sa[i]] = i;
		lcp.resize(n);
		
		int h = 0;
		lcp[0] = 0;
		for(int i = 0; i < n; i++){
			int j = sa[rank[i]-1];
			while(i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
			lcp[rank[i]-1] = h;
			if(h > 0) h--;
		}
	}
};

ll n, Q;
string s[200005];
ll pos[200005];
SuffixArray sa;
StaticRectangleSum srs;
ll qid[500005];
DisjointSparseTable sp(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> s[i];
	
	vector<ll> vec;
	rep(i, 1, n){
		pos[i] = sz(vec);
		vec.pb(100000+i);
		for(auto c : s[i]) vec.pb(c);
	}
	pos[n+1] = sz(vec);
	
	ll L = sz(vec);
	sa.init(vec);
	rep(i, 0, L) sa.rank[sa.sa[i]] = i;
	
	rep(i, 0, L-1) sp.set(i, sa.lcp[i]);
	sp.calc();
	rep(i, 0, L) srs.addPoint(i, L-sa.sa[i]+1, 1);
	
	/*rep(i, 0, L){
		cout << i << " ";
		rep(j, sa.sa[i], L-1) cout << vec[j] << " "; cout << endl;
	}*/
	
	ll l, r, k;
	rep(i, 1, Q){
		cin >> l >> r >> k;
		ll p = sa.rank[pos[k]+1], lx, rx;
		
		ll ub = p, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(sp.query(mid, p-1) >= sz(s[k])) ub = mid;
			else lb = mid;
		}
		lx = ub;
		
		ub = L+1, lb = p, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(sp.query(p, mid-1) >= sz(s[k])) lb = mid;
			else ub = mid;
		}
		rx = lb;
		
		ll ly = L-pos[r+1]+1, ry = L-pos[l]+1;
		qid[i] = srs.addQuery(lx, ly, rx, ry);
	}
	
	srs.calc();
	rep(i, 1, Q) cout << srs.getAnswer(qid[i]) << "\n";

	return 0;
}