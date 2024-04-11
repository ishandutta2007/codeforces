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
/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * License: CC0
 * Source: folklore
 * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of the type $(a\|\|b)\&\&(!a\|\|c)\&\&(d\|\|!b)\&\&...$ becomes true, or reports that it is unsatisfiable.
 * Negated variables are represented by bit-inversions (\texttt{\tilde{}x}).
 * Usage:
 *  TwoSat ts(number of boolean variables);
 *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
 *  ts.setValue(2); // Var 2 is true
 *  ts.atMostOne({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
 *  ts.solve(); // Returns true iff it is solvable
 *  ts.values[0..N-1] holds the assigned values to the vars
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 * Status: stress-tested
 */

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void unsEither(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].pop_back();
		gr[j].pop_back();
	}
	
	void setValue(int x, bool va) {
		//debug("Setting", x, va);
		if (va) either(x, x); 
		else either(~x, ~x);
	}
	void unsetValue(int x, bool va) {
		//debug("Unsetting", x, va);
		if (va) unsEither(x, x);
		else unsEither(~x, ~x);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		z.clear();
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

bool cons[26];
int alpha;


int main() {
	boost;
	string s;
	cin >> s;
	alpha = sz(s);
	rep(i, 0, alpha) {
		cons[i] = s[i] == 'C';
	}
	
	int n, m;
	cin >> n >> m;
	TwoSat solver(n);
	rep(i, 0, m) {
		int a, b;
		char z1, z2;
		cin >> a >> z1 >> b >> z2;
		bool bita = (z1 == 'C');
		bool bitb = (z2 == 'C');
		--a; --b;
		int desa = ~a;
		int desb = b;
		if (!bita) desa = ~desa;
		if (!bitb) desb = ~desb;
		
		solver.either(desa, desb);
	}
	
	string input;
	cin >> input;
	string wyn = "";
	auto get_different = [&](int lit, bool bit) -> int {
		while (lit < alpha && cons[lit] == bit) ++lit;
		if (lit == alpha) return -1;
		return lit;
	};
	
	for (int prefix = n; prefix >= 0; --prefix) { //iterating over common prefix
		debug(prefix);
		wyn = "";
		rep(i, 0, prefix) {
			char zn = input[i];
			wyn += zn;
			bool bit = cons[zn - 'a'];
			solver.setValue(i, bit);
		}
		if (prefix == n) {
			bool odp = solver.solve();
			if (odp) OUT(wyn);
			for (int i = prefix-1; i>=0; --i) {
				char zn = input[i];
				wyn.pop_back();
				bool bit = cons[zn - 'a'];
				solver.unsetValue(i, bit);
			}
		}
		else { //istnieje inna literka
			int dig = input[prefix] - 'a';
			int nast = dig + 1;
			if (nast >= alpha) nast = -1;	
			bool bit = 0;
			if (nast != -1) bit = cons[nast];
			auto probuj = [&]() {
				solver.setValue(prefix, bit);
				bool odp = solver.solve();
				if (odp) {
					debug("ANS");
					// we know that this is going to be the solution, let's iterate it
					wyn += (char)(nast + 'a');
					for (int i=prefix+1; i<n; ++i) {
						char zn = 'a';
						bool bit = cons[zn - 'a'];
						solver.setValue(i, bit);
						// ustawiam ten bit
						bool moge = solver.solve();
						if (!moge) { //odstawiam ten bit
							solver.unsetValue(i, bit);
							int dig = zn - 'a';
							while (dig < alpha && cons[dig] == bit) ++dig;
							if (dig >= alpha) OUT(-1);
							solver.setValue(i, 1 ^ bit);
							wyn += (char)(dig + 'a');
						}
						else wyn += zn;
					}
					OUT(wyn);
				}
				else { //this will not work, so resetting the constraints
					solver.unsetValue(prefix, bit); 
				}
			};
			
			if (nast != -1) {
				debug(nast);
				probuj();
				nast = get_different(nast, bit);
				if (nast != -1) {
					bit = cons[nast];
					debug(nast);
					probuj();
				}
			}
			
			for (int i = prefix-1; i>=0; --i) {
				char zn = input[i];
				wyn.pop_back();
				bool bc = cons[zn - 'a'];
				solver.unsetValue(i, bc);
			}
		}
	}
	
	OUT(-1);
}