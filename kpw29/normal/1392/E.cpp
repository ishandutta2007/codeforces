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

const int maxn = 30;

ll tab[maxn][maxn];
int n;

int main() {
	cin >> n;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			int prze = i + j - 3;
			if (prze == -1) tab[i][j] = 0;
			else {
				if (i % 2 == 1) tab[i][j] = 1LL << prze;
				else tab[i][j] = 0;
			}
		}
	}
	
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			cout << tab[i][j];
			if (j < n) cout << " ";
			else cout << "\n";
		}
	}
	
	cout.flush();
	int q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		int x = 1, y = 1, turn = 0;
		
		cout << x << ' ' << y << "\n";
		while (!(x == n && y == n)) {
			if (x == n) ++y;
			else if (y == n) ++x;
			else {
				if ((1LL << turn) & k) {
					if (x % 2 == 1) ++y;
					else ++x;
				}
				else {
					if (x % 2 == 0) ++y;
					else ++x;
				}
			}
			
			
			cout << x << ' ' << y << "\n";
			++turn;
		}
		
		cout.flush();
	}
	
		
}