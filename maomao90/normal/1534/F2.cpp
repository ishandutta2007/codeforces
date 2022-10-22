#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
		va_list args;
			va_start(args, format);
				vprintf(format, args);
					va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 400005
#define MAXM 400005

int n, m;
string grid[MAXN];
char tmp[MAXM];
int a[MAXM];
vi adj[MAXN];
int ans;
vi impt;

int ptoi(ii rc) {
	return rc.FI * m + rc.SE;
}
ii itop(int i) {
	return MP(i / m, i % m);
}

bool instk[MAXN];
int num[MAXN], low[MAXN], cnt;
int rep[MAXN];
vi stk;
bool ispart[MAXN];
vi nadj[MAXN];
int spid[MAXN];
void dfs(int u) {
	num[u] = low[u] = cnt++;
	stk.pb(u); instk[u] = 1;
	for (int v : adj[u]) {
		if (num[v] == -1) {
			dfs(v);
			mnto(low[u], low[v]);
		} else if (instk[v]) {
			mnto(low[u], num[v]);
		}

	}
	if (low[u] == num[u]) {
		while (1) {
			int bk = stk.back(); stk.pop_back();
			instk[bk] = 0;
			rep[bk] = u;
			if (bk == u) break;
		}
	}
}
bool visited[MAXN];
vi v;
void getTopo(int u) {
	for (int v : nadj[u]) {
		if (visited[v]) continue;
		visited[v] = 1;
		getTopo(v);
	}
	v.pb(u);
}
void dfs2(int u) {
	for (int v : nadj[u]) {
		if (visited[v]) continue;
		visited[v] = 1;
		spid[v] = -1;
		dfs2(v);
	}
}
ii lr[MAXN];
void dfs3(int u) {
	if (spid[u] != -1) {
		lr[u] = MP(spid[u], spid[u]);
	}
	for (int v : nadj[u]) {
		mnto(lr[u].FI, lr[v].FI);
		mxto(lr[u].SE, lr[v].SE);
		if (visited[v]) continue;
		visited[v] = 1;
		dfs3(v);
		mnto(lr[u].FI, lr[v].FI);
		mxto(lr[u].SE, lr[v].SE);
	}
}
bool hasid[MAXM];
int nxt(int x) {
	int u = x + 1;
	while (u < m && !hasid[u]) {
		u++;
	}
	return u;
}

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		scanf(" %s", tmp);
		grid[i] = tmp;
	}
	REP (i, 0, m) {
		scanf("%d", &a[i]);
	}
	REP (i, 0, m) {
		int prv = -1;
		REP (l, 0, n) {
			if (grid[l][i] == '.') continue;
			if (l != 0 && grid[l - 1][i] == '#') {
				adj[ptoi(MP(l, i))].pb(ptoi(MP(l - 1, i)));
			}
			if (prv != -1) {
				adj[ptoi(MP(prv, i))].pb(ptoi(MP(l, i)));
			}
			prv = l;
		}
	}
	REP (i, 0, m - 1) {
		int l = 0, r = 0;
		for (; l < n; l++) {
			if (grid[l][i] == '.') continue;
			while (r < n && (r < l || grid[r][i + 1] == '.')) {
				r++;
			}
			if (r != n) {
				adj[ptoi(MP(l, i))].pb(ptoi(MP(r, i + 1)));
				debug("(%d %d) -> (%d %d)\n", l, i, r, i + 1);
			}
		}
	}
	REP (i, 1, m) {
		int l = 0, r = 0;
		for (; l < n; l++) {
			if (grid[l][i] == '.') continue;
			while (r < n && (r < l || grid[r][i - 1] == '.')) {
				r++;
			}
			if (r != n) {
				adj[ptoi(MP(l, i))].pb(ptoi(MP(r, i - 1)));
				debug("(%d %d) -> (%d %d)\n", l, i, r, i - 1);
			}
		}
	}
	memset(num, -1, sizeof num);
	REP (i, 0, n * m) {
		auto [r, c] = itop(i);
		if (grid[r][c] == '.') continue;
		if (num[i] == -1) {
			dfs(i);
		}
	}
	REP (i, 0, n * m) {
		auto [r, c] = itop(i);
		if (grid[r][c] == '.') continue;
		ispart[rep[i]] = 1;
		for (int v : adj[i]) {
			if (rep[i] == rep[v]) continue;
			nadj[rep[i]].pb(rep[v]);
		}
	}
	memset(spid, -1, sizeof spid);
	REP (i, 0, m) {
		if (a[i] == 0) continue;
		int l = n - 1;
		REP (j, 0, a[i]) {
			while (grid[l][i] == '.') l--;
			if (j != a[i] - 1) l--;
		}
		spid[rep[ptoi(MP(l, i))]] = i;
		debug("%d %d: %d\n", l, i, i);
	}
	memset(visited, 0, sizeof visited);
	REP (i, 0, n * m) {
		if (!ispart[i]) continue;
		if (visited[i]) continue;
		visited[i] = 1;
		getTopo(i);
	}
	vi topo = v;
	reverse(ALL(topo));
	memset(visited, 0, sizeof visited);
	for (int &i : topo) {
		if (spid[i] != -1 && !visited[i]) {
			visited[i] = 1;
			dfs2(i);
		}
	}
	REP (i, 0, n * m) {
		if (spid[i] != -1) {
			hasid[spid[i]] = 1;
			auto [r, c] = itop(i);
			debug("%d %d\n", r, c);
		}
	}
	REP (i, 0, n * m) {
		lr[i] = MP(INF, -INF);
	}
	memset(visited, 0, sizeof visited);
	for (int &i : topo) {
		if (!ispart[i] || visited[i]) continue;
		dfs3(i);
	}
	sort(lr, lr + n * m);
	int r = lr[0].FI;
	int i = 0;
	while (i < n * m) {
		if (lr[i].SE == -INF || r >= m) break;
		int nr = -INF;
		for (; lr[i].FI <= r && i < n * m; i++) {
			mxto(nr, lr[i].SE);
		}
		ans++;
		r = nxt(nr);
	}
	printf("%d\n", ans);
	return 0;
}