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
mt19937_64 rng(time(0));
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
const int maxn = 200100;

int dr[maxn];
void add(int p, int v) {
	for (; p < maxn; p += p & (-p)) dr[p] += v;
}

int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}
int n, m, q;
int perm[maxn], gdzie[maxn];
vector <PII> queries[maxn];
vector <int> avail[maxn];

bool odp[maxn];
int tab[maxn];

int ost[maxn];
int skok[20][maxn];


void solve() {
	cin >> n >> m >> q;
	FOR(i, 1, n) {
		cin >> perm[i];
		gdzie[perm[i]] = i;
	}
	
	FOR(i, 1, m) cin >> tab[i];
	FOR(i, 1, n) ost[i] = m + 1;
	rep(pt, 0, 20) skok[pt][m + 1] = m + 1;
	
	for (int i=m; i>0; --i) {
		int elem = tab[i];
		int in_p = gdzie[elem];
		if (in_p == n) in_p = 1;
		else in_p++;
		
		int what_number = perm[in_p];
		skok[0][i] = ost[what_number];
		for (int j=1; j<20; ++j) skok[j][i] = skok[j-1][skok[j-1][i]];
		ost[elem] = i;
		
		int x = i;
		int k = n - 1;
		for (int j=0; j<20; ++j) {
			if (k & (1 << j)) x = skok[j][x];
		}
		
		avail[x].pb(i);
	}
	
	FOR(i, 1, q) {
		int a, b;
		cin >> a >> b;
		queries[b].pb({a, i});
	}
	
	FOR(i, 1, m) {
		for (auto av : avail[i]) add(av, 1);
		for (auto query : queries[i]) {
			int g = get(i) - get(query.e1 - 1);
			
			odp[query.e2] = (g > 0);
		}
	}
	
	FOR(i, 1, q) cout << odp[i];
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}