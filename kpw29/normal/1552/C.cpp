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

bool cross(PII pie, PII dru) {
	if (pie.e1 > dru.e1) swap(pie, dru);
	return pie.e1 < dru.e1 && dru.e1 < pie.e2 && pie.e2 < dru.e2;
}

ll calc(vector <PII> &points) {
	int res = 0;
	int sz = points.size();
	rep(i, 0, sz) {
		if (points[i].e1 > points[i].e2) swap(points[i].e1, points[i].e2);
	}
	
	for (int i=0; i<sz; ++i) {
		for (int j=i+1; j<sz; ++j) {
			if (cross(points[i], points[j])) ++res;
		}
	}
	
	return res;
}

void solve() {
	int n, k;
	
	cin >> n >> k;
	vector <PII> points;
	vector <bool> jest(2 * n + 1, false);
	vi sa;
	
	FOR(i, 1, k) {
		int a, b;
		cin >> a >> b;
		points.pb({a, b});
		jest[a] = 1; jest[b] = 1;
	}
	
	FOR(i, 1, 2 * n) {
		if (!jest[i]) sa.pb(i);
	}
	
	int sz = sa.size() / 2;
	for (int i=0; i<sz; ++i) {
		points.pb({sa[i], sa[i + sz]});
	}

	cout << calc(points) << "\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	while (tests--) {
		solve();
	}
}