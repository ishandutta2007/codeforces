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
bool TEST = 0;
ll brut(vi vec, vi zbior) {
	set<vi> odw;
	odw.insert(vec);
	queue<vi> q;
	q.push(vec);
	int n = sz(vec);
	
	ll best = LLONG_MIN;
	while (!q.empty()) {
		vi x = q.front();
		q.pop();
		for (auto b : zbior) {
			rep(i, 0, n) {
				int j = i + b - 1;
				if (j >= n) break;
				vi cp = x;
				for (int k = i; k <= j; ++k) cp[k] *= -1;
				if (odw.find(cp) == odw.end()) {
					odw.insert(cp);
					q.push(cp);
				}
			}
		}
	}
	
	for (auto u : odw) {
		ll sum = 0;
		for (auto elem : u) sum += elem;
		best = max(best, sum);
	}
	
	return best;
}

//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n, m;
	if (!TEST) cin >> n >> m;
	else n = random(2, 10), m = random(1, 3);
	vi vec(n);
	rep(i, 0, n) {
		if (!TEST) cin >> vec[i];
		else vec[i] = random(-3, 3);
	}
	
	int g = 0;
	vi zbior;
	rep(i, 0, m) {
		int a;
		if (!TEST) cin >> a;
		else a = random(1, n / 2);
		zbior.pb(a);
		g = __gcd(a, g);
	}
	
	debug(g);
	if (g == 1) {
		ll sum = 0;
		rep(i, 0, n) sum += abs(vec[i]);
		TCOUT(sum);
	}
	
	ll res = 0;
	int k = g;
	vll res_flip = {0, 0};
	
	for (int i=0; i<k; ++i) {
		vi values;
		for (int j=i; j<n; j+=k) values.pb(vec[j]);
		debug(values);
		
		int negatives = 0;
		ll sumabs = 0;
		trav(u, values) {
			if (u < 0) ++negatives;
			sumabs += abs(u);
		}
		
		bool sign_last_character = (negatives % 2);
		for (int flipuje = 0; flipuje < 2; ++flipuje) {
			res_flip[flipuje] += sumabs;
			if ((flipuje ^ sign_last_character) == 1) { //jednak bede z minusem
				vi absy = values;
				for (auto&u : absy) u = abs(u);
				sort(all(absy));
				debug(absy);
				res_flip[flipuje] -= 2LL * absy[0];
			}
		}
	}
	
	res = max(res_flip[0], res_flip[1]);
	if (TEST) {
		ll br = brut(vec, zbior);
		if (br != res) {
			debug("WA");
			debug(br, res);
			debug(vec);
			debug(zbior);
			exit(0);
		}
	}
	
	cout << res << "\n";
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