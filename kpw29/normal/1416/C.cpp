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
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 300100;
int dr[maxn];

int n, m, tab[maxn];
int N;

int temp[maxn];

inline void add(int p, int val) {
	for (; p <= n; p += p & (-p)) dr[p] += val;
}

inline int get(int p) {
	if (p == 0) return 0;
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}


map <ll, ll> M;
vector <pair <int, int> > skal;
int cnt = 0;
ll inversions(int base) {
	if (M.find(base) != M.end()) return M[base];
	skal.resize(n);
	++cnt;
	FOR(i, 1, n) skal[i - 1] = make_pair(tab[i] ^ base, i);
	sort(skal.begin(), skal.end());
	for (int i=0; i<n; ++i) temp[skal[i].e2] = i + 1;
	
	ll res = 0;
	fill(dr, dr + n + 1, 0);
	for (int i=n; i>0; --i) {
		res += get(temp[i]);
		add(temp[i], 1);
	}
	
	M[base] = res;
	return res;
}

void solveone() {
	cin >> n;
	//n = 300000;
	FOR(i, 1, n) {
		cin >> tab[i];
		//tab[i] = i;
	}
	
	int b = 0;
	
	for (int bit = 29; bit >= 0; --bit) {
		if (inversions(b) > inversions(b + (1 << bit))) b += (1 << bit);
	}

	cout << inversions(b) << ' ' << b << "\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}