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
const int inf = 1e9+9;
//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n;
	cin >> n;
	vi a(n+1);
	vi b(n+1); vi go(n+1);
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i];
	rep(i, 1, n+1) go[i] = i - b[i];
	go[0] = 0;
	
	set <int> to_visit;
	queue <int> q;
	vector<bool> odw(n+1, 0);
	vi par(n+1, -1);
	vi dist(n+1, inf);
	dist[n] = 0;
	q.push(n);
	
	rep(i, 0, n) to_visit.insert(i);
	
	while (!q.empty()) {
		int i = q.front();
		int init = i;
		i += b[i]; // slipped
		q.pop();
		debug(i, init);
		
		int MIN = i - a[i];
		if (MIN < 0) MIN = 0;
		while (true) {
			if (to_visit.empty()) break;
			auto it = to_visit.upper_bound(i);
			if (it == to_visit.begin()) break;
			--it;
			if (*it >= MIN && *it <= i) {
				to_visit.erase(*it);
				odw[*it] = 1;
				dist[*it] = dist[init] + 1;
				par[*it] = init;
				q.push(*it);
			}
			else break;
		}
		
	}
	debug(par);
	debug(dist);
	
	if (dist[0] == inf) {
		TCOUT(-1);
	}
	
	cout << dist[0] << "\n";
	int gdzie = 0;
	vi vec;
	while (gdzie != n) {
		vec.pb(gdzie);
		gdzie = par[gdzie];
	}
	reverse(all(vec));
	trav(u, vec) cout << u << ' ';
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