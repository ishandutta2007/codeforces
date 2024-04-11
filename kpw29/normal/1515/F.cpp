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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 300200;

vector <PII> v[maxn];
vector <int> ans;
ll a[maxn], COST;
bool odw[maxn];
int f[maxn], n, m;
int A[maxn], B[maxn];

inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

inline void lacz(int x, int y, int kraw) {
	x = find(x); y = find(y);
	a[x] += a[y];
	assert(a[x] >= COST);
	a[x] -= COST;
	ans.pb(kraw);
	f[y] = x;
}

void dfs(int x) {
	if (odw[x]) return;
	odw[x] = 1;
	for (auto u : v[x]) {
		if (find(x) != find(u.e1) && a[find(x)] + a[find(u.e1)] >= COST) {
			lacz(x, u.e1, u.e2);
			dfs(u.e1);
		}
	}
}

void solveone() {
	cin >> n >> m >> COST;
	ll suma = 0;
	
	FOR(i, 1, n) {
		cin >> a[i];
		f[i] = i;
		suma += a[i];
	}
	
	FOR(i, 1, m) {
		int p, q;
		cin >> p >> q;
		v[p].pb({q, i});
		v[q].pb({p, i});
		
		A[i] =p; B[i] = q;
	}
	
	if (suma < COST * (n - 1)) {
		cout << "NO\n";
		return;
	}
	
	//otherwise it is possible
	vi order(n);
	FOR(i, 0, n-1) order.pb(i+1);
	random_shuffle(all(order));
	
	trav(i, order) {
		if (find(i) == i && a[i] >= COST) dfs(i);
	}
	
	//FOR(i, 1, n) assert(a[find(i)] < COST);
	
	// it is possible that some nodes are remaining, but greedy should work now...
	vi kraw(m);
	FOR(i, 0, m-1) kraw[i] = i + 1;
	
	while (clock() <= 2.5*CLOCKS_PER_SEC) {
		random_shuffle(kraw.begin(), kraw.end());
		FOR(kr, 0, m-1) {
			int i = kraw[kr];
			int p = A[i], q = B[i];
			if (find(p) == find(q)) continue;
			p = find(p); q = find(q);
			if (a[p] + a[q] >= COST) lacz(p, q, i);
		}
	}
	
	cout << "YES\n";
	for (auto u : ans) cout << u << "\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}