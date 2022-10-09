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

int tests;
int n;
bool gra[maxn], curr[maxn];
int dp[maxn];

int solve() {
	int st = 2;
	while (st <= n && gra[st] == gra[1]) ++st;
	
	if (st == n + 1) {
		return 1 + (n - 1) / 3;
	}
	
	vector <int> res;
	int fro = st - 1;
	int ile = 1;
	
	
	for (int i=st + 1; i <= n; ++i) {
		if (gra[i] == gra[i - 1]) ++ile;
		else {
			res.push_back(ile);
			ile = 1;
		}
	}
	
	if (gra[n] == gra[1]) {
		res.push_back(ile + fro);
	}
	else {
		res.push_back(ile);
		res.push_back(fro);
	}
	
	//debug(res);
	int wn = 0;
	for (auto u : res) wn += u / 3;
	return wn;
}

void solveone() {
	string s;
	cin >> n >> s;
	FOR(i, 1, n)
		if (s[i - 1] == 'L') gra[i] = 1;
		else gra[i] = 0;
		
	int wyn = solve();
	
	cout << wyn << "\n";
}

int main() {
	boost;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}