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
const LL INF = 1e8;
const int maxn = 200200;
int n, m, k;
vi v[maxn];
vector <int> special;
ll dist[maxn];
ll rev[maxn];

ll solveone() {
	cin >> n >> m >> k;
	special.resize(k);
	FOR(i, 0, k-1) cin >> special[i];
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n) dist[i] = rev[i] = inf;
	dist[1] = 0;
	queue <int> q;
	q.push(1);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		trav(u, v[x]) {
			if (dist[u] == inf) {
				dist[u] = dist[x] + 1;
				q.push(u);
			}
		}
	}
	
	rev[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		trav(u, v[x]) {
			if (rev[u] == inf) {
				rev[u] = rev[x] + 1;
				q.push(u);
			}
		}
	}
	
	sort(all(special), [&](int a, int b) {
		if (dist[a] - rev[a] != dist[b] - rev[b]) return dist[a] - rev[a] < dist[b] - rev[b];
		return a < b;
	});
	
	ll best_result = 0;
	ll dmaxx = dist[special[0]];
	
	for (int i=1; i<k; ++i) {
		int b = special[i];
		best_result = max(best_result, min(rev[b] + dmaxx + 1, dist[n]));
		dmaxx = max(dmaxx, dist[special[i]]);
	}
	
	return best_result;
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		cout << solveone() << "\n";
	}
}