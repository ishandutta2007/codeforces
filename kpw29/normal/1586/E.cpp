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
const int maxn = 300100;
int n, m;
vector <int> v[maxn], ch[maxn];
int depth[maxn];
bool odw[maxn];
int parent[maxn];
int ksor[maxn];
int wychodzi[maxn];

int deg[maxn];

void dfs(int x) {
	odw[x] = 1;
	for (auto u : v[x]) {
		if (!odw[u]) {
			parent[u] = x;
			depth[u] = depth[x] + 1;
			ch[x].pb(u);
			dfs(u);
		}
	}
}

int ans;

void licz(int x) {
	for (auto u : ch[x]) {
		licz(u);
	}
	
	int ile_mam = 0;
	trav(u, ch[x]) {
		if (wychodzi[u]) ile_mam++;
	}
	
	if (!ksor[x]) {
		ans += ((ile_mam + 1) / 2);
		wychodzi[x] = 0;
	}
	else {
		++ile_mam;
		ans += (ile_mam / 2);
		wychodzi[x] = (ile_mam % 2);
	}
}

void solve() {
	cin >> n >> m;
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1);
	int q;
	cin >> q;
	vector <vi> paths(q);
	
	rep(zap, 0, q){
		
		vi aans, bans;
		vi path;
		int a, b;
		cin >> a >> b;
		while (a != b) {
			if (depth[a] > depth[b]) {
				aans.pb(a);
				ksor[a] ^= 1;
				a = parent[a];
			}
			else {
				bans.pb(b);
				ksor[b] ^= 1;
				b = parent[b];
			}
		}
		
		trav(u, aans) path.pb(u);
		path.pb(a);
		reverse(all(bans));
		trav(u, bans) path.pb(u);
		paths[zap] = path;
	}
	
	bool yes = true;
	assert(ksor[1] == 0);
	FOR(i, 2, n) {
		if (ksor[i]) yes = false;
	}
	
	if (yes) {
		cout << "YES\n";
		rep(zap, 0, q) {
			cout << sz(paths[zap]) << "\n";
			trav(u, paths[zap]) cout << u << ' ';
			cout << "\n";
		}
		return;
	}
	
	// count result
	cout << "NO\n";
	/*FOR(i, 1, n) cout << parent[i] << ' ';
	cout << endl;
	FOR(i, 1, n) cout << ksor[i] << ' ';
	cout << endl;
	*/
	//licz(1);
	
	FOR(i, 2, n) {
		if (ksor[i]) deg[i] ^= 1, deg[parent[i]] ^= 1;
	}
	
	FOR(i, 1, n) {
		if (deg[i]) ++ans;
	}
	assert(ans % 2 == 0);
	cout << ans / 2 << "\n";
}

int main() {
	boost;
	solve();
}