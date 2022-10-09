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
typedef unsigned long long ull;

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
const int LIM = (int)(sqrt(1e9)) + 1;

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}



ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

//Did you REAALLY consider sample tests?
int cnt[LIM + 1];
map <int, int> duze;
const ll INF = 1e18;

void solve(int tc) {
	int n;
	ll a, b;
	cin >> n >> a >> b;
	vector<int> arr(n);
	set <int> factors;
	rep(i, 0, n) cin >> arr[i];
	FOR(delta, -1, 1) {
		int value = arr[0] + delta;
		auto pierwsze = factor(value);
		trav(pr, pierwsze) factors.insert(pr);
	}
	FOR(delta, -1, 1) {
		int value = arr[n-1] + delta;
		auto pierwsze = factor(value);
		trav(pr, pierwsze) factors.insert(pr);
	}
	
	debug(factors);
	auto cost = [&](int i, int pr)->ll{
		if (arr[i] % pr == 0) return -a;
		if ((arr[i] - 1) % pr == 0 || (arr[i] + 1) % pr == 0) return -a+b;
		return INF;
	};
		
	ll c1 = INF;
	ll base_cost = a * n; //everyone removed
	
	trav(pr, factors) {
		vll pref(n + 1, 0); //wezme i
		vll best(n+1, INF);
		best[0] = 0; 
		FOR(i, 1, n) {
			pref[i] = pref[i-1] + cost(i-1, pr);
			pref[i] = min(pref[i], INF);
			best[i] = min(pref[i], best[i-1]);
		}
		debug(pr);
		debug(pref);
		debug(best);
		
		ll curr = 0;
		for (int i=n; i>=0; --i) {
			c1 = min(c1, base_cost + best[i] + curr);
			if (i > 0) curr += cost(i - 1, pr);
			if (curr > INF) break;
		}
	}
	
	cout << c1 << endl;
}

int main() {
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}