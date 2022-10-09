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
typedef vector<int> vi;
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}
const int maxn = 3010;
int n, m, k, a, b, c;
string s;

int tab[maxn];

PII help[maxn];

int place[maxn];

void swapNumbers(int x, int y) {
	int px = place[x], py = place[y];
	swap(tab[px], tab[py]);
	cout << min(px, py) << ' ' << max(px, py) << "\n";
	swap(place[x], place[y]);
}

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
		help[i] = {tab[i], i};
	}
	
	sort(help+1, help+n+1);
	int inv = 0;

	FOR(i, 1, n) {
		tab[help[i].e2] = i;
		place[i] = help[i].e2;
	}
	
	FOR(i, 1, n)
		FOR(j, i + 1, n)
			if (place[i] > place[j]) ++inv;
	
	cout << inv << "\n";
	FOR(i, 1, n) {
		int value = tab[i];
		for (int j = value - 1; j >= i; --j) swapNumbers(j, j + 1);
	}
	
	FOR(i, 1, n) assert(tab[i] == i);
}