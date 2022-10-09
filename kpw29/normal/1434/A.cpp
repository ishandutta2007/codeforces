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

bool cmp(pair <int, PII> a, pair <int, PII> b) {
	if (a.e1 != b.e1) return a.e1 < b.e1;
	return a.e2 > b.e2;
}

void solve() {
	int n;
	vector <int> a(7);
	FOR(i, 1, 6) cin >> a[i];
	sort(a.begin()+1, a.end());
	debug(a);
	
	cin >> n;
	vector <int> v(n);
	rep(i, 0, n) cin >> v[i];
	
	vector <pair <int, PII> > options;
	multiset <int> q;
	
	FOR(fir, 1, 6) {
		rep(i, 0, n) {
			int note_played = v[i] - a[fir];
			options.pb({note_played, {i, fir}});
			if (fir == 6) q.insert(note_played);
		}
	}
	
	sort(all(options), cmp);
	int result = 2e9;
	
	trav(opcja, options) {
		if (q.empty()) break;
		int best = *(--q.end());
		result = min(result, best - opcja.e1);
		q.erase(q.find(opcja.e1));
		int i = opcja.e2.e1;
		int fir = opcja.e2.e2;
		if (fir == 1) break;
		else q.insert(v[i] - a[fir - 1]);
	}
	
	cout << result << "\n";
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