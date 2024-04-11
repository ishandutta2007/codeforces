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

//Did you REAALLY consider sample tests?
int arr[1002], n, k;
const int mod = 998244353;
const int MAX = 1e5;

inline void addmod(int &x, int val) { x += val; if (x >= mod) x -= mod; }
int pref[1002][1002];

int suf[1002][1002];

int dp[1002][1002];
int sdp[1002][1002];

int poprzedni[1002][1002];

int jumpLeft[1002];
int jumpRight[1002];

int first[MAX + 2];
int lastt[MAX + 2];

void solve(int tc) {
	cin >> n >> k;
	FOR(i, 1, n) cin >> arr[i];
	auto range = [&](int beauty) {
		if (beauty == 0) return k;
		return min(k, MAX / beauty + 1);
	};
	
	sort(arr+1, arr+n+1);
	FOR(i, 1, n) {
		if (first[arr[i]] == 0) first[arr[i]] = i;
	}
	for (int i=n; i>0; --i) {
		if (lastt[arr[i]] == 0) lastt[arr[i]] = i;
	}
	
	FOR(i, 1, n) {
		jumpLeft[i] = i - 1;
		for (int j = i - 1; j > 0; --j) {
			if (arr[i] == arr[j]) jumpLeft[i] = j;
		}
		jumpRight[i] = i + 1;
		for (int j = i + 1; j <= n; ++j) {
			if (arr[i] == arr[j]) jumpRight[i] = j;
		}
	}
	
	int res = 0;
	arr[0] = -mod; arr[n+1] = mod;
	int maxk = MAX / (k - 1);
	for (int b = 1; b <= maxk; ++b) { //ustalamy to beauty
		//debug(b);
		int rr = range(b);
		for (int i = 1; i <= n; ++i) {
			while (jumpLeft[i] > 0 && abs(arr[i] - arr[jumpLeft[i]]) < b) jumpLeft[i] -= 1;
			while (jumpRight[i] <= n && abs(arr[i] - arr[jumpRight[i]]) < b) jumpRight[i] += 1;
			//if (b <= 5) debug(i, b, jumpLeft[i], jumpRight[i]);
		}
		
		// ranges correct
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= rr; ++j) {
				pref[i][j] = pref[i-1][j];
				dp[i][j] = pref[jumpLeft[i]][j - 1];
				if (j == 1) dp[i][j]++;
				addmod(pref[i][j], dp[i][j]);
			}
		}

		for (int i = n; i > 0; --i) {
			for (int j = 1; j <= rr; ++j) {
				suf[i][j] = suf[i+1][j];
				sdp[i][j] = suf[jumpRight[i]][j - 1];
				if (j == 1) sdp[i][j]++;
				addmod(suf[i][j], sdp[i][j]);
			}
		}
		
		addmod(res, pref[n][k]);
		// the results for b - 1 should be calculated
		/*for (int i = 1; i <= n; ++i) {
			if (arr[i] >= (b - 1)) {
				int j = lastt[arr[i] - (b - 1)];
				if (j != 0 && j < i) { //mamy dobrego kandydata
					int oldrange = range(b - 1);
					int rx = min(oldrange, k);
					//debug(j, i, b);
					for (int kk = 1; kk <= rx; ++kk) {
						int val = (ll)(b - 1) * (ll)poprzedni[j][kk] % mod;
						val = (ll)val * (ll)sdp[i][k - kk] % mod;
						//debug(j, i, b, kk, k-kk, poprzedni[j][kk], sdp[i][k - kk]);
						addmod(res, val);
					}
				}
			}
		}*/
		
		//cleanup
		FOR(i, 0, n+1) {
			pref[i][0] = 0;
			suf[i][0] = 0;
			FOR(j, 1, rr) {
				poprzedni[i][j] = dp[i][j];
				dp[i][j] = sdp[i][j] = pref[i][j] = suf[i][j] = 0;
			}
		}
	}
	
	cout << res << "\n";
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}