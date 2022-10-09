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

const int maxn = 105;

int a[maxn], b[maxn];

int dp[2][101][100 * 100 + 5];
int res[maxn];
void solveone() {
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i] >> b[i];
	FOR(i, 0, 1)
		FOR(j, 0, n)
			FOR(k, 0, 10000) dp[i][j][k] = -inf;
			
	dp[0][0][0] = 0;
	FOR(i, 1, n) {
		int elem = a[i];
		FOR(j, 0, n) {
			for (int sum = 0; sum <= 10000; ++sum) {
				dp[i&1][j][sum] = dp[(i&1)^1][j][sum];
				if (j > 0 && sum >= elem) dp[i&1][j][sum] = max(dp[(i&1)^1][j - 1][sum - elem] + b[i] * 2, dp[i&1][j][sum]);
				dp[i&1][j][sum] = max(dp[i&1][j][sum], dp[(i&1)^1][j][sum] + b[i]);
			}
		}
	}
	
	FOR(k, 1, n)
		FOR(sum, 0, 10000) res[k] = max(res[k], min(2 * sum, dp[n&1][k][sum]));
	
	FOR(i, 1, n) cout << (double)res[i]/2.0 << ' ';
	
}

int main() {
	boost;
	cout << fixed << setprecision(15);
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}