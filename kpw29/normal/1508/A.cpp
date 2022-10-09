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


string check(string &s1, string &s2, int n) {
	int l1 = 0, l2 = 0;
	int N = 2 * n;
	string ret = "";
	char greater = '0';
	int occ0 = 0, occ1 = 0;
	FOR(i, 0, N-1) {
		if (s1[i] == '0') ++occ0;
		else ++occ1;
	}
	FOR(i, 0, N-1) {
		if (s2[i] == '0') ++occ0;
		else ++occ1;
	}
	if (occ1 > occ0) greater = '1';
	
	while (l1 < N && l2 < N) {
		if (s1[l1] == s2[l2]) {
			ret += s1[l1];
			l1++; l2++;
		}
		else {
			if (s1[l1] == greater) {
				ret += s2[l2]; ++l2;
			}
			else {
				ret += s1[l1]; ++l1;
			}
		}
	}
	
	while (l1 < N) ret += s1[l1++];
	while (l2 < N) ret += s2[l2++];
	
	if (ret.size() <= 3 * n) return ret;
	return "";
}

string solveone() {
	string s1, s2, s3;
	int n; cin >> n;
	cin >> s1 >> s2 >> s3;
	
	string o1 = check(s1, s2, n);
	if (o1 != "") return o1;
	
	o1 = check(s1, s3, n);
	if (o1 != "") return o1;
	
	o1 = check(s2, s3, n);
	if (o1 != "") return o1;
	
	//assert(false);
}

int main() {
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) {
		cout << solveone() << "\n";
	}
}