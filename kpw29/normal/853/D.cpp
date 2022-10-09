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
const int maxn = 300003;
int n;
int tab[maxn];
const int MAX = 30;
const int inf = 1e9 + 9;
int dp[maxn][MAX + 1];
void minuj(int &x, int val) {
	x = min(x, val);
}

void solve() {
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	FOR(i, 0, n) FOR(j, 0, MAX) dp[i][j] = inf;
	
	dp[0][0] = 0;
	FOR(i, 1, n) {
		FOR(bonus, 0, MAX) {		
			// 1 - buy using some bonus
			int will_use = min(tab[i] / 100, bonus);
			int will_buy = tab[i] - 100 * will_use;
			minuj(dp[i][bonus - will_use], dp[i-1][bonus] + will_buy);
			
			// 2 - buy using cash only
			int will_get = tab[i] / 1000;
			minuj(dp[i][bonus + will_get], dp[i-1][bonus] + tab[i]);
		}
		
		FOR(bonus, 0, MAX) debug(i, bonus, dp[i][bonus]);
	}
	
	int wyn = inf;
	FOR(bonus, 0, MAX) wyn = min(dp[n][bonus], wyn);
	cout << wyn << endl;
}

int main() {
	boost;
	solve();
}