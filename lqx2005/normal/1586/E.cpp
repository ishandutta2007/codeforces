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
const int N = 3e5 + 10;
int n, m, cnt[N], vis[N];
vector<int> g[N], e[N];
int a[N], b[N];
int stk[N], top = 0;
void dfs(int u, int fa) {
	vis[u] = 1;
	for(int v : g[u]) {
		if(v == fa || vis[v]) continue;
		dfs(v, u);
		e[u].push_back(v), e[v].push_back(u);
	}
	return;
}

int DFS(int u, int fa, int t) {
	if(u == t) {
		stk[++top] = u;
		return 1;
	}
	int f = 0;
	for(int v : e[u]) if(v != fa) f |= DFS(v, u, t);
	if(f) stk[++top] = u;
	return f;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		scanf("%d%d", &a[i], &b[i]);
		cnt[a[i]]++, cnt[b[i]]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) if(cnt[i] & 1) ans++;
	if(ans == 0) {
		puts("YES");
		for(int i = 1; i <= q; i++) {
			top = 0;
			DFS(a[i], 0, b[i]);
			printf("%d\n", top);
			for(int j = top; j >= 1; j--) printf("%d ", stk[j]);
			printf("\n");
		}
	} else {
		printf("NO\n%d\n", ans / 2);
	}
    return 0;
}