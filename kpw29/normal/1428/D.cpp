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
int n, m, b, c;
int tab[maxn];
vector <PII> ans;

bool solveone() {
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	deque <int> ones;
	
	int last_notzero = -1, last_notone = -1;
	for (int i=n; i>0; --i) {
		int a = tab[i];
		if (a == 0) continue;
		if (a == 1) {
			ones.push_back(i);
			ans.push_back({i, i});
			last_notzero = i;
			continue;
		}
		
		if (a == 2) {
			if (ones.empty()) return false;
			int kom = ones.front();
			ones.pop_front();	
			ans.push_back({i, kom});
		}
		
		if (a == 3) {
			if (last_notzero == -1) return false;
			if (last_notone != -1) {
				ans.push_back({i, i});
				ans.push_back({last_notone, i});
			}
			else {
				//we have to take some ONE, let it be the LAST one (bcs why not)
				if (ones.empty()) return false;
				int kom = ones.back();
				ones.pop_back();
				
				ans.push_back({i, i});
				ans.push_back({kom, i});
			}
		}
		
		last_notone = i;
		
	}
	
	return 1;
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	bool odp = solveone();
	if (!odp) cout << "-1\n";
	else {
		cout << (int)ans.size() << "\n";
		for (auto u : ans) cout << u.e2 << ' ' << u.e1 << "\n";
	} 
}