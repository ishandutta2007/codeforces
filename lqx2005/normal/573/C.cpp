#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10;
int n, fa[N], siz[N];
vector<int> g[N];
void dfs(int u, int fa) {
	::fa[u] = fa;
	siz[u] = (sz(g[u]) >= 3);
	for(int v : g[u]) if(v != fa) dfs(v, u), siz[u] += siz[v];
	return;
}
int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	for(int u = 1; u <= n; u++) {
		int cnt = 0;
		for(int v : g[u]) {
			if(sz(g[v]) > 3) {
				cnt++;
				continue;
			}
			if(v == fa[u]) {
				cnt += (siz[1] - siz[u] - (sz(g[v]) == 3)) > 0;
			} else {
				cnt += (siz[v] - (sz(g[v]) == 3)) > 0;
			}
		}
		if(cnt > 2) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
    return 0;
}