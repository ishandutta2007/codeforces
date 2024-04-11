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

#define int long long
//Did you REAALLY consider sample tests?
int mod, n;

const int RANGE = 4000000;
int dp[RANGE+1];
int pref[RANGE+1];


int32_t main() {
	boost;
	cin >> n >> mod;
	pref[n] = dp[n] = 1;
	for (int i=n-1; i>=1; --i) {
		dp[i] = pref[i + 1];
		int k = 1;
		for (int j=i+i; j<=n; j+=i) {
			k++;
			/*int x = j, y = n;
			while (x < y) {
				int sr = (x + y) / 2 + 1;
				if (sr / k != i) --y;
				else ++x;
			}*/
			int ostatni = min(k * (i + 1) - 1, n);
			int add = pref[j] - pref[ostatni + 1] + mod;
			if (add >= mod) add -= mod;
			dp[i] = (dp[i] + add);
			if (dp[i] >= mod) dp[i] -= mod;
		}
		pref[i] = (pref[i+1] + dp[i]) % mod;
	}
	
	cout << dp[1] << endl;
	
	//FOR(i, 1, n) cout << dp[i] << ' ';
}