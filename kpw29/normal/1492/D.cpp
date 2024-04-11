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
#ifdef DEBUG
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 200100;
int a, b, k;


void solveone() {
	cin >> a >> b >> k;
	string s1 = "1";
	string s2 = "1";
	b--;
	if (k == 0) {
			cout << "Yes\n";
			FOR(i, 1, b) s1 += "1", s2 += "1";
			FOR(i, 1, a) s1 += "0", s2 += "0";
			cout << s1 << endl << s2 << endl;
			return;
	}
	
	if (k >= a + b) {
		cout << "No\n";
	}
	else {
		// will be a + b + 1 this way
		if (b == 0 || a == 0) {
			cout << "No\n";
			return;
		}
		else {
			string mid = "";
			FOR(i, 1, a-1) mid += "0"; 
			FOR(i, 1, b-1) mid += "1";
			string beg = "";
			int score = a + b - 1;
			while (score > k) {
				--score;
				char c = mid.back();
				mid.pop_back();
				beg += c;
			}
			reverse(beg.begin(), beg.end());
			
			s1 = s1 + beg + "1" + mid + "0";
			s2 = s2 + beg + "0" + mid + "1";
			
			cout << "Yes\n";
			cout << s1 << endl << s2 << endl;
		}
	}
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}