#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n, m;
vi adj[MAXN];
vii edges[2];

bool visited[MAXN];
int pst[MAXN], cnt;
void dfs(int u) {
	visited[u] = 1;
	for (int v : adj[u]) {
		if (visited[v]) continue;
		dfs(v);
	}
	pst[u] = cnt++;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n + 5) {
			adj[i].clear();
			visited[i] = 0;
		}
		REP (i, 0, 2) edges[i].clear();
		REP (i, 0, m) {
			int t, x, y; scanf("%d%d%d", &t, &x, &y);
			edges[t].pb(MP(x, y));
			if (t == 1) {
				adj[x].pb(y);
			}
		}
		cnt = 0;
		REP (i, 1, n + 1) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		bool pos = 1;
		REP (i, 0, edges[1].size()) {
			int x, y; tie(x, y) = edges[1][i];
			if (pst[x] < pst[y]) {
				pos = 0;
				break;
			}
		}
		if (!pos) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		REP (i, 0, edges[0].size()) {
			int x, y; tie(x, y) = edges[0][i];
			if (pst[x] < pst[y]) swap(x, y);
			printf("%d %d\n", x, y);
		}
		REP (i, 0, edges[1].size()) {
			int x, y; tie(x, y) = edges[1][i];
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}