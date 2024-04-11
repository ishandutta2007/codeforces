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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;

const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
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

const int maxn = (1 << 22);

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, _;
int tab[maxn + 2];
int nodes[30], DL;
vector <int> takes;

int f(int x, int chron) {
	int dst = 2 * x;
	if (tab[dst + 1] > tab[dst]) dst++;
	
	if (chron >= 1 && tab[dst] == 0) return 0; //nie da sie
	nodes[DL++] = x;
	if (tab[x] == 0) return x;
	return f(dst, chron - 1);
}



void suck(int root, int chron) {
	if (tab[root] == 0) return;
	DL = 0;
	while (f(root, chron) != 0) {
		takes.pb(root);
		for (int i=0; i+1<DL; ++i) tab[nodes[i]] = tab[nodes[i + 1]]; //zawracamy
		if (DL > 0) assert(tab[nodes[DL - 1]] == 0);
		DL = 0;
	}
	
	suck(2 * root, chron - 1);
	suck(2 * root + 1, chron - 1);
}



int ist, des, n, g;

void solve() {
	cin >> n >> g;
	ist = (1 << n) - 1, des = (1 << g) - 1;
	FOR(i, 1, ist) cin >> tab[i], tab[2*i] = tab[2*i+1] = 0;
	takes = {};
	suck(1, g);
	
	ll res = 0;
	FOR(i, 1, des) res += tab[i];
	cout << res << "\n";
	assert((int)takes.size() >= ist - des);
	for (auto u : takes) cout << u << ' ';
	cout << "\n";
}



int main() {
	boost;
	cin >> T;
	while (T--) solve();
}