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
int DL = 0, stos[maxn];
vector <int> oper;
int MEX[maxn];
int jest[maxn];

int getMex() {
	FOR(i, 0, 3000) MEX[i] = 0;
	
	FOR(i, 1, n) {
		MEX[tab[i]] = 1;
	}
	
	int mx = 0;
	while (MEX[mx]) ++mx;
	return mx;
}

void sub(int index) {
	int val = getMex();
	tab[index] = val;
	//cout << "Swapping " << index << " for " << val << endl;
	oper.push_back(index);
}

inline bool ok() {
	FOR(i, 1 ,n-1)
		if (tab[i] > tab[i + 1]) return false;
	
	return true;
}

int main() {
	boost;
	int t;
	cin >> t;
	FOR(z, 1, t) {
		cin >> n;
		oper.clear();
		FOR(i, 0, n) jest[i] = 0;
		
		FOR(i, 1, n) cin >> tab[i];
		FOR(i, 1, n) {
			if (jest[tab[i]] || tab[i] == n) sub(i);
			jest[tab[i]] = 1;
		}
		
		int buffer = getMex();
		
		while (!ok()) {
			//FOR(i, 1, n) cout << tab[i] << ' ';
			//cout << endl;
			
			if (buffer == n) {
				FOR(i, 1, n) {
					if (tab[i] != i - 1) {
						buffer = tab[i];
						sub(i);
						break;
					}
				}
			}
			else {
				int pre = buffer;
				buffer = tab[buffer + 1];
				sub(pre + 1);
			}
		}
		
		cout << (int)oper.size() << "\n";
		for (auto u : oper) cout << u << ' ';
		cout << "\n";
	}
}