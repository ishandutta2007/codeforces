#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+66;
 
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
//taken from UWarsaw template
 
// Works for POSITIVE integers up to 1e18
LL mul_bin(LL a, LL b, LL P) {
LL res = 0;
while (b) {
if (b % 2 == 1) { res = (res + a) % P; }
a = (a + a) % P;
b /= 2;
}
return res;
}
 
LL gcd(LL a, LL b, LL& x, LL& y){
if (a < b) return gcd(b, a, y, x);
if (b == 0) { x = 1; y = 0; return a; }
LL xp; LL pom = gcd(b, a % b, xp, x);
y = xp - x * (a / b);
return pom;
}
 
inline LL Adjust(LL a, LL mod) { return (a % mod + mod) % mod; }
	LL INF = 1e18;
	// Works for POSITIVE integers up to 1e18
	pair<LL, LL> nww(LL a, LL b, LL r1, LL r2) {
	r1 = Adjust(r1, a);
	r2 = Adjust(r2, b);
	LL x, y; LL d = gcd(a, b, x, y);
	x = Adjust(x, b);
	if (r1 % d != r2 % d) { return {-1, -1}; }
	if (a / d > INF / b + 2) { return {-1, -1}; }
	LL N = a / d * b;
	LL s = mul_bin(Adjust(r2 - r1, b) / d, x, b);
	LL new_r = (r1 + mul_bin(a, s, N)) % N;
	assert(new_r % a == r1 && new_r % b == r2);
	return {N, new_r};
}
 
// Elements of vec are equations of form x = p.second (mod p.first)
// If solution exists than this returns a pair (N, r) such that
// x = r (mod N); (1, 1) otherwise
// Works for POSITIVE integers up to 1e18
 
pair<LL, LL> CRT(vector<pair<LL, LL>>& vec) {
	LL N = 1, r = 0;
	for (auto& p : vec) {
		assert(p.e1 > 0 && p.e2 >= 0);
		pair<LL, LL> new_pair = nww(N, p.first, r, p.second);
		if (new_pair.first == -1) { return {-1LL, -1LL}; }
		N = new_pair.first; r = new_pair.second;
	}
	return {N, r};
}
 
const int maxn = 1000100;
int pos[maxn];
int pos2[maxn], maxx;
 
PLL solutions[maxn];
 
inline ll sufit(ll x, ll y ){
	if (x <= 0) return 0;
	if (x % y == 0) return x/y;
	return 1+x/y;
}
 
inline ll cnt(ll value) {
	ll ok_days = 0;
	for (int i=1; i<=maxx; ++i) {
		if (solutions[i] != make_pair(-1LL, -1LL)) {
			ok_days += sufit(value - solutions[i].e2 + 1, solutions[i].e1);
		}
	}
	
	return value - ok_days;
}
 
void solveone() {
	int n, m; ll k;
	cin >> n >> m >> k;
	maxx = 2 * max(n, m);
	FOR(i, 1, n) {
		int a;
		cin >> a;
		pos[a] = i;
	}
	
	FOR(i, 1, m) {
		int a;
		cin >> a;
		pos2[a] = i;
	}
	
	FOR(i, 1, maxx) {
		solutions[i] = {-1, -1};
		vector <PLL> eqs;
		if (pos2[i] != 0 && pos[i] != 0) {
			eqs.push_back({n, pos[i] % n});
			eqs.push_back({m, pos2[i] % m});
			solutions[i] = CRT(eqs);
			if (solutions[i].e2 == 0) solutions[i].e2 = solutions[i].e1;
			
			//debug(solutions[i]);
		}
	}
	
	//cout << cnt(3) << ' ' << cnt(4) << endl;
	
	ll x = 0, y = INF;
	while (x < y) {
		ll mid = (x + y) / 2;
		if (cnt(mid) < k) x = ++mid;
		else y = mid;
	}
	
	cout << x << "\n";
}
 
int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}