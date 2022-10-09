#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;

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
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 1000100;

int typ[maxn];
int a[maxn], b[maxn];

const int mod = 998244353;

void addmod(int &x, int val) {
	while (val >= mod) val -= mod;
	x += val;
	while (x >= mod) x -= mod;
}

ll przejde[maxn];
int delta[maxn];

void solve() {
	int n;
	map <int, int> skal;
	
	cin >> n;
	vector <int> values;
	vector <int> pierw(2 * n + 1, 0);
	
	vector <PII> points;
	
	FOR(i, 1, n) {
		cin >> b[i] >> a[i];
		values.pb(a[i]);
		values.pb(b[i]);
		cin >> typ[i];
	}
	
	ll result = 0;
	sort(all(values));
	rep(i, 0, (int)values.size()) {
		skal[values[i]] = i + 1;
		pierw[i + 1] = values[i];
	}
	
	points.pb({0, 0});
	FOR(i, 1, n) {
		points.pb({skal[a[i]], -i});
		points.pb({skal[b[i]], i});
	}
	
	sort(all(points));
	int N = 2 * n;
	assert(sz(points) == N + 1);
	
	for (int kt = N; kt > 0; --kt) {
		
		if (points[kt].e2 < 0) { //lewy koniec
			int i = -points[kt].e2;
			addmod(delta[kt], mod - przejde[i]);
			
			ll ile_razy = (delta[kt] + 1) % mod; //nothing stops me...
			result += ile_razy * (pierw[points[kt].e1] - pierw[points[kt-1].e1]);
			result %= mod;
		}
		else { //prawy koniec
			ll musze_przejsc = (delta[kt] + 1) % mod;
			int i = points[kt].e2;
			ll ile_razy = 0;
			
			if (typ[i]) ile_razy = (musze_przejsc * 2) % mod;
			else ile_razy = (musze_przejsc * 2 + mod - 1) % mod;
			
			ll wasted = (ile_razy - musze_przejsc + mod) % mod;
			przejde[i] = wasted;
			addmod(delta[kt - 1], wasted);
			// tyle razy przejde
			result += ile_razy * (pierw[points[kt].e1] - pierw[points[kt-1].e1]);
			result %= mod;
		}
		
		addmod(delta[kt - 1], delta[kt]);
	}
	
	cout << (result + 1) % mod;
	
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}