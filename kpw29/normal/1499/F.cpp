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
const int mod = 998244353;

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


const int maxn = 5010;
const ll INF = 1e18;

int sz[maxn], n, k;

ll dp[maxn][maxn];
vector <int> v[maxn];
ll tmp[maxn];
ll ndp[maxn];

inline void addmod(ll &x, ll val) {
	x += val;
	while (x >= mod) x -= mod;
}

void dfs(int x, int par=1) {
	sz[x] = 1;
	for (auto u : v[x]) {
		if (u != par) {
			dfs(u, x);
			sz[x] += sz[u];
		}
	}
	
	int smax = 0;
	FOR(j, 0, sz[x]) tmp[j] = 0;
	tmp[0] = 1; //one way to do zero
	for (auto u : v[x]) {
		if (u != par) {
			FOR(i, 0, smax + sz[u]) ndp[i] = 0;
			
			for (int f1=0; f1<=smax; ++f1) {
				for (int f2=0; f2+f1<=k && f2 <= sz[u]; ++f2) {
					addmod(ndp[max(f1, f2)], tmp[f1] * dp[u][f2] % mod);
				}
			}
			
			smax += sz[u];
			FOR(i, 0, smax) tmp[i] = ndp[i];
		}
	}
	
	//moving tmp to dp[u]; cutting edge
	for (int i=0; i<=sz[x]; ++i) addmod(dp[x][0], tmp[i]);
	
	//other choice:this edge stays (only if x != 1)
	
	if (x != 1) {
		for (int i=0; i<=sz[x]; ++i) addmod(dp[x][i + 1], tmp[i]);
	}
}

int main() {
	boost;
	cin >> n >> k;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1);
	
	ll res = 0;
	for (int i=0; i<=k; ++i) res = res + dp[1][i];
	cout << (res % mod);
}