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

const int maxn = 200100;
vector <int> v[maxn];
int dp[maxn], n;
bool OK = 1;

void dfs(int x, int par, int kk) {
	vector <int> ch;
	for (auto u : v[x])
		if (u != par) {
			dfs(u, x, kk);
			ch.push_back(dp[u]);
		}
	
	if (ch.empty()) dp[x] = 0;
	else {
		int sz = ch.size();
		vector <int> pref(sz + 2), suf(sz + 2);
		
		pref[0] = suf[sz + 1] = -2;
		for (int i=1; i<=sz; ++i) {
			pref[i] = max(pref[i-1], ch[i - 1]);
		}
		
		for (int i=sz; i>0; --i) {
			suf[i] = max(suf[i+1], ch[i - 1]);
		}
		
		dp[x] = inf;
		for (int i=1; i<=ch.size(); ++i) {
			if (pref[i - 1] + 2 <= kk && suf[i + 1] + 2 <= kk) {
				dp[x] = min(dp[x], ch[i - 1] + 1);
			}
		}

		if (dp[x] > kk) OK = 0;
		else if (dp[x] == kk && x > 1) OK = 0;
	}
	
}

bool check(int k) {
	OK = 1;
	dfs(1, 1, k);
	FOR(i, 1, n) debug(i, dp[i]);
	return OK;
}

void solveone() {
	cin >> n;
	FOR(i, 1, n) v[i].clear();
	
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	int xx = 1, yy = n;
	while (xx < yy) {
		int mid = (xx + yy) / 2;
		if (!check(mid)) xx = ++mid;
		else yy = mid;
	}
	
	cout << xx << "\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}