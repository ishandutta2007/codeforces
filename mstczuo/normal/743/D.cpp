#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define pb push_back

const int maxn = 200010;

const long long inf = (long long) (1e18 + .1);

vector<int> g[maxn];
long long a[maxn];
long long b[maxn];
long long ans;

void dfs(int u,int par) {
	b[u] = -inf;
	for(auto v: g[u]) if(v != par) {
		dfs(v, u);
		a[u] += a[v];
		b[u] = max(b[u], b[v]);
	}
	b[u] = max(b[u], a[u]);
}

void calc(int u,int par,long long val) {
	if(val != -inf) ans = max(ans, a[u] + val);
	int mx1 = -1, mx2 = -1;
	for(auto v: g[u]) if(v != par) {
		if(mx1 == -1 || b[v] > b[mx1]) {
			mx2 = mx1;
			mx1 = v;
		} else if(mx2 == -1 || b[v] > b[mx2]) {
			mx2 = v;
		}
	}
	for(auto v: g[u]) if(v != par) {
		if(v != mx1) calc(v, u, max(val, b[mx1]));
		else calc(v, u, mx2 == -1 ? val : max(val, b[mx2]));
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
	for(int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		g[x].pb(y); g[y].pb(x);
	}
	dfs(1, 1);
	ans = -inf;
	calc(1, 1, -inf);
	if(ans != -inf) {
		printf("%I64d\n", ans);
	} else {
		puts("Impossible");
	}
	return 0;
}