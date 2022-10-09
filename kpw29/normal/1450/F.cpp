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

const int maxn = 100100;
int tab[maxn];
ll n, m, k;
vector <PII> dwojki;
ll jkn[maxn];
ll dkn[maxn];

void solveone() {
	cin >> n;
	map <int, int> M;
	bool possible = true;
	dwojki.clear();
	
	FOR(i, 1, n) cin >> tab[i], M[tab[i]]++, jkn[i] = 0, dkn[i] = 0;
	
	vector <int> elem = {tab[1]};
	
	for (auto&u : M) {
		if (u.e2 > (n + 1) / 2) possible = false;
	}
	
	FOR(i, 2, n) {
		if (tab[i] == tab[i-1]) {
			dwojki.push_back({elem[0], elem.back()});
			elem = {tab[i]};
		}
		else {
			elem.push_back(tab[i]);
		}
	}
	
	dwojki.push_back({elem[0], elem.back()});
	
	
	//debug(dwojki);
	if (!possible) {
		cout << "-1\n";
	}
	else {
		for (auto u : dwojki) {
			if (u.e1 == u.e2) {
				dkn[u.e1]++;
			}
			else {
				jkn[u.e1]++;
				jkn[u.e2]++;
			}
		}
		
		int dodaj = 0;
		for (int i=1; i<=n; ++i) {
			int tych = dkn[i];
			int tamtych = dwojki.size() - dkn[i] - jkn[i];
			
			dodaj = max(dodaj, tych - tamtych - 1);
		}
		
		cout << dwojki.size() + dodaj - 1 << "\n";
	}
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}