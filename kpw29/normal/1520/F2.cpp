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
const int maxn = 200100;

const int BLOCK = 20;
int result[maxn], psum[maxn];
int X[maxn], Y[maxn];
int dr[maxn];

int zeros(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	int ans;
	cin >> ans;
	
	return r - l + 1 - ans;
}

set <int> s;

inline void add(int p, int v) {
	for (; p < maxn; p += p & (-p)) dr[p] += v;
}

inline int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}


int main() {
	int n, t, szukane;
	cin >> n >> t >> szukane;
	int MAXBLOCK = 0;
	for (int bl=1; bl<=10000; ++bl) {
		int x = BLOCK * (bl - 1) + 1;
		int y = BLOCK * bl; y = min(y, n);
		if (x > n) break;
		MAXBLOCK = bl;
		X[bl] = x; Y[bl] = y;
		result[bl] = zeros(x, y); //this many zeros are there in the block
		psum[bl] = psum[bl - 1] + result[bl];
	}
	
	for (int step = 1; step <= t; ++step) {
		if (step > 1) cin >> szukane;
		
		int xx = 1, yy = MAXBLOCK;
		while (xx < yy) {
			int mid = (xx + yy) / 2;
			if (psum[mid] - get(Y[mid]) < szukane) xx = ++mid;
			else yy = mid;
		}
		
		// now search in this block
		
		int poprzednie = psum[xx - 1] - get(X[xx] - 1);
		szukane -= poprzednie;
		assert(szukane > 0);
		
		int x = X[xx], y = Y[xx];
		while (x < y) {
			int mid = (x + y) / 2;
			if (zeros(X[xx], mid) < szukane) x = ++mid;
			else y = mid;
		}
		
		cout << "! " << x << endl;
		add(x, 1);
	}
}