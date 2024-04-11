#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
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
const int mod = 1e9+7;
const int inf = 1e9+9;
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

const int maxn = 1010;
int ans;
int deg[maxn];
vector <int> v[maxn];
int que, n;
bool bad[maxn];

int main() {
	cin >> n;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	int limit = (n / 2);
	
	while (que < limit && ans == 0) {
		int p = 0, q = 0;
		FOR(i, 1, n) {
			if (deg[i] == 1 && !p) p = i;
			else if (deg[i] == 1 && p && !q) q = i;
		}
		
		que++;
		cout << "? " << p << ' ' << q << endl;
		int rep;
		cin >> rep;
		if (rep == p) ans = p;
		if (rep == q) ans = q;
		bad[p] = 1;
		bad[q] = 1;
		deg[p] = 0; deg[q] = 0;
		for (auto u : v[p]) deg[u]--;
		for (auto u : v[q]) deg[u]--;
	}
	
	if (ans == 0) {
		FOR(i, 1, n) {
			if (!bad[i]) {
				cout << "! " << i << endl;
				exit(0);
			}
			
		}
	}
	
	cout << "! " << ans << endl;
}