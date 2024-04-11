#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
typedef pair<pii, int> ppi;

typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}


int L, R;

int MX = 0;
vector <ppi> edges;

const int XDD = 1e6;

void add_edge(int i, int j, int LEN) {
	MX = max(MX, j);
	edges.push_back(mp(mp(i, j), min(LEN, XDD)));
}

int fun(int x) {
	if (x == 0) return 1;
	return (1 << (x - 1));
}

int main() {
	MX = 0;
	cin >> L >> R;
	int diff = (L - 1);
	int N = R - (L - 1);
	//we need to build lengths from 1 to N
	
	for (int i=1; i<=25; ++i) {
		int goal = fun(i);
		for (int j=i-1; j>=0; --j) {
			if (goal > 1) goal /= 2;
			add_edge(j, i, goal);
		}
	}
	
	int SPECIAL = 26;
	int SO_FAR = 1;
	
	add_edge(0, SPECIAL, 1);
	N--;
	
	for (int bit = 1; bit < 26; ++bit) {
		if (N & (1 << (bit - 1))) {
			add_edge(bit, SPECIAL, SO_FAR);
			SO_FAR += fun(bit);
		}
	}
	
	if (diff != 0) {
		add_edge(SPECIAL, SPECIAL+1, diff);
	}
	
	cout << "YES\n";
	cout << MX + 1 << ' ' << (int)edges.size() << "\n";
	for (auto u : edges) cout << 1 + u.e1.e1 << ' ' << 1 + u.e1.e2 << ' ' << u.e2 << "\n";
}