#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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

const int maxn = 1000100;
ll n, m, k;
int tab[maxn];
int ile[maxn];

int MIN[maxn];


vector <int> rozloz(int x) {
	vector <int> v = {};
	while (x > 1) {
		debug(x);
		int dv = MIN[x], ile = 0;
		while (x % dv == 0) {
			x /= dv;
			++ile;
		}
		
		if (ile & 1) v.push_back(dv);
	}
	
	return v;
}

int max_zero, max_one;


void solveone() {
	cin >> n;
	map <vector <int>, int> M;
	max_zero = 0; max_one = 0;
	FOR(i, 1, n) cin >> ile[i];
	FOR(i, 1, n) {
		int a = ile[i];
		vector <int> ok = rozloz(a);
		M[ok]++;
		max_zero = max(max_zero, M[ok]);
	}	
	
	int zerowe = 0;
	for (auto &u : M) {
		int il = u.e2;
		if (u.e1.empty()) {
			zerowe += u.e2;
			continue;
		}
		
		if (il % 2 == 1) max_one = max(max_one, il);
		else zerowe += il;
	}
	
	max_one = max(max_one, zerowe);
	
	int q;
	cin >> q;
	while (q--) {
		ll xd;
		cin >> xd;
		if (xd >= 1) cout << max_one << "\n";
		else cout << max_zero << "\n";
	}
}

int main() {
	boost;
	MIN[1] = 1;
	FOR(i, 2, maxn-1)
		for (int j=i; j<maxn; j+=i)
			if (MIN[j] == 0) MIN[j] = i;
	
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}