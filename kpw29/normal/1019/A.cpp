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

void solve() {
	
}

vi votes[3010];

int main() {
	boost;
	int n, m;
	cin >> n >> m;
	if (m == 1) OUT(0);
	
	FOR(i, 1, n) {
		int p, c;
		cin >> p >> c;
		votes[p].pb(c);
	}
	
	FOR(i, 1, m) sort(all(votes[i]), greater<int>());
	ll ans = INF;
	
	for (int glos = 1; glos <= n; ++glos) {
		int mam = sz(votes[1]);
		ll cost = 0;
		FOR(party, 2, m) {
			for (int j = glos - 1; j < (int)votes[party].size(); ++j) {
				mam++;
				cost += votes[party][j];
			}
		}
		
		if (mam < glos) {
			vector <int> elems;
			FOR(party, 2, m) {
				int iter = min(sz(votes[party]), glos - 1);
				for (int j=0; j<iter; ++j) {
					elems.pb(votes[party][j]);
				}
			}
			
			sort(all(elems));
			for (int i=0; i<glos-mam; ++i) cost += elems[i];
		}
		
		ans = min(ans, cost);
	}
	
	cout << ans << endl;
	
}