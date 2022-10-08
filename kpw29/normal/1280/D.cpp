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
const ll INF = 1e14;
bool TEST = 0;
const int N = 3000;
//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n, m;
	if (!TEST) cin >> n >> m;
	else n = N, m = random(1, n);
	debug(n, m);
	vector<vi> v(n);
	vector<vi> ch(n);
	vector<vector<pll> > dp(n);
	vi size(n, 0);
	
	vll vec(n);
	if (!TEST) rep(i, 0, n) cin >> vec[i];
	
	rep(i, 0, n) {
		int a;
		if (!TEST) {
			cin >> a;
			vec[i] = a - vec[i];
		}
		else vec[i] = random(-1, 1);
	}
	
	//debug(vec);
	FOR(i, 2, n) {
		int a, b;
		if (!TEST) cin >> a >> b;
		else a = i, b = random(1, i - 1);
		a -= 1; b -= 1;
		v[a].pb(b);
		v[b].pb(a);
	}
	debug(vec);
	function<void(int, int)> dfs = [&](int x, int par) {
		size[x] = 1;
		bool son = 0;
		debug(x, v[x]);
		trav(u, v[x]) {
			if (u != par) {
				son = 1;
				dfs(u, x);
			}
		}
		if (!son) { // i am a leaf
			dp[x] = {{0, vec[x]}};
			return;
		}
		debug(x);
		son = 0;
		trav(u, v[x]) {
			if (u != par) {
				if (!son) { //initialize dp
					dp[x].resize(size[u] + 1, {0, -INF});
					rep(k, 0, size[u]) { //mamy dwie opcje
						dp[x][k] = max(dp[x][k], {dp[u][k].e1, dp[u][k].e2 + vec[x]});
						dp[x][k + 1] = max(dp[x][k + 1], {dp[u][k].e1 + ((dp[u][k].e2 > 0) ? 1 : 0), 
							vec[x]});
					}
					size[x] += size[u];
					assert(sz(dp[x]) >= size[x]);
				}
				else {
					vector<pll> newdp(size[x] + size[u] + 1, {0, -INF});
					rep(oldcomp, 0, size[x]) {
						rep(newcomp, 0, size[u]) {
							newdp[oldcomp + newcomp] = max(newdp[oldcomp + newcomp],
							{dp[x][oldcomp].e1 + dp[u][newcomp].e1, dp[x][oldcomp].e2 + dp[u][newcomp].e2});
							newdp[oldcomp + newcomp + 1] = max(newdp[oldcomp + newcomp + 1],
							make_pair(dp[x][oldcomp].e1 + dp[u][newcomp].e1 + ((dp[u][newcomp].e2 > 0) ? 1 : 0),
								dp[x][oldcomp].e2));
						}
					}
					
					dp[x] = newdp;
					size[x] += size[u];
					assert(sz(dp[x]) >= size[x]);
				}
				son = 1;
				assert(sz(dp[x]) >= size[x]);
			}
		}
		
		debug(x);
		
	};
	
	dfs(0, 0);
	auto wyn = dp[0][m - 1];
	if (wyn.e2 > 0) wyn.e1++;
	cout << wyn.e1 << "\n";
}

int main() {
	boost;
	int tests = 1;
	cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}