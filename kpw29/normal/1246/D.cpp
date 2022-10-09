#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
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


const int maxn = 100100;
int n, m;


int p[maxn], par[maxn];
vector <int> v[maxn];
int SZ[maxn];

bool cmp(int a, int b) {
	if (SZ[a] != SZ[b]) return SZ[a] < SZ[b];
	return a < b;
}

void dfs(int x) {
	SZ[x] = 1;
	for (auto u : v[x]) {
		dfs(u);
		SZ[x] = max(SZ[x], SZ[u] + 1);
	}

	sort(v[x].begin(), v[x].end(), cmp);
}
vector <int> opt;

void kol(int x) {
	opt.pb(x);
	for (auto u : v[x]) kol(u);
}

vector <int> wyn;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n-1) {
		cin >> par[i];
		v[par[i]].pb(i);
	}
	
	dfs(0);
	kol(0);
	for (auto u : opt) cout << u << ' ';
	cout << endl;
	
	for (int i=1; i<n; ++i) p[opt[i]] = opt[i-1];
	for (int i=1; i<n; ++i) {
		int u = opt[i];
		while (p[u] != par[u]) {
			wyn.pb(u);
			int tp = p[u];
			p[u] = p[tp];
		}
	}
	
	cout << (int)wyn.size() << endl;
	for (auto u : wyn) cout << u << ' ';
}