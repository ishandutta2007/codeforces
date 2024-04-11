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

const int maxn = 305;
ll n, m, k;

int tab[maxn][maxn];
int value[3];
int mna[3];

void solveone() {
	cin >> n;
	FOR(i, 1, n+1)
		FOR(j, 0, n+1) tab[i][j] = 0;
	FOR(i, 0, 2) value[i] = 0, mna[i] = 0;
	
	int ka = 0;
	FOR(i, 1, n) {
		string s;
		cin >> s;
		FOR(j, 1, n) {
			if (s[j - 1] == '.') tab[i][j] = 0;
			if (s[j - 1] == 'X') tab[i][j] = 1, ++ka, value[(i + j) % 3]++;
			if (s[j - 1] == 'O') tab[i][j] = -1, ++ka, mna[(i + j) % 3]++;
		}
	}
	
	bool flag = 0;
	FOR(a, 0, 2)
		FOR(b, 0, 2) {
			if (a == b || flag) continue;
			if (value[a] + mna[b] <= (ka / 3)) {
				//debug("HERE");
				flag = 1;
				FOR(i, 1, n)
					FOR(j, 1, n) {
						if (tab[i][j] == 1 && (i + j) % 3 == a) tab[i][j] = -1;
						if (tab[i][j] == -1 && (i + j) % 3 == b) tab[i][j] = 1;
					}
				
			}
		}
	
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			if (tab[i][j] == 1) cout << "X";
			if (tab[i][j] == -1) cout << "O";
			if (tab[i][j] == 0) cout << ".";
		}
		cout << "\n";
	}
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}