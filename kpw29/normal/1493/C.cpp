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
#endif

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
int tab[maxn], n, k;

inline int needs(int a) {
	a = a % k;
	if (a == 0) return 0;
	return k - a;
}

void solveone() {
	cin >> n >> k;
	
	
	string s;
	cin >> s;
	if (n % k) {
		cout << "-1\n";
		return;
	}
	vector <int> ile(26, 0);
	FOR(i, 1, n) tab[i] = s[i-1] - 'a';
	
	int necc = 0;
	FOR(i, 1, n) ile[tab[i]]++;
	FOR(i, 0, 25) necc += needs(ile[i]);
	
	if (necc == 0) {
		cout << s << "\n";
		return;
	}
	
	for (int i = n; i > 0; --i) {
		FOR(j, tab[i] + 1, 25) {
			//zmieniam tab[i] na j
			
			int prv = tab[i];
			necc -= needs(ile[prv]);
			ile[prv]--;
			necc += needs(ile[prv]);
			
			necc -= needs(ile[j]);
			ile[j]++;
			necc += needs(ile[j]);
			if (necc <= n - i) {
				//output
				string result = "";
				FOR(bar, 1, i-1) result += s[bar - 1];
				result += (char)(j + 'a');
				int full = n - i - necc;
				assert(full % k == 0);
				FOR(_, 1, full) result += 'a';
				FOR(let, 0, 25) {
					FOR(_, 1, needs(ile[let])) result += (char)(let + 'a');
				}
				cout << result << "\n";
				return;
			}
			// now doing the rollback
			
			necc -= needs(ile[j]);
			ile[j]--;
			necc += needs(ile[j]);
			
			
			necc -= needs(ile[prv]);
			ile[prv]++;
			necc += needs(ile[prv]);
		}
		
		int prv = tab[i];
		necc -= needs(ile[prv]);
		ile[prv]--;
		necc += needs(ile[prv]);
	}
	
	cout << "-1\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}