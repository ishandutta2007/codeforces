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
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#endif

#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif
const int maxn = 200100;
bool odw[maxn];
vector <int> v[maxn];
int n, m;
vector <vi> ans;
bool av[maxn];
int pre[maxn];
int DL = 0;

void dfs(int x, int par, int root) {
	pre[x] = ++DL;
	odw[x] = 1;
	int avail = 0;
	for (auto u : v[x]) {
		if (!odw[u]) { //drzewowe w d
			dfs(u, x, root);
			debug(x, u);
			if (!av[u]) continue;
			if (avail != 0) {
				ans.pb({avail, x, u});
				avail = 0;
			}
			else avail = u;
		}
		else if (u != par && pre[u] < pre[x]) { //niedrzewowe z x do u
			if (avail != 0) {
				ans.pb({avail, x, u});
				avail = 0;
			}
			else avail = u;
		}
	}
	
	if (avail && x != root) { // do ojca 
		av[x] = 0;
		ans.pb({avail, x, par});
		avail = 0;
	}
	
}

void solve(int tc) {
	cin >> n >> m;
	FOR(i, 1, n) av[i] = 1;
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n) {
		if (!odw[i]) dfs(i, i, i);
	}
	
	cout << sz(ans) << endl;
	trav(u, ans) cout << u[0] << ' ' << u[1] << ' ' << u[2] << "\n";
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