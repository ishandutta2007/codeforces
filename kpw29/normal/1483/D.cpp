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

const ll INF = 1e18;

const int maxn = 605;
bool useful[maxn][maxn];
ll dist[maxn][maxn];
vector <PII> triples[maxn];
bool good[maxn * maxn];
int n, m;
int A[maxn * maxn], B[maxn * maxn];
ll C[maxn * maxn];

ll BEST[maxn];

int main() {	
	cin >> n >> m;
	FOR(i, 1, n) {
		FOR(j, 1, n) dist[i][j] = INF;
	}
	
	FOR(i, 1, n) dist[i][i] = 0;
	FOR(i, 1, m) {
		ll a, b, c;
		cin >> a >> b >> c;
		A[i] = a; B[i] = b; C[i] = c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}
	
	FOR(k, 1, n)
	FOR(i, 1, n)
	FOR(j, 1, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	int que;
	cin >> que;
	FOR(i, 1, que) {
		int u, v, l;
		cin >> u >> v >> l;
		triples[u].pb({v, l});
		triples[v].pb({u, l});
	}
		
	FOR(u, 1, n) {
		FOR(i, 1, n) BEST[i] = -INF;
		for (auto tuple : triples[u]) {
			ll v = tuple.e1;
			ll l = tuple.e2;
			for (int b=1; b<=n; ++b) {
				BEST[b] = max(BEST[b], l - dist[b][v]);
			}
		}
		
		FOR(i, 1, m) {
			int a = A[i], b = B[i];
			ll con = dist[u][a] + C[i];
			
			if (con <= BEST[b]) good[i] = true;
		}
		
	}
	
	int res = 0;
	FOR(i, 1, m) res += good[i];
	cout << res << "\n";
}