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
const int maxn = 200100;
int n;
bool LOCAL = 0;

int perm[maxn];
int ask(int p1, int p2, int x) {
	if (x == 1) cout << "? 2 " << p1 << ' ' << p2 << ' ' << x << endl;
	else cout << "? 1 " << p1 << ' ' << p2 << ' ' << x << endl;
	
	int ans;
	if (LOCAL) {
		if (x == 1) ans = min(max(x, perm[p1]), max(x+1, perm[p2]));
		else ans = max(min(x, perm[p1]), min(x+1, perm[p2]));
	}
	else cin >> ans;
	return ans;
}

PII get(int pos) {
	int MAX = ask(pos, pos + 1, n - 1);
	int MIN = ask(pos, pos + 1, 1);
	
	if (MIN == 2) MIN = ask(pos + 1, pos, 1);
	if (MAX + 1 == n) MAX = ask(pos + 1, pos, n - 1);
	
	debug(pos, MIN, MAX);
	return {MIN, MAX};
}

int tab[maxn];
void pytaj(int pos) {
	debug(pos);
	PII jed = get(pos);
	PII dwa;
	int gdzie = 0;
	if (pos + 2 >= n) gdzie = n - 1, dwa = get(n - 1);
	else gdzie = pos + 2, dwa = get(pos + 2);
	
	PII srodek = get(pos + 1);
	
	if (jed.e1 == srodek.e1 || jed.e1 == srodek.e2) {
		tab[pos] = jed.e2;
		tab[pos + 1] = jed.e1;
	}
	else {
		tab[pos] = jed.e1;
		tab[pos + 1] = jed.e2;
	}
	
	if (pos + 2 < n) {
		if (dwa.e2 == srodek.e1 || dwa.e2 == srodek.e2) {
			tab[gdzie] = dwa.e2;
			tab[gdzie + 1] = dwa.e1;
		}
		else {
			tab[gdzie] = dwa.e1;
			tab[gdzie + 1] = dwa.e2;
		}
	}
	else {
		if (tab[n - 1] == dwa.e1) tab[n] = dwa.e2;
		else tab[n] = dwa.e1;
	}
}


int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		cin >> n;
		FOR(i, 1, n) tab[i] = 0;
		if (LOCAL) {
			FOR(i, 1, n) cin >> perm[i];
		}
		for (int i=1; i+3<=n; i+=4) pytaj(i);
		pytaj(n - 2);
		cout << "! ";
		FOR(i, 1, n) cout << tab[i] << ' ';
		cout << endl;
	}
}