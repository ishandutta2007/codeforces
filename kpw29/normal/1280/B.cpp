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
/**
 * Author: Johan Sannemo
 * Date: 2014-11-28
 * License: CC0
 * Source: Folklore
 * Description: Calculate submatrix sums quickly, given upper-left and lower-right corners (half-open).
 * Usage:
 * SubMatrix<int> m(matrix);
 * m.sum(0, 0, 2, 2); // top left 4 elements
 * Time: O(N^2 + Q)
 * Status: Tested on Kattis
 */
 
template<class T>
struct SubMatrix {
	vector<vector<T>> p;
	SubMatrix(vector<vector<T>>& v) {
		int R = sz(v), C = sz(v[0]);
		p.assign(R+1, vector<T>(C+1));
		rep(r,0,R) rep(c,0,C)
			p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
	}
	T sum(int u, int l, int d, int r) {
		return p[d][r] - p[d][l] - p[u][r] + p[u][l];
	}
};
//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n, m;
	cin >> n >> m;
	vector<vi> vec(n);
	
	rep(i, 0, n) {
		string s;
		cin >> s;
		vi tmp(m);
		rep(i, 0, m) {
			if (s[i] == 'A') tmp[i] = 0;
			else tmp[i] = 1;
		}
		vec[i] = tmp;
	}
	
	
	SubMatrix<int> solver(vec);
	if (solver.sum(0, 0, n, m) == 0) TCOUT(0);
	if (solver.sum(0, 0, n, m) == n * m) TCOUT("MORTAL");
	
	if (solver.sum(0, 0, n, 1) == 0) TCOUT(1);
	if (solver.sum(0, 0, 1, m) == 0) TCOUT(1);
	if (solver.sum(n-1, 0, n, m) == 0) TCOUT(1);
	if (solver.sum(0, m-1, n, m) == 0) TCOUT(1);
	
	// rows or columns
	rep(i, 0, n) {
		if (solver.sum(i, 0, i+1, m) == 0) TCOUT(2);
	}
	rep(j, 0, m) {
		if (solver.sum(0, j, n, j+1) == 0) TCOUT(2);
	}
	
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (solver.sum(0, 0, i+1, j+1) == 0) TCOUT(2);
			if (solver.sum(i, j, n, m) == 0) TCOUT(2);
			if (solver.sum(0, j, i + 1, m) == 0) TCOUT(2);
			if (solver.sum(i, 0, n, j + 1) == 0) TCOUT(2);
		}
	}
	
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (solver.sum(i, j, i+1, j+1) == 0) {
				if (i == 0 || j == 0 || i == n - 1 || j == m - 1) TCOUT(3);
			}
		}
	}
	
	TCOUT(4);
}

int main() {
	boost;
	int tests = 1;
	cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}