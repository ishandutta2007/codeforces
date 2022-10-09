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
const int mod = 1e9+7;
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
ll n, m;
int f[maxn];
vector <int> graph[maxn];
int sz[maxn], sajz[maxn];
inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

void solveone() {
	cin >> n >> m;
	FOR(i, 1, m) f[i] = i, sajz[i] = 1;
	vector <int> v;
	
	FOR(i, 1, n) {
		cin >> sz[i];
		FOR(j, 0, sz[i]-1) {
			int p;
			cin >> p;
			graph[i].pb(p);
		}
		
		int a = graph[i][0], b;
		if (sz[i] == 1) b = 0;
		else b = graph[i][1];
		
		int fa = find(a), fb = find(b);
		if (fa != fb) {
			v.pb(i);
			sajz[fb] += sajz[fa];
			f[fa] = fb;
		}
	}
	
	ll dwum = 1;
	FOR(i, 0, m) {
		if (find(i) == i) {
			if (sajz[i] == 0) continue;
			FOR(step, 1, sajz[i] - 1) dwum = (dwum * 2 % mod);
			if (find(i) == find(0)) {
				dwum = (dwum * 2) % mod;
			}
		}
	}
	
	cout << dwum << ' ' << v.size() << "\n";
	sort(v.begin(), v.end());
	for (auto u : v) cout << u << ' '; 
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}