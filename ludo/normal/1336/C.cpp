#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) begin(v), end(v)
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " \
		<< #x<< " = " << (x) << endl

template<class T> ostream& operator<<(ostream &os,
		const vector<T> &v) {
	os << "\n[";
	for(const T &x : v) os << x << ',';
	return os << "]\n";
}

namespace std { template<class T1, class T2>
struct hash<pair<T1,T2>> { public:
	size_t operator()(const pair<T1,T2> &p) const {
		size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
		return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
	}
}; }

const int mod = 998244353;

struct M {
	int x;
	M() : x(0) {}
	M(int _x) : x(_x) {
		if (x < 0) x += mod;
	}

	M operator+(const M &rhs) const {
		int y = x+rhs.x;
		return M(y >= mod ? y-mod : y);
	}

	M& operator+=(const M &rhs) {
		if ((x += rhs.x) >= mod)
			x -= mod;
		return *this;
	}
};

const int N = 3010;
M dp[N][N] = {};

void run() {
	string S, T;
	cin >> S >> T;

	int n = S.size();
	int m = T.size();

	for (int len = m; len <= n; len++) {
		dp[0][len] = M(1);
	}

	M ans(0);

	for (int w = n-1; w >= 0; w--) {
		char cur = S[w];

		for (int l = 0, r = w; r < n; l++, r++) {
			// dp[l][r] -> dp[l+1][r], dp[l][r-1]

			// either insert at l, or at r
			if (l == r) {
				if (l >= m || cur == T[l]) {
					ans += dp[l][l+1];
					ans += dp[l][l+1];
				}
				continue;
			}

			if (l >= m || cur == T[l]) dp[l+1][r+1] += dp[l][r+1];
			if (r >= m || cur == T[r]) dp[l][r] += dp[l][r+1];
		}
	}

	printf("%d\n", ans.x);
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}