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

const int maxn = 300100;
bool odw[maxn];
int val[maxn];
vector <PII> v[maxn];
int toparent[maxn];
int parent[maxn];
int ans = -1;

vector <int> edges;

void dfs(int x) {
	odw[x] = 1;
	trav(u, v[x]) {
		if (!odw[u.e1]) {
			parent[u.e1] = x;
			toparent[u.e1] = u.e2;
			dfs(u.e1);
		}
	}
	
	if (val[x] == 1) {
		if (parent[x] == 0) OUT(-1);
		
		int node = parent[x];
		val[x] ^= 1;
		if (val[node] != -1) {
			val[node] ^= 1;
		}
		
		edges.pb(toparent[x]);
	}
	
}

void solveone() {
	int n, m;
	cin >> n >> m;
	vector <int> nonzero, zero;
	int negative = -1;
	FOR(i, 1, n) {
		cin >> val[i];
		if (val[i] == -1) negative = i;
	}
	
	
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb({b, i});
		v[b].pb({a, i});
	}
	
	//FOR(i, 1, n) debug(i, val[i]);
	if (negative != -1) dfs(negative);
	else dfs(1);
	
	sort(all(edges));
	cout << (int)edges.size() << endl;
	trav(u, edges) cout << u << ' ';
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		solveone();
		//cout << (solveone() ? "YES\n" : "NO\n");
	}
}