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
vi v[maxn];
int A[maxn], B[maxn];
int dist[maxn];

void dfs(int x, vector <bool> &odw, vector <ll> &curr, vector <ll> &target) {
	odw[x] = 1;
	for (auto u : v[x]) {
		if (!odw[u]) {
			dist[u] = (dist[x] + 1) % 2;
			dfs(u, odw, curr, target);
		}
	}
}

bool solve(int z) {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) v[i].clear();
	vector <bool> odw(n+1, 0);
	vector <ll> curr(n+1), target(n+1);
	
	FOR(i, 1, n) {
		cin >> curr[i];
	}
	
	FOR(i, 1, n) {
		cin >> target[i];
		target[i] -= curr[i];
	}

	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		A[i] = a; B[i] = b;
	}
	
		
	dfs(1, odw, curr, target);
	bool bip = true;
	FOR(i, 1, m) {
		if (dist[A[i]] == dist[B[i]]) bip = false;
	}

	ll sum = 0;
	if (bip) {
		FOR(i, 1, n) {
			if (dist[i]) sum += target[i];
			else sum -= target[i];
		}
		
		return sum == 0;
	}
	else {
		FOR(i, 1, n) sum += target[i];
		return (sum % 2 == 0);
	}
}


int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(z, 1, tests) {
		bool ans = solve(z);
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}