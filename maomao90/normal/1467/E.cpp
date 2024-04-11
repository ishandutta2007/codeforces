// time-limit: 3000
// problem-url: https://codeforces.com/contest/1467/problem/E

// For the earth will be filled with the knowledge of the glory
// of the Lord as the waters cover the sea
// Habakkuk 2:14
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
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int n;
int a[MAXN];
vi adj[MAXN];
ii dis[MAXN];
vi mp[MAXN];
int ans;

int p[20][MAXN], pre[MAXN], pst[MAXN], lvl[MAXN], ptr = 1;
void dfs(int u, int cp) {
	p[0][u] = cp;
	REP (k, 1, 20) {
		if (p[k - 1][u] == -1) {
			p[k][u] = -1;
		} else {
			p[k][u] = p[k - 1][p[k - 1][u]];
		}
	}
	pre[u] = ptr++;
	for (int v : adj[u]) {
		if (cp == v) continue;
		lvl[v] = lvl[u] + 1;
		dfs(v, u);
	}
	pst[u] = ptr;
}
int child;
int lca(int a, int b) {
	if (a == b) {
		return a;
	}
	if (lvl[a] < lvl[b]) {
		swap(a, b);
	}
	RREP (k, 19, 0) {
		if (p[k][a] == -1) continue;
		if (lvl[p[k][a]] > lvl[b]) {
			a = p[k][a];
		}
	}
	child = a;
	if (lvl[a] != lvl[b]) {
		a = p[0][a];
	}
	if (a == b) {
		return a;
	}
	RREP (k, 19, 0) {
		if (p[k][a] != p[k][b]) {
			a = p[k][a];
			b = p[k][b];
		}
	}
	child = a;
	return p[0][a];
}
int fw[MAXN];
void incre(int i, int x) {
	for (; i <= n; i += i & -i) fw[i] += x;
}
void incre(int s, int e, int x) {
	incre(s, x); incre(e, -x);
}
int qsm(int i) {
	int res = 0;
	for (; i > 0; i -= i & -i) res += fw[i];
	return res;
}

int main() {
	int _t = 1;
   	//scanf("%d", &_t);
	while (_t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			dis[i - 1] = MP(a[i], i);
		}
		REP (i, 1, n) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		sort(dis, dis + n);
		int prv = -1, ptr = 0;
		REP (i, 0, n) {
			if (dis[i].FI != prv) {
				ptr++;
				prv = dis[i].FI;
			}
			a[dis[i].SE] = ptr;
		}
		REP (i, 1, n + 1) {
			mp[a[i]].pb(i);
		}
		dfs(1, -1);
		REP (i, 1, n + 1) {
			if (mp[i].size() <= 1) {
				continue;
			}
			sort(ALL(mp[i]), [&] (int l, int r) {
					return pre[l] < pre[r];
					});
			REP (j, 0, mp[i].size()) {
				int a = mp[i][j], b = mp[i][(j + 1) % mp[i].size()];
				if (pre[a] > pre[b]) swap(a, b);
				int u = lca(a, b);
				if (u == a) {
					incre(1, n + 1, 1);
					incre(pre[child], pst[child], -1);
				} else {
					incre(pre[a], pst[a], 1);
				}
				incre(pre[b], pst[b], 1);
			} 
		}
		REP (i, 1, n + 1) {
			if (qsm(pre[i]) == 0) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}