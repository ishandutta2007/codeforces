#include <bits/stdc++.h> 
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))

using namespace std;
const int N = 2e5 + 10;
int n;
vector<int> g[N];
int cnt[2];

void dfs(int u, int fa, int dep) {
	cnt[dep & 1]++;
	for(int &v : g[u]) {
		if(v == fa) continue;
		dfs(v, u, dep + 1);
	}
	return;
}

int main() {
	cin >> n;
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0, 0);
	cout << min(cnt[0], cnt[1]) - 1 << endl;
	return 0;
}