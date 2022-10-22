#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10;
int n;
int l[N], r[N];
vector<int> g[N];
LL dp[N][2];

void dfs(int u, int fa) {
	dp[u][0] = dp[u][1] = 0;
	for(int &v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		dp[u][0] += max(abs(l[u] - l[v]) + dp[v][0], abs(l[u] - r[v]) + dp[v][1]);
		dp[u][1] += max(abs(r[u] - l[v]) + dp[v][0], abs(r[u] - r[v]) + dp[v][1]);
	}
	return;
}

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	printf("%lld\n", max(dp[1][0], dp[1][1]));
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; work());
	return 0;
}