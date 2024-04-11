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

int n;
vi adj[MAXN];
priority_queue<ii> pq;
vi ans;

int d[MAXN], p[MAXN], in[MAXN];
void root(int u, int curp, int curd) {
	d[u] = curd;
	p[u] = curp;
	in[u] = adj[u].size();
	for (int v : adj[u]) {
		if (v == curp) continue;
		root(v, u, curd + 1);
	}
}

bool visited[MAXN];
void dfs(int u) {
	visited[u] = 1;
	ans.pb(u);
	for (int v : adj[u]) {
		if (v == p[u] || visited[v]) continue;
		dfs(v);
	}
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		int a; scanf("%d", &a);
		if (a == 0) continue;
		adj[i].pb(a);
		adj[a].pb(i);
	}
	root(1, -1, 0);
	REP (i, 1, n + 1) {
		if (in[i] % 2 == 0) {
			pq.push(MP(d[i], i));
		}
	}
	while (!pq.empty()) {
		int du, u; tie(du, u) = pq.top(); pq.pop();
		if (visited[u] || in[u] % 2 == 1) continue;
		dfs(u);
		in[p[u]]--;
		if (in[p[u]] % 2 == 0) {
			pq.push(MP(du - 1, p[u]));
		}
	}
	REP (i, 1, n + 1) {
		if (!visited[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i : ans) {
		printf("%d\n", i);
	}
	return 0;
}