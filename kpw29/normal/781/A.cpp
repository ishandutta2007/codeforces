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

void przypisz(int x, int par, int curr, int mx, vector <vi> &v, vi &col) {
	for (auto u : v[x]) {
		if (u != par) {
			while (col[x] == curr || (x > 1 && col[par] == curr)) {
				if (curr == mx) curr = 1;
				else curr++;
			}
			col[u] = curr;
			if (curr == mx) curr = 1;
			else curr++;
			przypisz(u, x, curr, mx, v, col);
		}
	}
}

void solve(int tc) {
	//Did you REAALLY consider sample tests?
	int n;
	cin >> n;
	vector<vi> v(n+1);
	vi col(n+1, 0);
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	col[1] = 1;
	int k = 0;
	FOR(i, 1, n) k = max(k, (int)sz(v[i]) + 1);
	przypisz(1, 1, 2, k, v, col);
	FOR(i, 1, n) {
		set <int> s;
		s.insert(col[i]);
		trav(node, v[i]) s.insert(col[node]);
		assert(sz(s) == sz(v[i]) + 1);
	}
	cout << k << endl;
	FOR(i, 1, n) cout << col[i] << ' ';
	cout << endl;
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