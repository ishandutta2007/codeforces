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

const int maxn = 2010;
int n, p, k;
ll x, y;
int tab[maxn][maxn];
int rowmin[maxn], rowmax[maxn], colmin[maxn], colmax[maxn];
int rowminall, rowmaxall, colminall, colmaxall;

int result[10];

void reset() {
	FOR(i, 0, n) rowmin[i] = colmin[i] = INT_MAX;
	FOR(i, 0, n) rowmax[i] = colmax[i] = INT_MIN;
	rowminall = colminall = INT_MAX;
	rowmaxall = colmaxall = INT_MIN;
}

int row_area(int x, int y, int row) {
	int best = max(row - 1, n - row);
	return abs(x - y) * best;
}

int col_area(int x, int y, int row) {
	int best = max(row - 1, n - row);
	return abs(x - y) * best;
}

int area_(int c1, int c2, int row, int other) {
	return abs(c1 - c2) * abs(row - other);
}

void solveone() {
	cin >> n;
	string s;
	FOR(i, 1, n) {
		cin >> s;
		FOR(j, 1, n) tab[i][j] = s[j - 1] - '0';
	}
	FOR(i, 0, 9) result[i] = 0;
	if (n > 1) 
	FOR(digit, 0, 9) {
		reset();
		FOR(i, 1, n)
			FOR(j, 1, n) {
				if (tab[i][j] != digit) continue;
				rowmin[i] = min(rowmin[i], j);
				rowmax[i] = max(rowmax[i], j);
				
				colmin[j] = min(colmin[j], i);
				colmax[j] = max(colmax[j], i);
				
				rowminall = min(rowminall, i);
				rowmaxall = max(rowmaxall, i);
				
				colminall = min(colminall, j);
				colmaxall = max(colmaxall, j);
			}
			
		FOR(i, 1, n)
			FOR(j, 1, n) {
				if (tab[i][j] != digit) continue;
				if (rowmin[i] != j) {
					result[digit] = max(result[digit], row_area(j, rowmin[i], i));
				}
				
				if (rowmax[i] != j) {
					result[digit] = max(result[digit], row_area(j, rowmax[i], i));
				}
				
				if (colmin[j] != i) {
					result[digit] = max(result[digit], col_area(i, colmin[j], j));
				}
				
				if (colmax[j] != i) {
					result[digit] = max(result[digit], col_area(i, colmax[j], j));
				}
				
				if (rowminall != i) {
					result[digit] = max(result[digit], area_(1, j, i, rowminall));
					result[digit] = max(result[digit], area_(n, j, i, rowminall));
				}
				
				if (colminall != j) {
					result[digit] = max(result[digit], area_(1, i, j, colminall));
					result[digit] = max(result[digit], area_(n, i, j, colminall));
				}
				
				if (rowmaxall != i) {
					result[digit] = max(result[digit], area_(1, j, i, rowmaxall));
					result[digit] = max(result[digit], area_(n, j, i, rowmaxall));
				}
				
				if (colmaxall != j) {
					result[digit] = max(result[digit], area_(1, i, j, colmaxall));
					result[digit] = max(result[digit], area_(n, i, j, colmaxall));
				}
			}
	}
	
	FOR(i, 0, 9) cout << result[i] << ' ';
	cout << "\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}