# include <iostream>
# include <vector>
# include <cstring>

using namespace std;
const int maxn = 200000 + 10;

int n, k;
vector<int> g[maxn];
int a[maxn], s[maxn], t[maxn];
long long ans = 0;

void dfs(int u,int par) {
	for(int v: g[u]) if(v != par) {
		dfs(v, u);
		ans += s[v];
		s[u] += s[v];
	}
}

int center(int u,int par) {
	for(int v: g[u]) if(v != par) {
		if(s[v] > k) return center(v, u);
	}
	return u;
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < k * 2; ++i) cin >> a[i];
	for(int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < k * 2; ++i) s[a[i]] += 1;
	dfs(1, -1);
	int c = center(1, -1);
	ans = 0;
	memset(s, 0, sizeof(s));
	for(int i = 0; i < k * 2; ++i) s[a[i]] += 1;
	dfs(c, -1);
	cout << ans << endl;
}