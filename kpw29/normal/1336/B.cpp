#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;

const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

const int maxn = 1010000;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k, T;

vi red, green, blue;

inline ll sq(ll value) {
	return value * value;
}

ll solve(vi &low, vi &mid, vi &high) {
	ll RES = INF;
	int na = low.size(), nc = high.size();
	int iterlow = 0, iterhigh = 0;
	for (auto u : mid) {
		while (iterlow + 1 < na && low[iterlow + 1] <= u) ++iterlow;
		while (iterhigh + 1 < nc && high[iterhigh] < u) ++iterhigh;
		RES = min(RES, sq(low[iterlow] - u) + sq(high[iterhigh] - u) + sq(high[iterhigh] - low[iterlow]));
	}
	
	return RES;
}

int main() {
	boost;
	cin >> T;
	while (T--) {
		int na, nb, nc;
		cin >> na >> nb >> nc;
		red.resize(na);
		FOR(i, 1, na) cin >> red[i - 1];
		green.resize(nb);
		FOR(i, 1, nb) cin >> green[i - 1];
		blue.resize(nc);
		FOR(i, 1, nc) cin >> blue[i - 1];
		sort(blue.begin(), blue.end());
		sort(red.begin(), red.end());
		sort(green.begin(), green.end());
		
		ll val = solve(red, green, blue);
		val = min(val, solve(red, blue, green));
		
		val = min(val, solve(blue, green, red));
		val = min(val, solve(green, blue, red));
		
		val = min(val, solve(blue, red, green));
		val = min(val, solve(green, red, blue));
		
		cout << val << "\n";
	}
	
}