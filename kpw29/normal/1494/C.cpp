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
const int mod = 998244353;
const int inf = 1e9+9;
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 1000100;
int n, m;


int solve(vector <int> &v, vector <int> &pos) {
	if (pos.empty() || v.empty()) return 0;
	sort(v.begin(), v.end());
	sort(pos.begin(), pos.end());
	
	debug(v, pos);
	int best = 0;
	vector <int> score(pos.size());
	for (int i=pos.size()-1; i>=0; --i) {
		int rest = 0;
		if (i != pos.size() - 1) rest = score[i + 1];
		score[i] = rest + binary_search(v.begin(), v.end(), pos[i]);
	}
	
	int it = 0;
	
	best = max(best, score[0]);
	for (int i=0; i<pos.size(); ++i) {
		while (it < v.size() && v[it] <= pos[i]) ++it;
		int sc = 0;
		if (i != pos.size() - 1) sc = score[i + 1];
		int f0 = 0;
		if (it != 0) f0 = lower_bound(pos.begin(), pos.end(), pos[i]) - lower_bound(pos.begin(), pos.end(), pos[i] - it + 1) + 1;
		best = max(best, f0 + sc);
	}
	
	return best;
}

void solveone() {
	cin >> n >> m;
	vector <int> pos, neg, spe_pos, spe_neg;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		if (a < 0) neg.pb(-a);
		else pos.pb(a);
	}
	
	FOR(i, 1, m) {
		int b;
		cin >> b;
		if (b < 0) spe_neg.pb(-b);
		else spe_pos.pb(b);
	}
	
	cout << solve(pos, spe_pos) + solve(neg, spe_neg) << "\n";
		
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}