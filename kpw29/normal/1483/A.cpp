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

int ile[maxn], arr[maxn], n, m;
vector <int> v[maxn];
int tab[maxn];

bool solveone() {
	cin >> n >> m;
	int maks = (m + 1) /2 ;
	FOR(i, 1, n) {
		ile[i] = maks;
	}
	FOR(i, 1, m) arr[i] = 0;
	bool ans = true;
	FOR(i, 1, m) {
		int sz;
		cin >> sz;
		v[i].clear();
		v[i].resize(sz);
		FOR(j, 0, sz-1) {
			cin >> v[i][j];
		}
		
		if (sz == 1) {
			int co = v[i][0];
			if (ile[co] == 0) ans = false;
			arr[i] = co;
			ile[co]--;
		}
	}
	
	if (!ans) return false;
	
	FOR(i, 1, m) {
		//int i = tab[xd];
		int maxx = 0;
		if (arr[i] == 0) {
			for (auto co : v[i]) {
				maxx = max(maxx, ile[co]);
			}
			
			if (maxx == 0) return false;
			for (auto co : v[i]) {
				if (maxx == ile[co]) {
					ile[co]--;
					arr[i] = co;
					break;
				}
			}
		}
	}
		
	return true;
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) {
		bool b = solveone();
		if (!b) cout << "NO\n";
		else {
			cout << "YES\n";
			FOR(i, 1, m) cout << arr[i] << ' ';
			cout << "\n";
		}
	}
}