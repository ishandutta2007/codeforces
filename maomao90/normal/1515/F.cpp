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
#define MAXN 300005

int n, m, x;
ll a[MAXN];
vii adj[MAXN];
int b, f;
int ans[MAXN];

bool visited[MAXN];
void dfs(int u) {
	visited[u] = 1;
	for (auto [v, e] : adj[u]) {
		if (visited[v]) continue;
		dfs(v);
		//printf("%d %d %d\n", u, v, e);
		if (a[v] + a[u] >= x) {
			//printf(" %d\n", f);
			a[u] += a[v];
			a[u] -= x;
			ans[f++] = e;
		} else {
			//printf(" %d\n", b);
			ans[b--] = e;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &x);
	ll sum = 0;
	REP (i, 1, n + 1) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	REP (i, 1, m + 1) {
		int x, y; scanf("%d%d", &x, &y);
		adj[x].pb(y, i);
		adj[y].pb(x, i);
	}
	if (sum < (ll) (n - 1) * x) {
		printf("NO\n");
		return 0;
	}
	b = n - 2;
	dfs(1);
	printf("YES\n");
	REP (i, 0, n - 1) {
		printf("%d\n", ans[i]);
	}
	return 0;
}