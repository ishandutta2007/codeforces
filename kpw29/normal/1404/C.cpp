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
const int R = (1 << 19);
vector <PII> zap[maxn];
int ans[maxn];

int n, m, tab[maxn];

int dr[maxn];

inline void add(int p, int val) {
	for (; p < maxn; p += p & (-p)) dr[p] += val;
}

inline int get(int p) {
	if (p == 0) return 0;
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}

inline int getSum(int x, int y) {
	return get(y) - get(x - 1);
}

PLL treemax[2 * R + 5];
ll dodaj[2 * R + 5];
int LOW, HIGH;

void push(int gdzie) {
	ll ile = dodaj[gdzie];
	dodaj[gdzie] = 0;
	treemax[2 * gdzie].e1 += ile;
	treemax[2 * gdzie + 1].e1 += ile;
	
	dodaj[2 * gdzie] += ile;
	dodaj[2 * gdzie + 1] += ile;
}

bool inrange(int value) {
	return LOW <= value && value <= HIGH;
}

void ustal(int gdzie) { //key fn
	if (!inrange(treemax[2 * gdzie].e2)) {
		treemax[gdzie] = treemax[2 * gdzie + 1];
		return;
	}
	if (!inrange(treemax[2 * gdzie + 1].e2)) {
		treemax[gdzie] = treemax[2 * gdzie];
		return;
	}
	//cout << "NEVER\n";
	//both in range
	if (treemax[2 * gdzie].e1 > treemax[2 * gdzie + 1].e1) {
		treemax[gdzie] = treemax[2 * gdzie];
		return;
	}
	else {
		treemax[gdzie] = treemax[2 * gdzie + 1];
		return;
	}
}

PII take() {
	return treemax[1];
}

void tree_insert(int gdzie, int pocz, int kon, int x, int y, ll dod) {
	if (x <= pocz && y >= kon) {
		treemax[gdzie].e1 += dod;
		dodaj[gdzie] += dod;
		if (pocz == kon) treemax[gdzie].e2 = pocz;
		return;
	}
	push(gdzie);
	int sr = (pocz + kon) / 2;
	if (x <= sr) tree_insert(2 * gdzie, pocz, sr, x, y, dod);
	if (y > sr) tree_insert(2 * gdzie + 1, sr + 1, kon, x, y, dod);
	ustal(gdzie);
}

void solveone() {
	cin >> n >> m;
	HIGH = n;
	FOR(i, 1, n) {
		cin >> tab[i];
		tab[i] -= i;
	}
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		zap[a + 1].push_back({n - b, i});
	}

	for (int i=n; i>0; --i) {
		LOW = i;
		tree_insert(1, 1, R, i, i, tab[i]);
		while (1) {
			PII choose = take();
			if (choose.e1 < 0) break;
			else if (choose.e1 == 0) {
				int x = choose.e2;
				//we can remove this thing
				add(x, 1);
				if (x != n) tree_insert(1, 1, R, x + 1, n, 1);
				tree_insert(1, 1, R, x, x, -inf);
			}
			else if (choose.e1 > 0) { //we don't want this item ever again
				int x = choose.e2;
				tree_insert(1, 1, R, x, x, -inf);
			}
		}
		
		for (auto pp : zap[i]) {
			int j = pp.e1, gdzie = pp.e2;
			ans[gdzie] = getSum(i, j);
		}
	}
	
	FOR(i, 1, m) cout << ans[i] << "\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}