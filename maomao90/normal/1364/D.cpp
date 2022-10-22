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
#define pb push_back
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
#define MAXN 200005

int n, m, k;
vi adj[MAXN];
priority_queue<ii> pq;

int num[MAXN], p[MAXN], ptr;
vi cyc;
void dfs(int u, int cp) {
	num[u] = ptr++;
	p[u] = cp;
	int cmx = -1;
	bool found = 0;
	for (int v : adj[u]) {
		if (v == cp) continue;
		if (num[v] != -1) found = 1;
	}
	if (found) {
		int mx = -1, mxid = -1;
		for (int v : adj[u]) {
			if (v == cp || num[v] == -1) continue;
			if (mxto(mx, num[v])) {
				mxid = v;
			}
		}
		int v = u;
		cyc.pb(u);
		while (v != mxid) {
			v = p[v];
			cyc.pb(v);
		}
	} else {
		for (int v : adj[u]) {
			if (v == cp) continue;
			dfs(v, u);
			if (!cyc.empty()) {
				return;
			}
		}
	}
}

bool c[MAXN];
int cnt[2];
void tdfs(int u, int cp) {
	cnt[c[u]]++;
	for (int v : adj[u]) {
		if (v == cp) continue;
		c[v] = c[u] ^ 1;
		tdfs(v, u);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP (i, 0, m) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (m == n - 1) {
		tdfs(1, -1);
		int mx = 0;
		if (cnt[1] > cnt[0]) mx = 1;
		vi ans;
		REP (i, 1, n + 1) {
			if (c[i] == mx) {
				ans.pb(i);
			}
		}
		printf("1\n");
		REP (i, 0, (k + 1) / 2) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	} else {
		memset(num, -1, sizeof num);
		dfs(1, -1);
		if (cyc.size() <= k) {
			printf("2\n");
			printf("%d\n", (int) cyc.size());
			for (int &i : cyc) {
				printf("%d ", i);
			}
			printf("\n");
		} else {
			vi ans;
			REP (i, 0, (k + 1) / 2) {
				assert(i * 2 < cyc.size());
				ans.pb(cyc[i * 2]);
			}
			printf("1\n");
			for (int &i : ans) {
				printf("%d ", i);
			}
			printf("\n");
		}
	}
	return 0;
}