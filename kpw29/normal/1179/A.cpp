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
	int n, m;
	cin >> n;
	
	int zap;
	cin >> zap;
	deque<int> q;
	rep(i, 0, n) {
		int a;
		cin >> a;
		q.push_back(a);
	}
	
	vector<pii> ruszone;
	
	auto iter = [&]() {
		int a = q.front(); q.pop_front();
		//ruszone.pb(a);
		int b = q.front(); q.pop_front();
		//ruszone.pb(b);
		ruszone.pb({a, b});
		if (a > b) {
			q.push_front(a);
			q.push_back(b);
		}
		else {
			q.push_front(b);
			q.push_back(a);
		}
	};
	
	rep(step, 0, 5 * n) {
		iter();
	}
	
	while (sz(ruszone) % (n - 1) != 0) {
		iter();
	}
	int current = sz(ruszone) - 1;
	rep(i, 0, n-1) iter();
	
	debug(ruszone);
	//period is n - 1 now
	while (zap--) {
		ll x;
		cin >> x;
		pii ans;
		if (x <= sz(ruszone)) ans = ruszone[x - 1];
		else {
			int reszta = (x - sz(ruszone)) % (n - 1);
			ans = ruszone[current + reszta];
		}
		cout << ans.e1 << ' ' << ans.e2 << "\n";
	}
	
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