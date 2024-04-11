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
const ll MOD = 1e9+696969;
#ifdef DEBUG
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
#endif
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
const int mod = 998244353;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 300100;

const int H = (1 << 19);

int tree[2 * H + 5];

vector <PPI> updates;

int pre[maxn], maxpre[maxn], n, WYNIK, DL, order[maxn];
vector <int> v[maxn], graph[maxn];
int parscore[maxn], R, kolejka;
int wynik[maxn];
int ojciec[maxn];
int depth[maxn];

void apply(int place, int co, int czas) {
	//debug("Aplikuje", place, co, czas);
	if (tree[place] < co) {
		updates.pb({{place, tree[place]}, czas});
		tree[place] = co;
	}
}

 
int cmp(int x, int y) {
	if (x == 0) return y;
	if (y == 0) return x;
	if (depth[x] > depth[y]) return x;
	return y;
}

int query(int x) {
	//debug("Pytam: ", x);
	x+= R-1;
	int result = tree[x];
	x /= 2;
	while (x) {
		result = cmp(result, tree[x]);
		x /= 2;
	}
	
	return result;
}

void set_max(int x, int y, int value, int czas) {
	if (x > y) return;
	//debug("Setting: ", x, y, value, czas);
	x += R-1; y += R-1;
	
	apply(x, value, czas);
	if (x == y) return;
	apply(y, value, czas);
	
	while (x + 1 < y) {
		if (!(x & 1)) apply(x+1, value, czas);
		if (y & 1) apply(y-1, value, czas);
		x /= 2; y /= 2;
	}
}



void prep(int x) {
	pre[x] = ++DL;
	maxpre[x] = pre[x];
	for (auto u : graph[x]) {
		depth[u] = 1 + depth[x];
		prep(u);
		maxpre[x] = max(maxpre[x], maxpre[u]);
	}
}

void dfs(int x, int treepar = 1) {
	order[x] = ++kolejka;
	ojciec[x] = query(pre[x]);
	
	debug(x, ojciec[x]);
	int sub = 0;
	if (ojciec[x] != 0) {
		if (pre[x] > pre[ojciec[x]]) {
			debug(x, ojciec[x]);
			if (parscore[ojciec[x]] == 0) ++sub;
			parscore[ojciec[x]]++;
			set_max(pre[x], maxpre[x], x, order[x]);
		}
		else {
			sub = 1;
			// NO SET MAX!!!!!!!!!!!!!!!
		}
	}
	else {
		set_max(pre[x], maxpre[x], x, order[x]);
	}
	
	// ustawiam max wszedzie
	wynik[x] = 1 + wynik[treepar] - sub;
	
	for (auto u : v[x]) {
		dfs(u, x);
	}
	
	while (!updates.empty() && updates.back().e2 >= order[x]) {
		PII rem = updates.back().e1;
		tree[rem.e1] = rem.e2;
		updates.pop_back();
	}
	
	if (ojciec[x] != 0 && pre[x] > pre[ojciec[x]]) {
		parscore[ojciec[x]]--;
	}
	
	WYNIK = max(WYNIK, wynik[x]);
}

int solve() {
	DL = 0; WYNIK = 0; kolejka = 0;
	cin >> n;
	R = 1;
	while (R < n) R *= 2;
	
	FOR(i, 1, n) {
		v[i].clear();
		depth[i] = 0;
		graph[i].clear();
		parscore[i] = 0;
		ojciec[i] = 0;
		wynik[i] = 0;
		pre[i] = 0; maxpre[i] = 0;
	}
	
	FOR(i, 2, n) {
		int xd;
		cin >> xd;
		v[xd].pb(i);
	}
	
	FOR(i, 2, n) {
		int xd;
		cin >> xd;
		graph[xd].pb(i);
	}
	
	prep(1);
	//FOR(i, 1, n) debug(pre[i], maxpre[i]);
	dfs(1);
	
	assert(updates.empty());
	FOR(i, 1, 2 * R) tree[i] = 0;
	return WYNIK;
}

int main() {
	boost;
	int t;
	cin >> t;
	while (t--) cout << solve() << "\n";
}