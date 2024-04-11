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

const int maxn = 1000100;

vi v;
ll n, awp, pistol, all, dist, dp[maxn][2];
ll arr[maxn];

inline ll killOne(ll x) { //x monsters + boss
	ll awp_used = min(awp, pistol) * x + awp;
	return awp_used;
}

inline ll killLeavingOne(ll x) {
	return min(x * min(pistol, awp) + pistol, all);
}


void solveone() {
	cin >> n >> pistol >> all >> awp >> dist;
	ll cheapest_one = min(all, awp);
	cheapest_one = min(cheapest_one, pistol);
	
	FOR(i, 1, n) cin >> arr[i];
	
	FOR(i, 1, n) dp[i][0] = dp[i][1] = INF;
	dp[0][0] = -dist;
	dp[0][1] = INF;
	
	FOR(i, 1, n) {
		ll bst_start = min(dp[i-1][0] + dist, dp[i-1][1] + dist + dist); //skoczylismy o dwa
		//teraz na pewno jestesmy w i
		
		dp[i][0] = min(dp[i][0], bst_start + killOne(arr[i]));
		if (i > 1) {
			//cofamy sie do poprzedniego tak po prostu
			dp[i][0] = min(dp[i][0], bst_start + killLeavingOne(arr[i]) + dist + dist + cheapest_one);
		}
		
		//opcja numer dwa, robimy ten i nastepny od razu, czyli ustawiamy dp[i + 1][]
		
		if (i < n) {
			ll cost = bst_start + killLeavingOne(arr[i]) + dist;
			ll left_one = cost + killLeavingOne(arr[i + 1]);
			ll left_zero = cost + killOne(arr[i + 1]);
			
			
			dp[i + 1][1] = min(dp[i + 1][1], left_zero + dist + cheapest_one);
			dp[i + 1][1] = min(dp[i + 1][1], left_one + dist + cheapest_one + dist + cheapest_one + dist); //raczej nie
			
			dp[i + 1][0] = min(dp[i + 1][0], left_zero + dist + cheapest_one + dist);
			dp[i + 1][0] = min(dp[i + 1][0], left_one + dist + cheapest_one + dist + cheapest_one);
		}
		
		//debug(i, dp[i][0], dp[i][1], bst_start);
	}

	
	ll ret = min(dp[n][0], dp[n][1]);
	cout << ret << "\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}