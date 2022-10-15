#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
vector <int> E[N];
int ans = N;

int odd[N], even[N];

void dfs(int x, int fa = -1) {
	even[x] = 1;
	for (auto v : E[x]) if (v != fa) {
		dfs(v, x);
		odd[x] += even[v];
		even[x] += odd[v];
	}
}

void fuck(int x, int fa = -1, int ODD = 0, int EVEN = 0) {
	ans = min(ans, EVEN + even[x] - 1);
	for (auto v : E[x]) if (v != fa) {
		fuck(v, x, EVEN + even[x] - odd[v], ODD + odd[x] - even[v]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1);
	fuck(1);
	cout << ans << endl;
}