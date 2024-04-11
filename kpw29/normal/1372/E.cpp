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
# define debug(x...) cerr << (#x != "" ? #x ":  " : ""), dump(x), Nl(), cerr
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
int rd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int dp[105][105];
int ile[105][105], n, m;

inline int sq(int x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		int k;
		cin >> k;
		for (int j=1; j<=k; ++j) {
			int pocz, kon;
			cin >> pocz >> kon;
			for (int a=1; a<=pocz; ++a)
				for (int b=kon; b<=m; ++b) ile[a][b]++;
		}
	}
	
	for (int len=1; len<=m; ++len) {
		for (int i=1; i+len-1<=m; ++i) {
			int j = i + len - 1;
			//we are counting dp[i][j]
			for (int k=i; k<=j; ++k) {
				int prawe = ile[i][k-1], lewe = ile[k+1][j];
				dp[i][j] = max(dp[i][j], sq(ile[i][j] - prawe - lewe) + dp[i][k-1] + dp[k+1][j]);
			}
		}
	}
	
	cout << dp[1][m];
}