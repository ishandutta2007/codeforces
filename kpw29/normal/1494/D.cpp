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
 
const int maxn = 5010;
int tab[510][510];
int placa[maxn];
int highest[maxn], n;
bool jest[maxn];
vector <int> graf[maxn];
int f[maxn];

void dfs(int x, vector <int> &vec) {
	jest[x] = 1;
	vec.pb(x);
	for (auto u : graf[x]) {
		if (!jest[u]) dfs(u, vec);
	}
}
 
inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

void solveone() {
	cin >> n;
	map <int, vector <PII> > M;
	FOR(i, 0, maxn-1) f[i] = i, highest[i] = i;
	
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cin >> tab[i][j];
			M[tab[i][j]].push_back({i, j});
		}
	}
	
	int N = n;
	for (auto &u : M) {
		fill(jest, jest+N, true);
		int numer = u.e1;
		set <int> elems = {};
		for (auto &elem : u.e2) {
			if (elem.e1 == elem.e2) {
				placa[elem.e1] = numer;
			}
			else {
				if (elem.e1 != elem.e2) {
					elems.insert(find(elem.e1));
					elems.insert(find(elem.e2));
				}
			}
		}
		
		for (auto vv : elems) {
			graf[vv].clear();
			jest[vv] = false;
		}
		
		for (auto &elem : u.e2) {
			if (elem.e1 != elem.e2) {
				int a = find(elem.e1), b = find(elem.e2);
				graf[a].pb(b);
				graf[b].pb(a);
			}
		}
		
		debug(elems);
		
			vector <int> vec;
		for (auto vv : elems) {
			if (!jest[vv]) {
				vec = {};
				dfs(vv, vec);
				placa[++N] = numer;
				debug(vec);
				for (auto node : vec) {
					f[find(node)] = N;
					highest[node] = N;
				}
			}
		}
		
	}
	
	cout << N << "\n";
	FOR(i, 1, N - 1) cout << placa[i] << ' ';
	cout << placa[N] << "\n";
	cout << N << "\n";
	FOR(i, 1, N-1) cout << i << ' ' << highest[i] << "\n";
}
 
int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}