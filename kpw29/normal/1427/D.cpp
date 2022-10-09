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

const int maxn = 55;
int n, m, a, b, c;

int pos[maxn], tab[maxn];
int nowe[maxn], LEN = 0;
vector <vector <int> > moves;

bool ok() {
	FOR(i, 1, n)
		if (tab[i] != i) return false;
	
	return true;
}

void execute(vector <int> op) {
	moves.push_back(op);
	
	LEN = 0; int OST = n;
	for (int i=op.size()-1; i>=0; --i) {
		int ile = op[i];
		int ST = OST - ile + 1;
		
		for (int j = 0; j < ile; ++j) nowe[++LEN] = tab[ST + j];
		OST -= ile;
	}

	assert(LEN == n);
	assert(OST == 0);
	FOR(i, 1, n) tab[i] = nowe[i];
}

void move() {
	FOR(i, 1, n) pos[tab[i]] = i;
	FOR(i, 2, n)
		if (pos[i] < pos[i-1]) {
			//this move is ok
			
			int x = pos[i], y = pos[i - 1], bg = y;
			while (tab[bg-1] + 1 == tab[bg]) --bg;
			
			vector <int> op = {};
			if (x > 1) op.push_back(x - 1);
			op.push_back(bg - x);
			op.push_back(y - bg + 1);
			if (y != n) op.push_back(n - y);
			
			execute(op);
			return;
		}
}

void solveone() {
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	
	while (!ok()) move();
	
	cout << (int)moves.size() << endl;
	for (auto &u : moves) {
		cout << u.size() << "\n";
		for (auto &elem : u) cout << elem << ' ';
		cout << "\n";
	}
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}