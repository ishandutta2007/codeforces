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
const int R = (1 << 19);
int dr[2 * R + 5];

void insert(int x, int val) {
	x += R - 1;
	dr[x] = val;
	x /= 2;
	while (x) {
		dr[x] = __gcd(dr[2 * x], dr[2 * x + 1]);
		x /= 2;
	}
}
int ZLYCH;
bool SPLIT;

void query(int gdzie, int pocz, int kon, int a, int b, int x) {
	if (dr[gdzie] % x == 0) return;
	if (a <= pocz && b >= kon) { //base, zly
		if (ZLYCH == 0) ZLYCH = gdzie;
		else ZLYCH = -1;
		return;
	}
	
	int sr = (pocz + kon) / 2;
	if (a <= sr) query(2 * gdzie, pocz, sr, a, b, x);
	if (b > sr) query(2 * gdzie + 1, sr + 1, kon, a, b, x);
}

int main() {
	boost;
	int n, m;
	cin >> n;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		//a = rand()%n+1;
		insert(i, a);
	}
	cin >> m;
	FOR(z, 1, m) {
		int type, a, b, x;
		cin >> type;
		if (type == 1) {
			cin >> a >> b >> x;
			//a = rand()%n+1; b = rand()%n+1; x = rand()%n+1;
			if (a>b) swap(a, b);
			ZLYCH = 0;
			query(1, 1, R, a, b, x);
			debug(ZLYCH);
			bool ans = true;
			if (ZLYCH == -1) ans = false;
			else if (ZLYCH > 0) {
				int node = ZLYCH;
				while (node < R) {
					debug(node, dr[node], x, dr[2 * node], dr[2 * node + 1]);
					if (dr[2 * node] % x > 0 && dr[2 * node + 1] % x > 0) {ans = false; break; }
					else {
						if (dr[2 * node] % x > 0) node = 2 * node;
						else node = 2 * node + 1;
					}
				}
			}
			cout << (ans ? "YES\n" : "NO\n");
		}
		else {
			int i, a;
			cin >> i >> a;
			//i = rand()%n+1; a = rand()%n+1;
			insert(i, a);
		}
	}
}