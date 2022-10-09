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
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1000000LL * 1000000LL * 1000000LL;

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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 200100;
const int BIG = 20;

ll dp[maxn][BIG + 2];
int shortest_path[maxn];
ll potw[60];


int A[maxn], B[maxn];
vector <int> v[maxn], rev[maxn];

int n, m;

PLL costs[maxn];

void propagate(int dim) {
	if (dim) {
		FOR(i, 1, n) dp[i][dim] = min(dp[i][dim], dp[i][dim - 1]);
	}
	
	set <PLL> q;
	FOR(i, 1, n) q.insert({dp[i][dim], i});
	
	FOR(i, 1, n) {
		PLL fro = *q.begin();
		q.erase(q.begin());
		int a = fro.e2;
		if (dim % 2 == 0) {
			for (auto &b : v[a]) {
				if (dp[a][dim] + 1 < dp[b][dim]) {
					q.erase({dp[b][dim], b});
					dp[b][dim] = dp[a][dim] + 1;
					q.insert({dp[b][dim], b});
				}
			}
		}
		else {
			for (auto &b : rev[a]) {
				if (dp[a][dim] + 1 < dp[b][dim]) {
					q.erase({dp[b][dim], b});
					dp[b][dim] = dp[a][dim] + 1;
					q.insert({dp[b][dim], b});
				}
			}
		}
	}
	
	//propagation step has finished
	FOR(i, 1, n) {
		int a = costs[i].e2;
		if (dim % 2 == 1) {
			for (auto &b : v[a]) {
				dp[b][dim + 1] = min(dp[b][dim + 1], dp[a][dim] + 1);
			}
		}
		else {
			for (auto &b : rev[a]) {
				dp[b][dim + 1] = min(dp[b][dim + 1], dp[a][dim] + 1);
			}
		}
	}
	
	//ok we're finished with this step
}

vector <pair <int, PLL> > graph[2 * maxn];
PLL operator+(PLL a, PLL b) {
	return make_pair(a.first + b.first, a.second + b.second);
}

PLL dijkstra(int start, int kon) {
	vector <PLL> dp(2 * n + 1);
	FOR(i, 1, 2 * n) dp[i] = make_pair(INF + 1, INF + 1);
	dp[start] = make_pair(0, 0);
	FOR(i, 1, m) {
		graph[A[i]].push_back({B[i], {0, 1}});
		graph[B[i]].push_back({A[i] + n, {1, 1}});
		
		graph[B[i] + n].push_back({A[i] + n, {0, 1}});
		graph[A[i] + n].push_back({B[i], {1, 1}});
	}
	
	
	set <pair <PLL, int> > q;
	q.insert({dp[start], start});
	
	while (!q.empty()) {
		pair <PLL, int> head = *q.begin();
		int a = head.second;
		q.erase(q.begin());
		
		for (auto &sec : graph[a]) {
			PLL option = dp[a] + sec.e2;
			if (option < dp[sec.e1]) {
				q.erase({dp[sec.e1], sec.e1});
				dp[sec.e1] = option;
				q.insert({dp[sec.e1], sec.e1});
			}
		}
	}
	
	return min(dp[kon], dp[kon + n]);
}

void solveone() {

	potw[0] = 1;
	for (int i=1; i<60; ++i) potw[i] = potw[i-1] * 2LL;
	
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> A[i] >> B[i];
		v[A[i]].pb(B[i]);
		rev[B[i]].pb(A[i]);
	}
	
	FOR(i, 1, n) 
		FOR(j, 0, BIG) dp[i][j] = INF;
	
	dp[1][0] = 0;
	FOR(i, 0, BIG) propagate(i);
	//if (A[1] == 91298) {
		//FOR(i, 1, n) cout << i << ' ' << dp[n][i] << endl;
	//}
	
	if (dp[n][BIG] == INF) {
		//still no option to go there, we need to do BFS to go for shortest path
		PLL result = dijkstra(1, n);
		ll res = 1;
		for (int step = 0; step < result.e1; ++step) res = (res * 2) % mod;
		res = (res + mod - 1) % mod;
		res = (res + result.e2) % mod;
		cout << res << "\n";
	}
	else {
		/*debug("dwa");
		
		debug("zero");
		FOR(i, 1, n) debug(i, dp[i][0]);
		debug("jeden");
		FOR(i, 1, n) debug(i, dp[i][1]);
		debug("dwa");
		FOR(i, 1, n) debug(i, dp[i][2]);
		debug("trzy");
		FOR(i, 1, n) debug(i, dp[i][3]);
		*/
		ll result = INF;
		for (int i=0; i<=BIG; ++i) {
			
			result = min(result, dp[n][i] + potw[i] - 1);
		}
		cout << result % mod << "\n";
	}
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}