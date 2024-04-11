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
mt19937_64 rng(time(0));
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
const int maxn = 1000100;

ll pref[maxn];
int tab[maxn], temp[maxn];
ll zostanie[maxn];
int delta[maxn];
ll melted[maxn];

void solve() {
	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
	}
	FOR(i, 1, n) {
		cin >> temp[i];
		melted[i] = melted[i - 1] + temp[i];
	}
	melted[n + 1] = melted[n];
	
	FOR(i, 1, n) {
		delta[i] += delta[i-1];
		int x = i - 1, y = n;
		while (x < y) {
			int sr = (x + y) / 2 + 1;
			if (melted[sr] - melted[i-1] >= tab[i]) y = --sr;
			else x = sr;
		}
		zostanie[x + 1] += tab[i] - (melted[x]-melted[i-1]);
		delta[x + 1]--;
		delta[i]++;
		
		cout << (ll)delta[i] * temp[i] + zostanie[i] << ' ';
	}
	
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}