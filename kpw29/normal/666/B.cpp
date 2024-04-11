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
const int maxn =3010;

//Did you REAALLY consider sample tests?
vi dist[maxn];

vi v[maxn];
int best[maxn][3];
int n, m;
const int inf = 1e9+9;
vi rev[maxn];
vi revdist[maxn];
int revbest[maxn][3];

void bfs(int start) {
	vi d(n + 1, -inf);
	queue <int> q;
	q.push(start);
	d[start] = 1;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto u : v[x]) {
			if (d[u] == -inf) {
				d[u] = d[x] + 1;
				q.push(u);
			}
		}
	}
	
	dist[start] = d;
}
void revbfs(int start) {
	vi d(n + 1, -inf);
	queue <int> q;
	q.push(start);
	d[start] = 1;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto u : rev[x]) {
			if (d[u] == -inf) {
				d[u] = d[x] + 1;
				q.push(u);
			}
		}
	}
	
	revdist[start] = d;
}

void solve(int tc) {
	cin >> n >> m;
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		//a = rand()%n+1; b = rand()%n+1;
		v[a].pb(b);
		rev[b].pb(a);
	}
	
	FOR(i, 1, n) {
		bfs(i);
		dist[i][0] = -inf;
		best[i][0] = best[i][1] = 0;
		
		FOR(j, 1, n) {
			if (dist[i][j] > dist[i][best[i][0]]) {
				best[i][2] = best[i][1];
				best[i][1] = best[i][0];
				best[i][0] = j;
			}
			else if (dist[i][j] > dist[i][best[i][1]]) {
				best[i][2] = best[i][1];
				best[i][1] = j;
			}
			else if (dist[i][j] > dist[i][best[i][2]]) {
				best[i][2] = j;
			}
		}
	}
	
	FOR(i, 1, n) {
		revbfs(i);
		revdist[i][0] = -inf;
		revbest[i][0] = revbest[i][1] = 0;
		FOR(j, 1, n) {
			if (revdist[i][j] > revdist[i][revbest[i][0]]) {
				revbest[i][2] = revbest[i][1];
				revbest[i][1] = revbest[i][0];
				revbest[i][0] = j;
			}
			else if (revdist[i][j] > revdist[i][revbest[i][1]]) {
				revbest[i][2] = revbest[i][1];
				revbest[i][1] = j;
			}
			else if (revdist[i][j] > revdist[i][revbest[i][2]]) {
				revbest[i][2] = j;
			}
		}
	}
	
	FOR(i, 1, n) debug(dist[i]);
	FOR(i, 1, n) debug(revdist[i]);
	
	vi opt = {};
	int ans = 0;
	FOR(a, 1, n) FOR(b, 1, n) {
		if (a == b || dist[a][b] == -inf) continue;
		rep(i, 0, 3) rep(j, 0, 3) {
			int n1 = revbest[a][i];
			int n2 = best[b][j];
			if (n1 == 0 || n2 == 0 || n1 == n2 || n1 == a || n1 == b || n2 == a || n2 == b) continue;
			int op = dist[n1][a] + dist[a][b] + dist[b][n2];
			if (op > ans) {
				ans = op;
				opt = {n1, a, b, n2};
			}
		}
	}
	
	debug(ans);
	trav(node, opt) cout << node << ' ';
			
}

int main() {
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}