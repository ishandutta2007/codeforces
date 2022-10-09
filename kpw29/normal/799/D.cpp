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
typedef unsigned long long ll;
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

int sufit(int a, int b) {
	if (a % b == 0) return a / b;
	return 1 + a/b;
}

//Did you REAALLY consider sample tests?
int wyn;
const int inf = 1e9+9;

void recurse(vector<pii> &dp, int i, ll s1, ll s2, ll n1, ll n2, int so_far) {
	if (s1 >= n1 && s2 >= n2) {
		wyn = min(wyn, so_far);
		return;
	}
	if (i >= sz(dp)) return;
	//consider all opt
	
	bool flag = rand()%2;
	if (flag) swap(s1, s2), swap(n1, n2);
	ll t1 = s1, t2 = s2;
	// sprawdz czy da sie tylko tym
	int ile = 0; ll pot = 1;
	while (pot * t1 < n1) ++ile, pot *= dp[i].e1;
	pot = 1;
	int tmp = ile;
	
	while (pot * t2 < n2) ++ile, pot *= dp[i].e1;
	if (ile <= dp[i].e2) {
		wyn = min(wyn, so_far + ile);
		return;
	}
	
	int ile_dwojka = ile - tmp;
	// nie da sie tym jednym, to sprobujmy dalej
	int min_jed = max(0, dp[i].e2 - ile_dwojka);
	FOR(step, 1, dp[i].e2-min_jed) t2 *= dp[i].e1;
	FOR(step, 1, min_jed) t1 *= dp[i].e1;
	for (int step = min_jed; step <= dp[i].e2; ++step) {
		recurse(dp, i + 1, t1, t2, n1, n2, so_far + dp[i].e2);
		t1 *= dp[i].e1;
		t2 /= dp[i].e1;
	}
}

void solve(int tc) {
	srand(2137);
	int a, b, w, h, n;
	cin >> a >> b >> w >> h >> n;
	int n1 = sufit(a, w);
	int n2 = sufit(b, h);
	debug(n1, n2);
	vi v(n);
	rep(i, 0, n) cin >> v[i];
	//rep(i, 0, n) v[i] = i + 2;
	sort(all(v), greater<int>());
	
	int greedy = min(n, 50); //not more than 40 always necessary
	vi cnt(100100, 0);
	rep(i, 0, greedy) cnt[v[i]]++;
	
	vector<pii> dp;
	
	int total = 0;
	for (int i=100000; i>0; --i) {
		total += cnt[i];
		if (cnt[i]) dp.pb({i, cnt[i]});
	}
	
	wyn = inf;
	recurse(dp, 0, 1, 1, n1, n2, 0);
	n1 = sufit(a, h);
	n2 = sufit(b, w);
	recurse(dp, 0, 1, 1, n1, n2, 0);
	
	if (wyn == inf) cout << "-1\n";
	else cout << wyn << endl;
}

int main() {
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}