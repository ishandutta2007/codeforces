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
int n, m, k;

int dp[maxn][2];
bool suffix[maxn];

int main() {
	boost;
	string s;
	cin >> s;
	n = s.size();
	for (int i=0; i<n; ++i) {
		if (s[i] == '1' && s[(i+1)%n] == '0') {
			string w = "";
			for (int j=i+1; j<n; ++j) w += s[j];
			for (int j=0; j<=i; ++j) w += s[j];
			s = w;
			break;
		}
	}
	
	assert(s[0] == '0');
	assert(s[n-1] == '1');
	debug(s);
	
	suffix[n] = true;
	for (int i=n-1; i>=0; --i) {
		suffix[i] = suffix[i + 1] & (s[i] == '1');
	}
	
	dp[0][1] = 1;
	dp[0][0] = 0;
	
	int result = 1;
	int ost_reach = 0;
	for (int i=1; i<n; ++i) {
		FOR(j, 0, 1) dp[i][j] = dp[i-1][j];
		
		if (i > 1 && s[i-2] != s[i-1]) ost_reach = i - 1;
		
		if (ost_reach != 0) {
			FOR(j, 0, 1) dp[i][j] = max(dp[i][j], 1 + dp[ost_reach - 1][j]);
		}
		else {
			dp[i][0] = 1;
			dp[i][1] = 1;
		}
		
		result = max(result, dp[i][0]);
		if (!suffix[i]) result = max(result, dp[i][1]);
	}
	
	cout << result << "\n";
}