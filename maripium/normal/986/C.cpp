#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 22;

int n, m;
int a[N];
bool have[N];
bool visit[N][2];
int ans;

void dfs(int u,int t) {
	if (visit[u][t]) {
		return;
	}
	visit[u][t] = true;
	if (t == 0) {
		if (have[u]) {
			dfs(u ^ ((1 << n) - 1), 1);
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (u & (1 << i)) {
				dfs(u ^ (1 << i), 1);
			}
		}
		dfs(u, 0);
	}
} 

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", a + i);
		have[a[i]] = true;
	}
	for (int i = 1; i <= m; ++i) {
		if (!visit[a[i]][0]) {
			++ans;
			dfs(a[i], 0);
		}
	}
	printf("%d\n", ans);
}