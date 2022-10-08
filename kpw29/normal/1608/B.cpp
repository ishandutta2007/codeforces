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
#define boost {ios_base::sync_with_stdio(false); }
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
	int n, a, b;
	cin >> n >> a >> b;
	swap(a, b);
	if (abs(a - b) > 1) TCOUT(-1);
	if (a + b > n - 2) TCOUT(-1);
	if (a == 0 && b == 0) {
		FOR(i, 1, n) cout << i << ' ';
		cout << "\n";
		return;
	}
	//da sie
	
	int parmin = 0;
	if (a < b) parmin = 1;
	vi type(n, -1);
	
	for (int i = 1 + parmin; a > 0; i += 2) {
		a--;
		type[i] = 0;
	}
	
	for (int i = 1 + (1 - parmin); b > 0; i += 2) {
		b--;
		type[i] = 1;
	}
	
	vi result(n, -1);
	int first = 0, last = n - 1;
	while (type[first] == -1) ++first;
	while (type[last] == -1) --last;
	
	int i = 1, j = n;
	
	//0 - local minimum
	if (type[first] == 0) result[0] = j--;
	else result[0] = i++;
	
	if (type[last] == 0) { //koniec musi byc wiekszy
		for (int step = n - 1; step > last; --step) result[step] = j--;
	}
	else {
		for (int step = n - 1; step > last; --step) result[step] = i++;
	}
	
	while (first <= last) {
		if (type[first] == 0) result[first++] = i++;
		else result[first++] = j--;
	}

	rep(i, 0, n) assert(result[i] != -1);
	rep(i, 0, n) cout << result[i] << ' ';
	cout << "\n";
	
}

int main() {
	boost;
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}