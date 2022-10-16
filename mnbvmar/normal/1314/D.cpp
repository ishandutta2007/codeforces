#pragma GCC optimize("O3")
#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // XIII LO Szczecin
using LL = long long;    // Poland
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
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
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
// end of templates
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	vector<vector<int>> cost(n, vector<int>(n));
	REP(i, n)
		REP(j, n)
			cin >> cost[i][j];
	debug(cost);
 
	constexpr LL inf = LL(1e18) + 1;
	LL answer = inf;
	int iterations = 60000;
	REP(it, iterations) {
		vector<bool> side(n);
		FOR(i, 1, n - 1)
			side[i] = rd(0, 1);
		vector<vector<LL>> dp(k + 1, vector<LL>(n, inf));
		array<vector<int>, 2> vertices;
		REP(v, n)
			vertices[side[v]].emplace_back(v);
 
		dp[0][0] = 0;
		FOR(K, 1, k) {
			int parity = K % 2;
			for(int start : vertices[parity ^ 1])
				for(int end : vertices[parity])
					dp[K][end] = min(dp[K][end], dp[K - 1][start] + cost[start][end]);
		}
		debug(dp);
		answer = min(answer, dp[k][0]);
	}
	cout << answer << '\n';
}