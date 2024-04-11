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
//#include <atcoder/modint>
//using namespace atcoder;
//using mint = modint1000000007;
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
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void add(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll pytaj(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

const int maxn = 200100;
int p[maxn];

int n, zapp;

ll dp[maxn][3][3];
typedef pair<pii, pii> query;
ll wyn[3][3];

vector <query> q[maxn];

void solve(int tc) {
	cin >> n >> zapp;
	FOR(i, 1, n) cin >> p[i];
	FT tree(n+1);
	FOR(i, 1, zapp) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vi xlines = {a-1, c, n};
		vi ylines = {b-1, d, n};
		
		rep(a, 0, 3)
		rep(b, 0, 3) {
			q[xlines[a]].pb({{ylines[b], i}, {a, b}});
		}
	}
	
	FOR(i, 0, n) {
		if (i > 0) tree.add(p[i], 1);
		
		// zapytania
		trav(zap, q[i]) {
			auto [y, z] = zap.e1;
			auto [a, b] = zap.e2;
			
			dp[z][a][b] = tree.pytaj(y + 1);
		}
	}
	
	FOR(i, 1, zapp) {
		rep(a, 0, 3) rep(b, 0, 3) wyn[a][b] = 0;
		rep(a, 0, 3) {
			rep(b, 0, 3) {
				wyn[a][b] = dp[i][a][b];
				if (a > 0) wyn[a][b] -= dp[i][a-1][b];
				if (b > 0) wyn[a][b] -= dp[i][a][b-1];
				if (a > 0 && b > 0) wyn[a][b] += dp[i][a-1][b-1];
			}
		}
		
		ll ans = 0;
		ans += wyn[0][0] * (wyn[1][1] + wyn[1][2] + wyn[2][1] + wyn[2][2]);
		ans += wyn[0][1] * (wyn[1][0] + wyn[1][1] + wyn[1][2] + wyn[2][0] + wyn[2][1] + wyn[2][2]);
		ans += wyn[0][2] * (wyn[1][0] + wyn[1][1] + wyn[2][0] + wyn[2][1]);
		
		ans += wyn[1][0] * (wyn[1][1] + wyn[1][2] + wyn[2][1] + wyn[2][2]);
		//middle
		ans += wyn[1][1] * (wyn[1][2] + wyn[2][0] + wyn[2][1] + wyn[2][2]);
		ans += wyn[1][1] * (wyn[1][1] - 1) / 2;
		
		ans += wyn[1][2] * (wyn[2][0] + wyn[2][1]);
		
		cout << ans << "\n";
	}
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