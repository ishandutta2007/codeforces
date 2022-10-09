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

const int maxn = 10002;

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

int n, m, k, d, tab[maxn];
int island[maxn];

int RED[maxn][1000];
vector <int> q;
vector <int> nodes[1000];


inline int num(int i, int res) {
	return i * 1000 + res;
}
int green, red;

int main() {
	boost;
	cin >> d >> n;
	FOR(i, 1, n) cin >> island[i];
	cin >> green >> red;
	
	sort(island+1, island+n+1);
	RED[1][0] = 1;
	q.pb(1);
	FOR(STEP, 1, n) {
		if (q.empty()) break;
		FOR(j, 0, 999) nodes[j].clear();
		nodes[0] = vector <int>(q);
		q = {};
		for (int j = 0; j < green; ++j) {
			for (auto i : nodes[j]) {
				if (i < n) {
					int dst = island[i + 1] - island[i];
					if (j + dst == green && RED[i + 1][0] == 0) {
						RED[i + 1][0] = STEP + 1;
						q.push_back(i + 1);
					}
					else if (j + dst < green && RED[i + 1][j + dst] == 0) {
						RED[i + 1][j + dst] = STEP;
						nodes[j + dst].push_back(i + 1);
					}
				}
				
				if (i > 1) {
					int dst = island[i] - island[i - 1];
					if (j + dst == green && RED[i - 1][0] == 0) {
						RED[i - 1][0] = STEP + 1;
						q.push_back(i - 1);
					}
					else if (j + dst < green && RED[i - 1][j + dst] == 0) {
						RED[i - 1][j + dst] = STEP;
						nodes[j + dst].push_back(i - 1);
					}
				}
			}
		}
	}
	
	ll RES = INF;
	FOR(i, 1, n-1)
		if (RED[i][0] != 0) {
			ll rw = RED[i][0] - 1;
			ll full_going = rw * (green + red);
			if (island[n] - island[i] <= green) RES = min(RES, full_going + island[n] - island[i]);
		}
		
	if (RES == INF) cout << "-1";
	else cout << RES;
}