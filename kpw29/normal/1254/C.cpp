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
mt19937_64 rng(0);
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


bool LOCAL = 0;
ll X[maxn], Y[maxn];
int n;

inline ll det(int i, int j) {
	return X[i] * Y[j] - X[j] * Y[i];
}

inline ll area(int i, int j, int k) {
	return abs(det(i,j) + det(j,k) + det(k, i));
}

int ask_sign(int i, int j, int k) {
	cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
	if (LOCAL) {
		ll xa = X[j] - X[i];
		ll xb = X[k] - X[i];
		ll ya = Y[j] - Y[i];
		ll yb = Y[k] - Y[i];
		
		ll det = xa * yb - xb * ya;
		if (det > 0) return 1;
		else return -1;
	}
	
	int odp;
	cin >> odp;
	return odp;
}


ll ask_area(int i, int j, int k) {
	cout << 1 << ' ' << i << ' ' << j << ' ' << k << endl;
	if (LOCAL) {
		return area(i, j, k);
	}
	
	ll odp;
	cin >> odp;
	return odp;
}

vector <int> order;
ll tab[1010];
ll znak[1010];
int perm[1010];
int DL;

vector <int> solve(int lewy, int prawy, vector <int> pozycje) {
	debug(lewy, prawy, pozycje);
	
	if (pozycje.empty()) return {};
	int kt = 0;
	for (int i=1; i<(int)pozycje.size(); ++i) {
		if (tab[pozycje[i]] > tab[pozycje[kt]]) kt = i;
	}
	
	//ok, mamy maxa
	vector <PLL> lewe, prawe;
	
	for (int i=0; i<(int)pozycje.size(); ++i) {
		if (i == kt) continue;
		int node = pozycje[i];
		int sgn = ask_sign(lewy, pozycje[kt], node);
		if (sgn == -1) prawe.pb({tab[node], node});
		else lewe.pb({-tab[node], node});
	}
	
	sort(all(lewe));
	sort(all(prawe));
	
	vector <int> res = {};
	trav(node, prawe) res.pb(node.e2);
	res.pb(pozycje[kt]);
	trav(node, lewe) res.pb(node.e2);
	
	return res;
}

int main() {
	cin >> n;
	if(LOCAL) {
		FOR(i, 1, n) cin >> X[i] >> Y[i];
	}
	
	FOR(i, 3, n) tab[i] = ask_area(1, 2, i);
	FOR(i, 3, n) znak[i] = ask_sign(1, 2, i);
	
	vector <int> minuses = {};
	vector <int> pluses = {};
	
	FOR(i, 3, n) {
		if (znak[i] > 0) pluses.pb(i);
		else minuses.pb(i);
	}
	
	auto ans_first = solve(1, 2, minuses);
	debug(ans_first);
	auto ans_second = solve(2, 1, pluses);
	debug(ans_second);
	
	cout << 0 << ' ' << 1 << ' ';
	trav(node, ans_first) cout << node << ' ';
	cout << 2 << ' '; 
	trav(node, ans_second) cout << node << ' ';
	cout << endl;
}