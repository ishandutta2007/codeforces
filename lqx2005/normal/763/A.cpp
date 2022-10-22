#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<i64, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10;
int n, c[N];
int rt = -1;
vector<int> g[N];

void dfs(int u, int fa) {
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		if(rt != -1) return;
		if(c[u] != c[v]) {
			rt = u;
			break;
		}
	}
	return;
	
}

int check(int u, int fa) {
	int res = 1;
	for(int v : g[u]) {
		if(v == fa) continue;
		if(c[v] != c[u]) return 0;
		res &= check(v, u);
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	dfs(1, 0);
	if(rt == -1) rt = 1;
	for(int v : g[rt]) {
		if(!check(v, rt)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n%d\n", rt);
	return 0;
}