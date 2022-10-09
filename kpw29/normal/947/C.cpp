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

int ILE = 1;
int tree[300000 * 30 + 2][2];
int ile[300000 * 30 + 2];
int A[maxn], B[maxn];

void add(int x) {
	int gdzie = 1;
	for (int step = 29; step >= 0; --step) {
		++ile[gdzie];
		int bit = 0;
		if (x & (1 << step)) bit = 1;
		if (!tree[gdzie][bit]) tree[gdzie][bit] = ++ILE;
		gdzie = tree[gdzie][bit];
	}
	
	++ile[gdzie];
}

int query(int x) {
	int gdzie = 1;
	int res = 0;
	ile[gdzie]--;
	
	for (int step = 29; step >= 0; --step) {
		int desired_bit = 0;
		if (x & (1 << step)) desired_bit = 1;
		if (!tree[gdzie][desired_bit] || ile[tree[gdzie][desired_bit]] == 0) {
			desired_bit ^= 1;
			res += (1 << step);
		}
		
		gdzie = tree[gdzie][desired_bit];
		ile[gdzie]--;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> A[i];
	FOR(i, 1, n) {
		cin >> B[i];
		add(B[i]);
	}
	
	FOR(i, 1, n) {
		int r = query(A[i]);
		cout << r << ' ';
	}
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