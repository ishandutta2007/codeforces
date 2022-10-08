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
vi par;
vi dp; //ending at node v

void dfs(int x, int p=-1) {
	int current = 0;
	for (auto u : v[x]) {
		if (u != p) {
			par[u] = x;
			dfs(u, x);
			current ^= (dp[u] + 1);
		}
	}
	
	dp[x] = current;
}
void solve(int tc) {
	int n;
	cin >> n;
	v.resize(n); par.resize(n, 0); dp.resize(n, 0);
	
	rep(i, 1, n) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(0);
	vi marked(n, 0);
	marked[0] = 1;
	int ksor = dp[0];
	auto ans = [&]() {
		if (ksor == 0) cout << "2";
		else cout << "1";
	};
	ans();
	rep(i, 1, n) {
		vi vis;
		int node = i;
		while (!marked[node]) {
			marked[node] = 1;
			vis.pb(node);
			node = par[node];
		}
		
		reverse(all(vis));
		trav(node, vis) {
			ksor ^= (dp[node] + 1);
			ksor ^= dp[node];
			ksor ^= 1;
		}
		ans();
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