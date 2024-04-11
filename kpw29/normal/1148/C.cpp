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
void solve(int tc) {
	int n;
	cin >> n;
	vi perm(n+1);
	rep(i, 1, n+1) cin >> perm[i];
	int half = (n / 2);
	vector <pii> ans;
	vi gdzie(n+1, 0);
	FOR(i, 1, n) gdzie[perm[i]] = i;
	
	auto swp=[&](int a, int b) {
		debug("Swap", a, b);
		ans.pb({a, b});
		swap(perm[a], perm[b]);
		gdzie[perm[a]] = a;
		gdzie[perm[b]] = b;
	};
	
	int n0 = half, n1 = half + 1;
	vi sequence;
	FOR(i, 1, n) {
		if (i % 2 == 1) sequence.pb(n0--);
		else sequence.pb(n1++);
	}
	auto ok = [&](int a, int b) {
		return abs(a - b) * 2 >= n;
	};
	debug(sequence);
	trav(elem, sequence) {
		int curr = gdzie[elem];
		debug(gdzie);
		debug(perm);
		if (curr == elem) continue;
		debug(curr, elem);
		if (ok(elem, curr)) swp(curr, elem); //just swap
		else { //too close, swap with one suffix
			if (ok(curr, 1) && ok(1, elem)) {
				swp(curr, 1); swp(1, elem);
			}
			else if (ok(curr, n) && ok(n, elem)) {
				swp(curr, n); swp(n, elem);
			}
			else if (ok(curr, 1) && ok(1, n) && ok(n, elem)) {
				swp(curr, 1); swp(1, n); swp(n, elem);
			}
			else if (ok(curr, n) && ok(n, 1) && ok(1, elem)) {
				swp(curr, n); swp(n, 1); swp(1, elem);
			}
			else {
				assert(1 == 0);
			}
		}
	}
	/*int fz = 1, fo = half + 1;
	FOR(i, 1, half) {
		int j = i + half;
		int ti = type(perm[i]), tj = type(perm[j]);
		debug(i, j, ti, tj);
		if (ti < tj) continue;
		else if (ti > tj) swp(i, j);
		else {
			//they are the same
			if (ti == 0) {
				while (type(perm[fo]) == 0) ++fo;
				debug(j, fo);
				zamien(j, fo);
			}
			else {
				while (type(perm[fz]) == 1) ++fz;
				debug(i, fz);
				zamien(i, fz);
			}
		}
		debug(perm);
	}
	
	debug(perm);
	FOR(i, 1, half) assert(type(perm[i]) == 0);
	FOR(i, half+1, n) assert(type(perm[i]) == 1);
	
	vi odw(n+1, 0);
	FOR(i, 1, n) {
		if (!odw[i]) {
			vi cycle;
			int j = i;
			while (!odw[j]) {
				cycle.pb(j);
				odw[j] = 1;
				j = perm[j];
			}
			debug(cycle);
			rep(c, 0, sz(cycle)-1) zamien(cycle[c], cycle[c+1]);
		}
	}*/
	
	FOR(i, 1, n) assert(perm[i] == i);
	cout << sz(ans)  << endl;
	trav(u, ans) cout << u.e1 << ' ' << u.e2 << "\n";
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