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


const int maxn = 1010;
const ll INF = 1e18;

inline void addmod(ll &x, ll val) {
	x += val;
	while (x >= mod) x -= mod;
}

ll dp[maxn][maxn][26];
ll suma[maxn][maxn];

string s1, s2;
int n, m;

ll blank_s1[maxn][26];
ll blank_s2[maxn][26];

ll sum_s1[maxn], sum_s2[maxn];

int main() {
	cin >> s1 >> s2;
	n = s1.length(), m = s2.length();
	s1 = "#" + s1;
	s2 = "$" + s2;
	
	ll res = 0;
	
	FOR(i, 1, n) {
		FOR(let, 0, 25) blank_s1[i][let] = 0;
		sum_s1[i] = 0;
		int cc = s1[i] - 'a';
		ll value = (sum_s1[i-1] - blank_s1[i-1][cc] + 1 + mod) % mod;
		blank_s1[i][cc] = value;
		addmod(sum_s1[i], value);
	}
	
	FOR(j, 1, m) {
		FOR(let, 0, 25) blank_s2[j][let] = 0;
			sum_s2[j] = 0;
			
			int cc = s2[j] - 'a';
			ll value = (sum_s2[j-1] - blank_s2[j-1][cc] + 1 + mod) % mod;
			blank_s2[j][cc] = value;
			addmod(sum_s2[j], value);
	}
	
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			// case 1: continuing both sequences	
			int c1 = s1[i] - 'a';
			if (i > 1) {
				ll value = (suma[i-1][j] - dp[i-1][j][c1] + mod) % mod;
				addmod(dp[i][j][c1], value);
				addmod(suma[i][j], value);
			}
			
			int c2 = s2[j] - 'a';
			if (j > 1) {
				ll value = (suma[i][j-1] - dp[i][j-1][c2] + mod) % mod;
				addmod(dp[i][j][c2], value);
				addmod(suma[i][j], value);
			}
			
			// case 2: I am adding a new string, can always do that
			
			ll xd = (sum_s2[j] - blank_s2[j][c1] + mod) % mod;
			addmod(dp[i][j][c1], xd);
			addmod(suma[i][j], xd);
			
			xd = (sum_s1[i] - blank_s1[i][c2] + mod) % mod;
			addmod(dp[i][j][c2], xd);
			addmod(suma[i][j], xd);
			
			FOR(let, 0, 25) res += dp[i][j][let];
		}
	}
	

		
	cout << res % mod << "\n";
	
}