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

void no() {
	cout << "Not unique";
	exit(0);
}

pii operator+(pii a, pii b) {
	return {a.e1 + b.e1, a.e2 + b.e2};
}

bool operator==(pii a, pii b) {
	return (a.e1 == b.e1 && a.e2 == b.e2);
}

//Did you REAALLY consider sample tests?
const int maxn = 2020;
int n, m;
string s[maxn];
vector <pii> neighbors = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector <char> signs = {'<', '>', 'v', '^'};

bool valid(int i, int j) {
	if (i < 0 || j < 0) return false;
	if (i >= n || j >= m) return false;
	if (s[i][j] != '.') return false;
	return true;
}

int deg[maxn * maxn];
inline int num(int i, int j) {
	return i * m + j;
}

int match[maxn * maxn];
string ans[maxn];
bitset <maxn * maxn> in_queue;

vector <int> get_neighbors(int nr) {
	vector <int> res;
	int i = nr / m, j = nr % m;
	pii pole = {i, j};
	
	trav(add, neighbors) {
		pii sas = pole + add;
		if (valid(sas.e1, sas.e2)) res.pb(num(sas.e1, sas.e2));
	}
	
	return res;
}

void solve(int tc) {
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> s[i];
	}
	
	queue <int> q;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (s[i][j] == '.') {
				pii pole = {i, j};
				int nr = num(i, j);
				trav(add, neighbors) {
					pii sas = pole + add;
					if (valid(sas.e1, sas.e2)) {
						//v[nr].pb(num(sas.e1, sas.e2));
						deg[nr]++;
					}
				}
				
				if (deg[nr] == 1 && !in_queue[nr]) in_queue[nr] = 1, q.push(nr);
			}
		}
	}
	rep(i, 0, n*m) match[i] = -1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (match[x] != -1) continue;
		//select a guy to match
		int mat = -1;
		vi vec = get_neighbors(x);
		trav(u, vec) {
			if (match[u] == -1) {
				mat = u;
			}
		}
		
		if (mat == -1) no();
		match[x] = mat;
		match[mat] = x;
		trav(node, vec) {
			deg[node]--;
			if (deg[node] <= 1 && !in_queue[node] && match[node] == -1) in_queue[node] = 1, q.push(node);
		}
		vec = get_neighbors(mat);
		trav(node, vec) {
			deg[node]--;
			if (deg[node] <= 1 && !in_queue[node] && match[node] == -1) in_queue[node] = 1, q.push(node);
		}
	}
	
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (s[i][j] == '.' && match[num(i,j)] == -1) no();
		}
	}
	
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (s[i][j] == '.') {
				int nr = num(i, j);
				if (match[match[nr]] != nr) no();
			}
		}
	}
	
	rep(i, 0, n) {
		ans[i] = s[i];
		rep(j, 0, m) {
			if (s[i][j] == '.') { //somehow matched
				int nr = num(i, j);
				pii pole = {i, j};
				for (int key = 0; key < 4; ++key) {
					pii opcja = pole + neighbors[key];
					if (valid(opcja.e1, opcja.e2) && num(opcja.e1, opcja.e2) == match[nr]) ans[i][j] = signs[key];
				}
			}
		}
	}
	
	rep(i, 0, n) cout << ans[i] << "\n";
			
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