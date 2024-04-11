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


const int maxn = 1000100;
const int R = (1 << 18);
int tab[maxn];

int dr[2 * R + 5];
const int RANGE = 1e7+3;
int pr[RANGE];

void insert(int x, int val) {
	x += R - 1;
	dr[x] = val;
	x /= 2;
	
	while (x) {
		dr[x] = min(dr[2 * x], dr[2 * x + 1]);
		x /= 2;
	}
}

int query(int x, int y) {
	x += R-1; y += R-1;
	int res = min(dr[x], dr[y]);
	if (x == y) return res;
	while (x + 1 < y) {
		if (!(x&1)) res = min(res, dr[x + 1]);
		if (y & 1) res = min(res, dr[y - 1]);
		x >>= 1; y >>= 1;
	}
	
	return res;
}



int get_cannon(int x) {
	int res = 1;
	
	while (x > 1) {
		//debug(x);
		int dv = pr[x];
		int cnt = 0;
		while (x % dv == 0) {
			//debug(x, dv);
			x /= dv;
			++cnt;
		}
		
		if (cnt % 2 == 1) res = res * dv;
	}
	
	return res;
}

int first[RANGE];
int bad[maxn];
int dp[maxn];

void solveone() {
	int _, n;
	cin >> n >> _;
	FOR(i, 1, n) {
		cin >> tab[i];
		tab[i] = get_cannon(tab[i]);
	}

	int lt = 1, res = 1;
	FOR(i, 1, n) {
		if (first[tab[i]] != 0) {
			++res;
			FOR(j, lt, i - 1) first[tab[j]] = 0;
			lt = i;
		}

		first[tab[i]] = i;

	}
		
	FOR(i, 1, n) first[tab[i]] = 0;
	cout << res << "\n";
}


int main() {
	boost;
	for (int i=1; i<RANGE; ++i) pr[i] = i;
	for (int i=2; i<RANGE; ++i) {
		if (pr[i] == i) {
			for (int j=i; j<RANGE; j+=i) {
				if (pr[j] == j) pr[j] = i;
			}
		}
	}
	
	//FOR(i, 1, 10) cout << get_cannon(i) << ' ';
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}