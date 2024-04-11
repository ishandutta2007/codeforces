#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
const long long INF = 1e18+3;
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

const int maxn = 1001000;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: For each position in a string, computes p[0][i] = half length of
 *  longest even palindrome around pos i, p[1][i] = longest odd (half rounded down).
 * Time: O(N)
 * Status: Stress-tested
 */

array<vi, 2> manacher(string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

string s;
void solve(string s) {
	int n = s.length();
	int POCZ = 0, KON = n - 1;
	while (POCZ <= KON && s[POCZ] == s[KON]) {
		POCZ++;
		KON--;
	}
	
	if (POCZ >= KON) {
		FOR(i, 0, n-1) cout << s[i];
		return;
	}
	
	string w = "";
	int L = 0;
	
	FOR(step, POCZ, KON) w += s[step], ++L;
	auto arr = manacher(w);
	
	int ODD = 0, EVEN = 0, MX = 0;
	FOR(i, 0, L-1) {
		if (arr[1][i] == i) ODD = 2 * i + 1;
		if (arr[0][i + 1] == i + 1) EVEN = 2 * (i + 1);
	}
	
	MX = max(ODD, EVEN);
	
	reverse(w.begin(), w.end());
	ODD = 0, EVEN = 0;
	arr = manacher(w);
	reverse(w.begin(), w.end());
	
	FOR(i, 0, L-1) {
		if (arr[1][i] == i) ODD = 2 * i + 1;
		if (arr[0][i + 1] == i + 1) EVEN = 2 * (i + 1);
	}
	
	int MAXX = max(ODD, EVEN);
	FOR(i, 0, POCZ - 1) cout << s[i];
	if (MX > MAXX) {
		FOR(ka, 0, MX-1) cout << s[POCZ + ka];
	}
	else KON -= MAXX;
	FOR(ka, KON + 1, n - 1) cout << s[ka];
}

int main() {
	//boost;
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> s;
		solve(s);
		cout << "\n";
	}
}