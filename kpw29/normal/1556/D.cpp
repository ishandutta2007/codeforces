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
ll init[100];

bool LOCAL = 0;
ll get_sum(int i, int j) {
	cout << "and " << i + 1 << ' ' << j + 1 << endl;
	ll ans = 0;
	if (LOCAL) ans = (init[i] & init[j]);
	else cin >> ans;
	
	cout << "or " << i + 1 << ' ' << j + 1 << endl;
	ll odp = 0;
	if (LOCAL) odp = (init[i] | init[j]);
	else cin >> odp;
	return ans + odp;
}

ll s[3];

int main() {
	int n, k;
	cin >> n >> k;
	if (LOCAL) {
		rep(i, 0, n) cin >> init[i];
	}
	
	vll vec(n);
	ll a = get_sum(0, 1);
	ll b = get_sum(0, 2);
	ll c = get_sum(1, 2);
	
	ll all = a + b + c;
	assert(all % 2 == 0);
	all /= 2;
	vec[0] = all - c;
	vec[1] = all - b;
	vec[2] = all - a;
	rep(i, 3, n) vec[i] = get_sum(i, 0) - vec[0];
	debug(vec);
	
	sort(all(vec));
	cout << "finish " << vec[k - 1] << endl;
}