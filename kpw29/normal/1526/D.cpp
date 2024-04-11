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
const int maxn = 100100;

vector <int> pos[4];
int mak[2137];
vector <char> rv = {'N', 'A', 'T', 'O'};

int dr[maxn];

void add(int p, int v) {
	for (; p < maxn; p += p & (-p)) dr[p] += v;
}

int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}

ll licz(vector <int> &vec) {
	ll res = 0;
	for (int i=(int)vec.size()-1; i>=0; --i) {
		res += get(vec[i] + 1);
		add(vec[i] + 1, 1);
	}
	
	trav(u, vec) add(u + 1, -1);
	//debug(vec);
	return res;
}

void solve() {
	string anton;
	cin >> anton;
	int n = anton.size();
	FOR(i, 0, 3) pos[i].clear();
	for (int i=0; i<n; ++i) {
		int p = mak[anton[i]];
		pos[p].push_back(i);
	}
	
	vi opt;
	ll best_score = -1;
	
	vi perm;
	FOR(i, 0, 3) perm.pb(i);
	do {
		vi sorted = {};
		FOR(step, 0, 3) {
			int kt = perm[step];
			trav(gdzie, pos[kt]) sorted.pb(gdzie);
		}
		
		ll w = licz(sorted);
		if (w > best_score) {
			best_score = w;
			opt = sorted;
		}
		
	}while(next_permutation(perm.begin(), perm.end()));

	debug(best_score);
	
	trav(gdzie, opt) cout << anton[gdzie];
	
	cout << "\n";
}

int main() {
	mak['A'] = 1; mak['N'] = 0; mak['T'] = 2; mak['O'] = 3;
	
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	while (tests--) {
		solve();
	}
}