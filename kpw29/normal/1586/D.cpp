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
const int maxn = 1100;

int n;

bool LOCAL = 0;
int key[maxn];
int ask(vi v) {
	cout << "? ";
	for (int i=1; i<=n; ++i) cout << v[i] << ' ';
	cout << endl;
	
	int ans;
	if (LOCAL) {
		map <int, int> M;
		FOR(i, 1, n) {
			int co = v[i] + key[i];
			if (M.find(co) != M.end()) return i;
			M[co] = 1;
		}
		return 0;
	}
	else cin >> ans;
	return ans;
}

vi edges[maxn];


void solve() {
	cin >> n;
	if (LOCAL) {
		FOR(i, 1, n) cin >> key[i];
	}
	
	vi perm(n + 1, 0);
	int pos_max = -1;
	
	
	FOR(i, 1, n) {
		
		vi vec(n + 1, 1);
		vec[i] = 2; //dodam jeden
		int num = ask(vec);
		
		if (num == 0) pos_max = i;
		else {
			if (num != i) {
				edges[i].pb(num);
				edges[num].pb(i);
			}
		}
	}
	
	FOR(i, 1, n) {
		vi vec(n + 1, 2);
		vec[i] = 1;
		int num = ask(vec);
		if (num == 0) continue;
		if (num != i) {
			edges[i].pb(num);
			edges[num].pb(i);
		}
	}
	
	assert(pos_max != -1);
	int p = pos_max;
	vi odp(n+1, 0);
	int ID = n + 1;
	
	vector <bool> vis(n + 1, 0);
	
	while (ID > 1) {
		ID--;
		vis[p] = 1;
		odp[p] = ID;
		
		int nast = -1;
		trav(u, edges[p]) {
			if (!vis[u]) nast = u;
		}
		
		p = nast;
	}
	
	cout << "! ";
	FOR(i, 1, n) cout << odp[i] << ' ';
	cout << endl;
	
}

int main() {
	solve();

}