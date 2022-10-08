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
vector <vi> v;
vi dist;

void dfs(int x) {
	trav(u, v[x]) {
		dist[u] = dist[x] + 1;
		dfs(u);
	}
}
const ll INF = LLONG_MAX / 4;
void solve(int tc) {
	int n;
	cin >> n;
	v.clear(); dist.clear();
	v.resize(n); dist.resize(n, 0);
	vi parent(n, 0);
	rep(i, 1, n) {
		int par;
		cin >> par;
		--par;
		parent[i] = par;
		v[par].pb(i);
	}
	
	dfs(0);
	vi nodes(n);
	rep(i, 0, n) nodes[i] = i;
	vll score(n, 0);
	rep(i, 1, n) cin >> score[i];
	vll dp(n, 0);
	
	sort(all(nodes), [&](const int &a, const int &b) {
		if (dist[a] != dist[b]) return dist[a] < dist[b];
		if (score[a] != score[b]) return score[a] < score[b];
		return a < b;
	});
	
	vector <pii> ranges = {{0, 0}};
	assert(nodes[0] == 0);
	rep(i, 1, n) {
		if (dist[nodes[i]] == dist[nodes[i-1]]) ranges[sz(ranges)-1].e2++;
		else ranges.pb({i, i});
	}
	
	pii ost = ranges.back();
	int x = ost.e1, y = ost.e2;
	
	ll bestplus = -INF, bestminus = -INF;
	for (int i=x; i<=y; ++i) {
		dp[nodes[i]] = max(abs(score[nodes[i]] - score[nodes[x]]),
						   abs(score[nodes[i]] - score[nodes[y]]));
						   
		bestplus = max(bestplus, dp[nodes[i]] + score[parent[nodes[i]]]);
		bestminus = max(bestminus, dp[nodes[i]] - score[parent[nodes[i]]]);
	}
	
	for (int d = sz(ranges)-2; d > 0; --d) {
		// szukamy najlepszego poprzedniego	
		int x = ranges[d].e1, y = ranges[d].e2;
		for (int i=x; i<=y; ++i) {
			dp[nodes[i]] = max(bestplus - score[nodes[i]], bestminus + score[nodes[i]]);
			
			ll best_pair = max(abs(score[nodes[i]] - score[nodes[x]]),
						   abs(score[nodes[i]] - score[nodes[y]]));
						   
			for (auto child : v[nodes[i]]) {
				dp[nodes[i]] = max(dp[nodes[i]], dp[child] + best_pair);
			}
		}
		
		bestplus = -INF;
		bestminus = -INF;
		for (int i=x; i<=y; ++i) {
			bestplus = max(bestplus, dp[nodes[i]] + score[parent[nodes[i]]]);
			bestminus = max(bestminus, dp[nodes[i]] - score[parent[nodes[i]]]);
		}
	}
	
	ll res = 0;
	trav(u, nodes) res = max(res, dp[u]);
	cout << res << "\n";
	
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