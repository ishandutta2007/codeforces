#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
int n;
const int maxn = 100100;

vector <PLL> tab;
ll det(int i, int j) {
	return tab[i].e1 * tab[j].e2 - tab[i].e2 * tab[j].e1;
}

ll is_left(int i, int j, int k) {
	return (det(i, j) + det(j, k) + det(k, i)) > 0;
}
vector <int> hull;

map <ll, ll> M;

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) {
		ll x, y;
		cin >> x >> y;
		ll g = -INF;
		if (M.find(x) != M.end()) g = M[x];
		M[x] = max(g, y - x * x);
	}
	
	for (PLL elem : M) {
		tab.pb(elem);
	}
	
	int sz = tab.size();
	sort(all(tab));
	for (int i=sz-1; i>=0; --i) {
		while (hull.size() > 1 && !is_left(hull[hull.size() - 2], hull.back(), i)) hull.pop_back();
		hull.pb(i);
	}
	
	cout << max(0, (int)hull.size() - 1) << endl;
}