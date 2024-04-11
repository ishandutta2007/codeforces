#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
vector <mint> fac, inv;
mint binom(int n, int k) {
	if (n < k || n < 0) return 0;
	return fac[n] * inv[k] * inv[n-k];
}

void prep(int N) {
	fac.resize(N+1, 1); inv.resize(N+1, 1);
	for (int i=1; i<=N; ++i) fac[i] = fac[i-1] * i;
	inv[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) inv[i] = inv[i+1] * (i + 1);
}*/

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
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
const int maxn = 1000100;

//Did you REAALLY consider sample tests?
bool dp[3];
string s[3];

int blocked[3][110];
int will_block[3][110];

void solve(int tc) {
	int n, m;
	cin >> n >> m;
	rep(i, 0, 3) cin >> s[i];
	dp[0] = dp[1] = dp[2] = 0;
	rep(i, 0, 3) FOR(j, 0, n) blocked[i][j] = 0, will_block[i][j] = 0;
	
	rep(i, 0, 3) {
		if (s[i][0] == 's') {
			dp[i] = 1;
			if (s[i][1] != '.') TCOUT("NO");
		}
	}
	
	rep(i, 0, 3) {
		rep(j, 0, n) {
			if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
				int zagraza = (j + 1) / 3;
				if (j % 3 == 1) will_block[i][zagraza] = 1;
				else blocked[i][zagraza] = 1;
			}
		}
	}
	
	FOR(turn, 1, n) {
		vector<pii> pairs = {{0, 1}, {1, 2}, {1, 0}, {2, 1}};
		vi old(3);
		rep(i, 0, 3) old[i] = dp[i];
		
		for (auto &[poprz, teraz] : pairs) {
			if (old[poprz] && !will_block[teraz][turn-1] && !will_block[poprz][turn-1]) dp[teraz] = 1;
		}
		rep(i, 0, 3) if (blocked[i][turn] || will_block[i][turn]) dp[i] = 0;
	}
	
	rep(i, 0, 3) if (dp[i]) TCOUT("YES");
	TCOUT("NO");
}

int main() {
	boost;
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}