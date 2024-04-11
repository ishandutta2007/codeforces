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
const int inf = 1e9+9;

//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n, c, d;
	cin >> n >> c >> d;
	vector<pii> can_c, can_d;
	
	FOR(i, 1, n) {
		int beauty, cost;
		cin >> beauty >> cost;
		char type;
		cin >> type;
		if (type == 'C') {
			if (cost <= c) can_c.pb({beauty, cost});
		}
		else {
			if (cost <= d) can_d.pb({beauty, cost});
		}
	}
	
	auto get_best = [&](vector <pii> &v, int budget)-> int{
		int best = -1;
		trav(elem, v) {
			if (elem.e2 <= budget) best = max(best, elem.e1);
		}
		return best;
	};
	
	auto ans = [&](vector <pii> &v, int budget) {
		vector <pii> best(100500, {-1, -1});
		int xdd = -inf;
		
		auto cmp = [&](int a, int b) {
			if (a == -1) return b;
			if (b == -1) return a;
			if (v[a].e1 >= v[b].e1) return a;
			return b;
		};
		
		for (int i=0; i<sz(v); ++i) {
			int gdzie = v[i].e2;
			if (cmp(i, best[gdzie].e1) == i) best[gdzie].e2 = best[gdzie].e1, best[gdzie].e1 = i;
			else if (cmp(i, best[gdzie].e2) == i) best[gdzie].e2 = i;
		}
		
		FOR(i, 1, 100000) {
			int opt = best[i-1].e1;
			if (opt != -1 && opt != best[i].e1 && opt != best[i].e2) {
				if (cmp(opt, best[i].e1) == opt) best[i].e2 = best[i].e1, best[i].e1 = opt;
				else if (cmp(opt, best[i].e2) == opt) best[i].e2 = opt;
			}
			opt = best[i-1].e2;
			if (opt != -1 && opt != best[i].e1 && opt != best[i].e2) {
				if (cmp(opt, best[i].e1) == opt) best[i].e2 = best[i].e1, best[i].e1 = opt;
				else if (cmp(opt, best[i].e2) == opt) best[i].e2 = opt;
			}
		}
		
		for (int i=0; i<sz(v); ++i) {
			pii elem = v[i];
			assert(elem.e2 <= budget);
			int score = elem.e1;
			int b = budget - elem.e2;
			if (best[b].e1 != -1 && best[b].e1 != i) xdd = max(xdd, score + v[best[b].e1].e1);
			if (best[b].e2 != -1 && best[b].e2 != i) xdd = max(xdd, score + v[best[b].e2].e1);
		}
		
		return xdd;
	};
	
	int a1 = get_best(can_c, c);
	int a2 = get_best(can_d, d);
	
	if (a1 == -1) cout << max(0, ans(can_d, d)) << endl;
	else if (a2 == -1) cout << max(0, ans(can_c, c)) << endl;
	else {
		int o1 = ans(can_d, d);
		int o2 = ans(can_c, c);
		int tmp = max(o1, o2);
		tmp = max(tmp, 0);
		cout << max(a1 + a2, tmp) << "\n";
	}
}

int main() {
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}