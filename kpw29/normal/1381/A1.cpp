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

const int maxn = 1000010;

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

string s;
int tab[maxn];
int m, k;

string a, b;
void do_oper(int ile) {
	for (int i = 0; i < ile; ++i) {
		if (a[i] == '1') a[i] = '0';
		else a[i] = '1';
	}
	
	reverse(a.begin(), a.begin()+ile);
}

void solveone() {
	int n;
	cin >> n >> a >> b; 
	
	vector <int> oper;
	
	int turn = 0;
	int next_low = 0, next_high = n - 1;
	
	int total_swaps = 0;
	for (int i = n - 1; i >= 0; --i) {
		int is_there = 0;
		
		if (turn % 2 == 0) {
			is_there = a[next_low] - '0';
			++next_low;
		}
		else {
			is_there = a[next_high] - '0';
			--next_high;
		}
		
		is_there ^= 1; //oper toggles
		if (total_swaps % 2 == 1) is_there ^= 1;
		if (b[i] - '0' != is_there) {
			oper.push_back(1);
		}
		
		oper.push_back(i + 1);
		total_swaps++;
		
		++turn;
	}
	
	cout << (int)oper.size() << ' ';
	for (auto u : oper) cout << u << ' ';
	cout << "\n"; 
	
	//for (auto u : oper) do_oper(u);
	//for (int i=0; i<n; ++i) assert(a[i] == b[i]);
}

int main() {
	boost;
	int tests;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}