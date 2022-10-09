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
const int maxn = 200100;

int bridge[maxn];
const int LOG = 19;
vi v[maxn];
int skok[LOG][maxn];
int most_skok[LOG][maxn];

int d[maxn];
int par[maxn];
int pre[maxn], maxpre[maxn];
int DL;

vector <pair<int, PII> > bridges[maxn];

void dfs(int x) {
	pre[x] = ++DL;
	maxpre[x] = pre[x];
	trav(u, v[x]) {
		d[u] = d[x] + 1;
		skok[0][u] = x;
		dfs(u);
		maxpre[x] = max(maxpre[x], maxpre[u]);
	}
}

int make_jump(int x, int k) {
	for (int j=0; j<LOG; ++j) {
		if (k & (1 << j)) x = skok[j][x];
	}
	
	return x;
}

int getLCA(int x, int y) {
	if (d[x] < d[y]) y = make_jump(y, d[y] - d[x]);
	else x = make_jump(x, d[x] - d[y]);
	
	//x and y are equal
	for (int j=LOG-1; j>=0; --j) {
		if (skok[j][x] != skok[j][y]) {
			x = skok[j][x];
			y = skok[j][y];
		}
	}
	if (x == y) return x;
	return skok[0][x];
}

void przypisz_mosty(int x) {
	for (auto &most : bridges[x]) {
		int node = most.e2.e1;
		while (node != x && bridge[node] == 0) {
			bridge[node] = most.e2.e2;
			most_skok[0][node] = x; //da sie jednym ruchem skoczyc do x
			node = par[node];
		}
	}
	
	trav(u, v[x]) przypisz_mosty(u);
}

int ans[maxn];
int jump_cost[maxn];
vector <PP> rect_queries[maxn];
vector <int> points[maxn];
int rect_points[maxn];

int dr[maxn];

inline void add(int p, int val) {
	for (; p < maxn; p += p & (-p)) dr[p] += val;
}

inline int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}

int main() {
	boost;
	int n, m, zap;
	cin >> n;
	FOR(i, 2, n) {
		int p;
		cin >> p;
		v[p].pb(i);
		par[i] = p;
	}
	par[1] = 1;
	
	dfs(1);
	skok[0][1] = 1;
	rep(j, 1, LOG) {
		FOR(i, 1, n) skok[j][i] = skok[j-1][skok[j-1][i]];
	}
	
	cin >> m;
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		int u = getLCA(a, b);
		debug(a, b, u);
		bridges[u].pb({d[b], {b, i}});
		bridges[u].pb({d[a], {a, i}});
		
		if (u != a && u != b) {
			points[pre[a]].pb(pre[b]);
			points[pre[b]].pb(pre[a]);
		}
	}
	
	FOR(i, 1, n) sort(all(bridges[i]));
	przypisz_mosty(1);
	FOR(i, 1, n) {
		if (most_skok[0][i] == 0) most_skok[0][i] = i; //we can always remain 
	}
	
	rep(j, 1, LOG) {
		FOR(i, 1, n) most_skok[j][i] = most_skok[j-1][most_skok[j-1][i]];
	}
	
	cin >> zap;
	FOR(z, 1, zap) {
		int a, b;
		cin >> a >> b;
		int u = getLCA(a, b);
		//impossible to go at all
		if (d[most_skok[LOG - 1][a]] > d[u]) ans[z] = inf;
		else if (d[most_skok[LOG - 1][b]] > d[u]) ans[z] = inf;
		else {
			int cost = 0;
			for (int j = LOG - 1; j >= 0; --j) {
				int g1 = most_skok[j][a], g2 = most_skok[j][b];
				if (d[g1] > d[u]) {
					cost += (1 << j);
					a = most_skok[j][a];
				}
				if (d[g2] > d[u]) {
					cost += (1 << j);
					b = most_skok[j][b];
				}
			}
			jump_cost[z] = cost; //always possible in one move
			assert(d[most_skok[0][a]] <= d[u]);
			assert(d[most_skok[0][b]] <= d[u]);
			if (a == u || b == u) {
				rect_points[z] = 1; //always enough in one
			}
			else {
				PII inter = {pre[a], maxpre[a]};
				PII i2 = {pre[b], maxpre[b]};
				rect_queries[inter.e2].push_back({i2, {z, 1}});
				rect_queries[inter.e1 - 1].push_back({i2, {z, -1}});
			}
		}
	}
	
	FOR(coord, 0, n) {
		trav(c, points[coord]) add(c, 1);
		// now all the rectangles
		
		trav(query, rect_queries[coord]) {
			int a = query.e1.e1, b = query.e1.e2;
			int score = get(b) - get(a - 1);
			rect_points[query.e2.e1] += score * query.e2.e2;
		}
	}
	
	FOR(i, 1, zap) {
		if (ans[i] > n) {
			cout << "-1\n";
		}
		else {
			if (rect_points[i] > 0) cout << 1 + jump_cost[i] << "\n";
			else cout << 2 + jump_cost[i] << "\n";
		}
	}
}