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
const int maxn = 1000100;
int n, m, k;
long long pref[maxn];
typedef pii flight;

vector <flight> to[maxn];
vector <flight> from[maxn];

//vector <pii> to[maxn];
const ll INF = 1e12 + 6;

void apply(int a, int b, ll val) {
	debug("appl", a, b, val);
	a = max(a, 0);
	if (a > b) return;
	pref[a] += val;
	pref[b+1] -= val;
};

const int MAX = 1e6;

void solve(int tc) {
	cin >> n >> m >> k;
	FOR(i, 1, m) {
		int a, b, day, cost;
		cin >> day >> a >> b  >> cost;
		if (a > 0) from[a].pb({day, cost});
		else to[b].pb({day - (k + 1), cost});
	}
	FOR(i, 1, n) sort(all(from[i]));
	FOR(i, 1, n) sort(all(to[i]));
	FOR(i, 1, n) {
		debug(i);
		int s = sz(from[i]);
		ll min_cost = INF;
		if (from[i].empty() || to[i].empty()) OUT(-1);
		
		apply(0, from[i][0].e1-1, INF);
		rep(j, 0, s) {
			min_cost = min(min_cost, (ll)from[i][j].e2);
			if (j + 1 == s) apply(from[i][j].e1, MAX, min_cost);
			else apply(from[i][j].e1, from[i][j+1].e1-1, min_cost);
		}
		
		debug("Finished from");
		s = sz(to[i]);
		apply(to[i][s-1].e1+1, MAX, INF);
		
		min_cost = INF;
		for (int j=s-1; j>=0; --j) {
			min_cost = min(min_cost, (ll)to[i][j].e2);
			if (j == 0) apply(0, to[i][j].e1, min_cost);
			else apply(to[i][j-1].e1+1, to[i][j].e1, min_cost);
		}
	}
	
	ll wynik = INF;
	FOR(i, 0, MAX) {
		pref[i] += pref[i-1];
		//if (pref[i] <= 30000) debug(i, pref[i]);
		wynik = min(wynik, pref[i]);
	}
	
	if (wynik >= INF) cout << "-1\n";
	else cout << wynik << endl;
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