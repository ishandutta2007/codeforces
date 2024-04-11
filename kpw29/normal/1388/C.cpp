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
typedef pair <PLL, PLL > PP;
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

const int maxn = 1001010;
int n, m;


vector <int> values;

ll h[maxn], ile[maxn];
ll total[maxn], count_good[maxn], req_good[maxn];
bool answer;
vector <int> v[maxn];

void dfs(int x, int par = -1) {
	total[x] = ile[x]; //ile mieszka
	for (auto u : v[x])
		if (u != par) {
			dfs(u, x);
			total[x] += total[u];
		}
}

void check(int x, int par = -1) {
	for (auto u : v[x])
		if (u != par) {
			check(u, x);
			count_good[x] += req_good[u];
		}
	
	if (req_good[x] < count_good[x]) answer = false;
}

void solveone() {
	cin >> n >> m;
	FOR(i, 1, n) cin >> ile[i];
	FOR(i, 1, n) cin >> h[i], req_good[i] = 0, total[i] = 0, count_good[i] = 0;
	answer = true;
	FOR(i, 1, n) v[i].clear();
	
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1);
	FOR(i, 1, n) {
		ll good = h[i] + total[i];
		if (good % 2 != 0 || good < 0) answer = false;
		else req_good[i] = good / 2;
		if (req_good[i] > total[i]) answer = false;
	}
	check(1);
	
	/*debug("req");
	FOR(i, 1, n) cout << req_good[i] << ' ';
	cout << endl;
	FOR(i, 1, n) cout << total[i] << ' ';*/
	
	if (answer) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	boost;
	int tests;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}