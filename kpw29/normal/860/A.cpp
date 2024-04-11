#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
//#include <atcoder/modint>
//using namespace atcoder;
//using mint = modint1000000007;
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
#ifdef DEBUG
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#endif

#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

bool cons(char zn) {
	if (zn == 'a') return 0;
	if (zn == 'e') return 0;
	if (zn == 'i') return 0;
	if (zn == 'o') return 0;
	if (zn == 'u') return 0;
	return 1;
}

void solve(int tc) {
	string s;
	cin >> s;
	int n = sz(s);
	
	int co = 0;
	bool diff = 0;
	rep(i, 0, n) {
		
		if (co >= 1 && cons(s[i]) && s[i] != s[i-1]) diff = 1;
		if (cons(s[i])) ++co;
		
		if (cons(s[i]) && co >= 3 && diff) {
			cout << ' ';
			co = 1;
			diff = 0;
		}
		
		if (!cons(s[i])) co = 0, diff = 0;
		
		cout << s[i];
	}
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}