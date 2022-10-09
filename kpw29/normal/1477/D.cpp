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

const int maxn = 500100;
ll n, m, k;
int tab[maxn];

vector <int> v[maxn];
int best[maxn];

int p[maxn], q[maxn];
vector <int> edges[maxn];
int special[maxn];

vector <int> block[maxn];

void dfs(int x) {
	int sum = 0;
	for (auto u : edges[x]) {
		dfs(u);
		sum += (1 - special[u]);
	}
	
	if (sum > 0) {
		special[x] = 1;
		block[x].push_back(x);
		for (auto u : edges[x]) {
			if (!special[u]) block[x].push_back(u);
		}
	}
}

void solveone() {
	cin >> n >> m;
	FOR(i, 1, n) best[i] = -1, v[i].clear(), edges[i].clear(), block[i].clear(), special[i] = 0;
	
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	FOR(i, 1, n) {
		sort(v[i].begin(), v[i].end());
		v[i].push_back(n + 1);
		int nast = 1;
		best[i] = -1;
		for (auto item : v[i]) {
			if (nast == i) ++nast;
			
			if (item != nast) {
				best[i] = nast;
				break;
			}
			++nast;
		}
	}
	
	int END = n;
	FOR(i, 1, n)
		if (best[i] == -1) {
			p[i] = END;
			q[i] = END;
			--END;
		}
	
	FOR(i, 1, n) debug(best[i]);
	
	vector <int> roots = {};

	FOR(i, 1, n)
		if (best[i] != -1) {
			int nei = best[i];
			if (best[nei] == i) { // a loop
				if (i < nei) {
					roots.push_back(i);
					edges[i].push_back(nei);
					debug("edge", i, nei);
				}
			}
			else {
				edges[nei].push_back(i);
				debug("edge", nei, i);
			}
		}
	debug(roots);
		
	int LAST = 0;
	for (auto u : roots) {
		dfs(u);
		if (!special[u]) block[edges[u][0]].push_back(u);
	}
	FOR(i, 1, n) debug(i, block[i]);
	
	FOR(i, 1, n) {
		if (best[i] == -1 || block[i].empty()) continue;
		int LEN = block[i].size();
		for (int j=0; j<LEN; ++j) {
			p[block[i][j]] = LAST + j + 1;
		}
		
		for (int j=0; j<LEN; ++j) {
			q[block[i][j]] = LAST + j;
		}
		
		LAST += LEN;
		q[block[i][0]] = LAST;
	}
	
	FOR(i, 1, n) cout << p[i] << ' ';
	cout << endl;
	FOR(i, 1, n) cout << q[i] << ' ';
	cout << endl;
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}