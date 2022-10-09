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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;

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

const int maxn = 100002;

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

int n, m, k, d, tab[maxn];

vector <PII> v;

vector <int> ch[maxn], graf[maxn];
int TIME = 0, ANS;

void rob(int x) {
	v.push_back(mp(x, TIME));
	++TIME;
	if (TIME > ANS && (x != 1)) {
		int dist = ANS - (int)graf[x].size();
		TIME = dist;
		v.pb(mp(x, TIME));
		++TIME;
	}
}

void dfs(int x, int par) {
	int start_time = TIME;
	rob(x);
	for (auto u : graf[x]) {
		if (u != par) {	
			dfs(u, x);
			rob(x);
		}
	}
	
	if (x != 1 && TIME != start_time) {
		v.push_back(mp(x, start_time - 1));
		TIME = start_time;
	}
}

int jest[maxn];
set <int> s[maxn];

bool check() {
	for (auto u : v) jest[u.e1]++;
	FOR(i, 1, n)
		if (!jest[i]) return false;
	
	if (v.back().e1 != 1) return false;
	if (v[0].e1 != 1) return false;
	
	for (auto u : v) {
		if (s[u.e1].find(u.e2) != s[u.e1].end()) return false;
		s[u.e1].insert(u.e2);
	}
	
	return true;
}

int main() {
	boost;
	cin >> n;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}

	ANS = 0;
	FOR(i, 1, n) ANS = max(ANS, (int)graf[i].size());
	
	dfs(1, 1);
	
	cout << v.size() << endl;
	for (auto u : v) cout << u.e1 << ' ' << u.e2 << "\n";
	
	//assert(check());
}