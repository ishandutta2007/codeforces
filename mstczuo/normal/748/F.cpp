# include <vector>
# include <cstdio>
# include <algorithm>

using namespace std;

const int maxn = 200010;
vector<int> g[maxn];
int s[maxn], a[maxn];
int n, k;

void pre(int u,int par) {
	s[u] = a[u];
	for(auto v: g[u]) if(v != par) {
		pre(v, u); s[u] += s[v];
	}
}

int get_center(int u,int par) {
	for(auto v: g[u]) if(v != par) 
		if(s[v] > k) return get_center(v, u);
	return u;
}

vector<int> ans;
void dfs(int u,int par) {
	if(a[u]) ans.push_back(u);
	for(auto v: g[u]) if(v != par) dfs(v, u);
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < k * 2; ++i) {
		int x; scanf("%d", &x);
		a[x] = 1;
	}
	pre(1, 1);
	int ct = get_center(1, 1);
	printf("%d\n%d\n", 1, ct);
	dfs(1, 1);
	for(int i = 0; i < k; ++i) 
		printf("%d %d %d\n", ans[i], ans[i + k], ct);
	return 0;
}