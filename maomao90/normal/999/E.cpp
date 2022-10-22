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
#define MAXN 5005

int n, m, s;
vi adj[MAXN];
bool visited[MAXN];
int sze[MAXN];
set<ii, greater<ii> > st;
int ans;

void dfs(int u) {
	visited[u] = 1;
	for (int v : adj[u]) {
		if (visited[v]) continue;
		dfs(v);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	REP (i, 0, m) {
		int x, y; scanf("%d%d", &x, &y);
		adj[x].pb(y);
	}
	RREP (i, n, 1) {
		memset(visited, 0, sizeof visited);
		dfs(i);
		REP (j, 1, n + 1) {
			if (visited[j]) {
				sze[i]++;
			}
		}
	}
	memset(visited, 0, sizeof visited);
	dfs(s);
	REP (i, 1, n + 1) {
		if (!visited[i]) {
			st.insert(MP(sze[i], i));
		}
	}
	memset(visited, 0, sizeof visited);
	while (!st.empty()) {
		int curSze, id; tie(curSze, id) = *st.begin(); 
		st.erase(st.begin());
		if (visited[id]) continue;
		ans++;
		dfs(id);
	}
	printf("%d\n", ans);
	return 0;
}